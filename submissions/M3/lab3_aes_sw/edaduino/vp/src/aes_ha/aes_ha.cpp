/**
 * @Author: J.Geier
 * @Date:   2020-04-24T13:19:42+01:00
 * @Filename: aes_ha.cpp
 * @Last modified by:   
 * @Last modified time: 
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

#include "aes_ha/aes_ha.h"

#ifdef VRTL_CORE
#include "Vaes16_bidir.h"
#endif /* VRTL_CORE */  

#define ID_CLINT "AES_HA"

Aes_Ha::Aes_Ha(sc_core::sc_module_name name, etissvp::PerParams&& params,
             etissvp::SoC* owner,  const uint64_t subsystem_clkperiod_ps )
    : PeripheralBaseMinres(name, std::move(params), owner),
	  subsystem_clkperiod_ps_(subsystem_clkperiod_ps), cur_(FSM_STATES::IDLE){

    for(size_t i = 0; i< ios_.size(); ++i){
        std::string _pf = std::to_string(i*4 + 3) + std::string("_") + std::to_string(i*4);
        std::string regname = std::string("BYTES_") + _pf;
        std::string name = std::string("IO_") + _pf;
        std::string urid = std::string("aes_ha.io") + _pf;
        ios_[i]  = &(regs->getBitfield(regname, name, urid));
    }
    for(size_t i = 0; i< key_.size(); ++i){
        std::string _pf = std::to_string(i*4 + 3) + std::string("_") + std::to_string(i*4);
        std::string regname = std::string("KEY_") + _pf;
        std::string name = std::string("KEY_") + _pf;
        std::string urid = std::string("aes_ha.key") + _pf;
        key_[i]  = &(regs->getBitfield(regname, name, urid));
    }
    for(size_t i = 0; i< iv_.size(); ++i){
        std::string _pf = std::to_string(i*4 + 3) + std::string("_") + std::to_string(i*4);
        std::string regname = std::string("IV_") + _pf;
        std::string name = std::string("IV_") + _pf;
        std::string urid = std::string("aes_ha.iv") + _pf;
        iv_[i]  = &(regs->getBitfield(regname, name, urid));
    }
#ifdef VRTL_CORE    
    hlscore_ = new Vaes16_bidir("aes16top");
    hlscore_->inout_0_i(in_[0]);
    hlscore_->inout_1_i(in_[1]);
    hlscore_->inout_2_i(in_[2]);
    hlscore_->inout_3_i(in_[3]);
    hlscore_->inout_0_o(out_[0]);
    hlscore_->inout_1_o(out_[1]);
    hlscore_->inout_2_o(out_[2]);
    hlscore_->inout_3_o(out_[3]);
    hlscore_->key_0(k_[0]);
    hlscore_->key_1(k_[1]);
    hlscore_->key_2(k_[2]);
    hlscore_->key_3(k_[3]);
    hlscore_->inout_0_o_ap_vld(v_[0]);
    hlscore_->inout_1_o_ap_vld(v_[1]);
    hlscore_->inout_2_o_ap_vld(v_[2]);
    hlscore_->inout_3_o_ap_vld(v_[3]);    
    
    hlscore_->ap_start(start_);
    hlscore_->ap_clk(clk_);
    hlscore_->ap_rst(rst_);
    hlscore_->ap_idle(idle_);
    hlscore_->ap_done(done_);  
    hlscore_->ap_ready(rdy_);    
    
    hlscore_->iv_0_i(iv_i_[0]);
    hlscore_->iv_1_i(iv_i_[1]);
    hlscore_->iv_2_i(iv_i_[2]);
    hlscore_->iv_3_i(iv_i_[3]);
    hlscore_->iv_0_o(iv_o_[0]);
    hlscore_->iv_1_o(iv_o_[1]);
    hlscore_->iv_2_o(iv_o_[2]);
    hlscore_->iv_3_o(iv_o_[3]);
    hlscore_->iv_0_o_ap_vld(iv_v_[0]);
    hlscore_->iv_1_o_ap_vld(iv_v_[1]);
    hlscore_->iv_2_o_ap_vld(iv_v_[2]);
    hlscore_->iv_3_o_ap_vld(iv_v_[3]);
    
#endif /* VRTL_CORE */   
    control_ = 0;
    status_ = 0;
    pc_ = 0;
    
    control_.setWriteCallback([this](auto&&, uint32_t& valueToWrite) {
        control_ = valueToWrite;
        SC_REPORT_INFO(ID_CLINT, "New AES HA control");
    });

    status_.setReadCallback([this](auto&&) {
        return(status_.get());
    });
    
    pc_.setReadCallback([this](auto&&) {
        return(pc_.get());
    });

    pc_cpu_lo_.setReadCallback([this](auto&&) {
        static const auto cpu_cycle_time = etiss::cfg().get<unsigned int>("Arch::cpuCycleTime_ps", 0);
        uint64_t x_ps = sc_core::sc_time_stamp().value()/cpu_cycle_time;
        pc_cpu_lo_ = x_ps & 0xFFFFFFFF;
        return(pc_cpu_lo_.get());
    });
    pc_cpu_hi_.setReadCallback([this](auto&&) {
        static const auto cpu_cycle_time = etiss::cfg().get<unsigned int>("Arch::cpuCycleTime_ps", 0);
        uint64_t x_ps = sc_core::sc_time_stamp().value()/cpu_cycle_time;
        pc_cpu_hi_ = (x_ps >> 32) & 0xFFFFFFFF;
        return(pc_cpu_hi_.get());
    }); 
    for(size_t i = 0; i< ios_.size(); ++i){
        ios_[i]->setWriteCallback([this, i](auto&&, uint32_t& valueToWrite) {
            *(ios_[i]) = valueToWrite;
            #ifdef VRTL_CORE
            //switch(i){
            //    case 0: in_[0] = valueToWrite; break;
            //    case 1: in_[1] = valueToWrite; break;
            //    case 2: in_[2] = valueToWrite; break;
            //    case 3: in_[3] = valueToWrite; break;
            //    default: break;
            //}
            #endif /* VRTL_CORE */
            SC_REPORT_INFO(ID_CLINT, "New AES HA Input");
        });
        ios_[i]->setReadCallback([this, i](auto&&) {
        	SC_REPORT_INFO(ID_CLINT, "New AES HA Output read");
        	return(ios_[i]->get());
        });    
    }    
    for(size_t i = 0; i< key_.size(); ++i){
    	key_[i]->setWriteCallback([this, i](auto&&, uint32_t& valueToWrite) {
            *(key_[i]) = valueToWrite;
            #ifdef VRTL_CORE
            //switch(i){
            //    case 0: k_[0] = valueToWrite; break;
            //    case 1: k_[1] = valueToWrite; break;
            //    case 2: k_[2] = valueToWrite; break;
            //    case 3: k_[3] = valueToWrite; break;
            //    default: break;
            //}
            #endif /* VRTL_CORE */
            SC_REPORT_INFO(ID_CLINT, "New AES KEY Input");
        });
    	key_[i]->setReadCallback([this, i](auto&&) {
        	SC_REPORT_INFO(ID_CLINT, "New AES HA KEY read");
        	return(key_[i]->get());
        });
    }
    for(size_t i = 0; i< iv_.size(); ++i){
    	iv_[i]->setWriteCallback([this, i](auto&&, uint32_t& valueToWrite) {
            *(iv_[i]) = valueToWrite;
            #ifdef VRTL_CORE
            //switch(i){
            //    case 0: iv_i_[0] = valueToWrite; break;
            //    case 1: iv_i_[1] = valueToWrite; break;
            //    case 2: iv_i_[2] = valueToWrite; break;
            //    case 3: iv_i_[3] = valueToWrite; break;
            //    default: break;
            //}
            #endif /* VRTL_CORE */
            SC_REPORT_INFO(ID_CLINT, "New AES IV Input");
        });
    	iv_[i]->setReadCallback([this, i](auto&&) {
        	SC_REPORT_INFO(ID_CLINT, "New AES HA IV read");
        	return(iv_[i]->get());
        });
    }
    for (auto& bf : regs->bitfields) {
        bf = 0;
    }
    
    SC_THREAD(clkProcess);
}

void Aes_Ha::reset() {
    sc_core::sc_time tinycylce{static_cast<double>(1),
                                   sc_core::SC_PS};
#ifdef VRTL_CORE    
    rst_ = 1;
    clk_ = 0;
    wait(tinycylce);
    clk_ = 1;
    wait(tinycylce);
    clk_ = 0;
    wait(tinycylce);
    rst_ = 0;
#endif /* VRTL_CORE */    
}

void Aes_Ha::clkProcess() {
  static const auto cpu_cycle_time = etiss::cfg().get<unsigned int>("Arch::cpuCycleTime_ps", 0);
  static const sc_core::sc_time base_clk_period{static_cast<double>(cpu_cycle_time), sc_core::SC_PS};
  uint64_t counter_ps = 0;
  static const uint64_t _OVERFLOW_ = 0x0FFFFFFFF;
  bool hi = false;
  reset();
  
  while (true) {
    
	wait(base_clk_period);
    

	counter_ps += cpu_cycle_time;
	if(counter_ps >= subsystem_clkperiod_ps_/2){
#ifdef VRTL_CORE
    if(!hi){
           clk_ = 0;
        }else{
            clk_ = 1;
    		/* We need a FSM here to reliably control the RTL simulator AND emualte the register interface:
    		 * Input: 	CONTROL
    		 * Output: 	STATUS
    		 * Actions:	Manipulation of VRTL core
    		 *
    		 * How? Either simple clocked one w/ event driven (write to control) input.
    		 * State pattern template so we can reuse in other projects/peripherals?
             */
    switch (cur_){
            case FSM_STATES::IDLE:
                /* next state logic */
                if((control_.get() & (uint32_t)FSM_START)){
                    cur_ = FSM_STATES::START;
                }
                /* actions */
                break;
            case FSM_STATES::START:
                /* next state logic */
                cur_ = FSM_STATES::PROC;
                /* actions */
                for (size_t i = 0; i< 4; ++i){
                    in_[i] = *(ios_[i]);
                    k_[i] = *(key_[i]);
                    iv_i_[i] =*(iv_[i]);
                }
                //control_ = control_.get() & ~(uint16_t(0x1));
                start_ = 1;
                pc_ = 0;
                break;
            case FSM_STATES::PROC:
                /* next state logic */
                if(done_){
                    cur_ = FSM_STATES::DONE;
                } else if(idle_){
                    cur_ = FSM_STATES::IDLE;
                }
                /* actions */
                control_ = 0;
                for (size_t i = 0; i< 4; ++i){
                    if(v_[i])
                        *(ios_[i]) = out_[i];
                    if(iv_v_[i])
                        *(iv_[i]) = iv_o_[i];
                }
                start_ = 0;
                pc_ = pc_ +1;
                break;
            case FSM_STATES::DONE:
                /* next state logic */
                cur_ = FSM_STATES::IDLE;
                /* actions */
                control_ = control_.get() | (uint16_t)FSM_IP; //(*irq_out_)[0] = 1;
            default:break;
		}
        status_ = cur_;   
        if(control_.get() & (uint32_t) FSM_IP){
            (*irq_out_)[0] = 1;
        }else{
            (*irq_out_)[0] = 0;
        }
    }         
        
#endif /* VRTL_CORE */   
        hi = !hi;
        counter_ps = 0;
  }
}
}
