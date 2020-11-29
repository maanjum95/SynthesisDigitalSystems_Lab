/**
 * @Author: S.Klotz
 * @Date:   2019-03-18T13:05:43+01:00
 * @Filename: uart.cpp
 * @Last modified by:   sharif
 * @Last modified time: 2019-03-18T13:10:45+01:00
 * @Copyright: Copyright (c) 2019
  Institute for Electronic Design Automation, TU Munich

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.

 */

#include "periphs/uart.h"


#define ID_UART "uart"

UART::UART(sc_core::sc_module_name name, etissvp::PerParams&& params,
           etissvp::SoC* owner)
    : etissvp::PeripheralBaseEda<etissvp::SoC>{name, std::move(params), owner} {
  reset();
  register_ptr_ = reinterpret_cast<uint8_t*>(&regs_);
  access_ptr_ = permission_;

  sock_i_ = std::make_unique<tlm_utils::simple_initiator_socket<UART>>(
      "initiator_socket");
  sock_t_ext_ = std::make_unique<tlm_utils::simple_target_socket<UART>>(
      "target_socket_external");
  sock_t_ext_->register_b_transport(this, &UART::b_transport_ext);

  SC_THREAD(sendInterrupt);
}

void UART::b_transport(tlm::tlm_generic_payload& gp, sc_core::sc_time& delay) {
  auto addr = gp.get_address();
  auto ptr = gp.get_data_ptr();
  auto cmd = gp.get_command();
  auto len = gp.get_data_length();

  //std::cout << addr << std::endl;

  if(addr < 0x4){
    if (regs_.LCR >= 128) {
      gp.set_address(addr + 4);
      tlm_access_register(gp);
    } else {
      if (cmd == tlm::TLM_READ_COMMAND) {
        tlm_access_register(gp);
        if(addr == 0) {//== 1)
          getData(*ptr);
          interrupt_event_q_.push(R_RDATA_AVAILABLE);
          interrupt_event_.notify();
        }
      } else {
        gp.set_address(addr + 8);
        tlm_access_register(gp);
        if(addr == 0){
          sendData(*ptr);
          interrupt_event_q_.push(R_TBR_EMPTY);
          interrupt_event_.notify();
        }
      }
    }
  } else if (addr < 0x8) {
    if (regs_.LCR >= 128) {
      gp.set_address(addr + 8);
      tlm_access_register(gp);
    } else {
      gp.set_address(addr + 12);
      tlm_access_register(gp);
    }
  } else if (addr < 0xc) {
    if (cmd == tlm::TLM_READ_COMMAND) {
      gp.set_address(addr + 12);
      tlm_access_register(gp);
      interrupt_event_q_.push(R_TBR_EMPTY);
      interrupt_event_.notify();
    } else {
      gp.set_address(addr + 16);
      tlm_access_register(gp);
    }
  } else if (addr >= 0xc && addr <= 0x1c) {
    gp.set_address(addr + 16);
    tlm_access_register(gp);
    if((addr -16) == 0xc)
      interrupt_event_q_.push(R_RLSR_CHANGE);
      interrupt_event_.notify();
  } else {
    SC_REPORT_FATAL(ID_UART, "out of range addr issued in UART::b_transport");
  }

}

void UART::b_transport_ext(tlm::tlm_generic_payload& gp,
                           sc_core::sc_time& delay) {
  gp.set_response_status(tlm::TLM_OK_RESPONSE);
  auto data = *reinterpret_cast<uint32_t*>(gp.get_data_ptr());
  // regs_.RBR = data;
  auto in_LSR = regs_.LSR;

  regs_.LSR = (regs_.LSR & ~(0x01)) | (data & 0x1);
  if(regs_.LSR != in_LSR){
    if(regs_.IER & 0x4) {
      interrupt_event_q_.push(S_RLSR_CHANGE);
      interrupt_event_.notify();
    }
  }
  if( (regs_.IER & 0x1) && (regs_.LSR & 0x1)){
    interrupt_event_q_.push(S_RDATA_AVAILABLE);
    interrupt_event_.notify();
  }
  //std::cout << "LSR: " << std::hex << regs_.LSR << std::endl;
}

void UART::reset() {
  regs_.RBR = 0;
  regs_.DLL = 0;
  regs_.THR = 0;
  regs_.DLM = 0;
  regs_.IER = 0;
  regs_.IIR = 1;
  regs_.FCR = 0;
  regs_.LCR = 0;
  regs_.MCR = 0;
  regs_.LSR = 0x60;
  regs_.MSR = 0;
  regs_.SCR = 0;

  permission_[0] = AccessType::READ;
  permission_[1] = AccessType::READ_WRITE;
  permission_[2] = AccessType::WRITE;
  permission_[3] = AccessType::READ_WRITE;
  permission_[4] = AccessType::READ_WRITE;
  permission_[5] = AccessType::READ;
  permission_[6] = AccessType::WRITE;
  permission_[7] = AccessType::READ_WRITE;
  permission_[8] = AccessType::READ_WRITE;
  permission_[9] = AccessType::READ_WRITE;
  permission_[10] = AccessType::READ_WRITE;
  permission_[11] = AccessType::READ_WRITE;
}

void UART::sendData(uint8_t data) {
  tlm::tlm_generic_payload gp{};
  gp.set_command(tlm::TLM_WRITE_COMMAND);
  gp.set_data_ptr(static_cast<unsigned char*>(&data));
  gp.set_data_length(1);
  gp.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
  sc_core::sc_time delay{sc_core::SC_ZERO_TIME};

  (*sock_i_)->b_transport(gp, delay);

  if (gp.get_response_status() != tlm::TLM_OK_RESPONSE) {
    SC_REPORT_FATAL(ID_UART, "data send failed in UART::sendData()");
  }

  if(regs_.IER & 0x2) {
    interrupt_event_q_.push(S_TBR_EMPTY);
    interrupt_event_.notify();
  }
}
void UART::getData(uint8_t& data) {

  tlm::tlm_generic_payload gp{};
  sc_core::sc_time delay{sc_core::SC_ZERO_TIME};
  gp.set_command(tlm::TLM_READ_COMMAND);
  gp.set_data_ptr(static_cast<unsigned char*>(&data));
  gp.set_data_length(1);
  gp.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

  (*sock_i_)->b_transport(gp, delay);

  if (gp.get_response_status() != tlm::TLM_OK_RESPONSE) {
    SC_REPORT_FATAL(ID_UART, "data receive failed in UART::getData()");
  }

  data = *reinterpret_cast<uint8_t*>(gp.get_data_ptr());
  regs_.RBR = data;

  //regs_.LSR = 0x61;
  //send_interrupt_ = true;

}

void UART::sendInterrupt() {
  auto clk_period = etiss::cfg().get<int>("Arch::cpuCycleTime_ps", 0);

  (*irq_out_)[0] = 0;
  while (1) {
    wait(interrupt_event_);
    int x = 0;
    while(!interrupt_event_q_.empty()){
      x |=  int(interrupt_event_q_.front()); // get all events
      interrupt_event_q_.pop();
    }
    if(x & 0xF ) // set interrupt
    {
      if(x & S_RLSR_CHANGE){
        regs_.IIR = 0x3 << (1);
      } else if(x & S_RDATA_AVAILABLE){
        regs_.IIR = regs_.IIR = 0x1 << (2);
      } else if(x & S_TBR_EMPTY){
        regs_.IIR = regs_.IIR = 0x1 << (1);
      }
    }
    else{ // reset interrupt
      if(x & R_RLSR_CHANGE)
        regs_.IIR &= ~(0x3 << (1));
      if(x & R_RDATA_AVAILABLE)
        regs_.IIR &= ~(0x1 << (2));
      if(x & R_TBR_EMPTY)
        regs_.IIR &= ~(0x1 << (1));
    }

    if(regs_.IIR & (~0x1)) {
      regs_.IIR &= (~0x1); // IP
      (*irq_out_)[0] = 1;
      //wait(10*clk_period, sc_core::SC_PS);
      //(*irq_out_)[0] = 0;
    }else {
      (*irq_out_)[0] = 0;
      regs_.IIR |= 1; // no IP
    }
  }
}
