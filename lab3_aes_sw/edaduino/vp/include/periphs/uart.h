/**
 * @Author: S.Klotz
 * @Date:   2019-03-18T13:08:08+01:00
 * @Filename: uart.h
 * @Last modified by:   sharif
 * @Last modified time: 2019-03-18T13:09:19+01:00
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

#ifndef __UARTIF_H__
#define __UARTIF_H__

#include "etissvp/base-tlmcomp/periph.h"
#include "etissvp/generic-tlmcomp/soc.h"

#include <queue>

// Uart Structure is running from 0x00 to 0x07 - global adresses use 0x00 ..
// 0x04 for eversy reg.
typedef struct {
  uint32_t RBR; /*!< (@ 0x000 )Reciever Buffer Register (DLAB=0)            */
  uint32_t DLL; /*!< (@ 0x000 )Divisor Latch (LS)  (DLAB=1)                 */
  uint32_t THR; /*!< (@ 0x000 )Transmitter Holding Register (DLAB=0)        */

  uint32_t DLM; /*!< (@ 0x004 )Divisor Latch (MS)           (DLAB=1)         */
  uint32_t IER; /*!< (@ 0x004 )Interrupt Enable Register    (DLAB=0)        */

  uint32_t IIR; /*!< (@ 0x008 )Interrupt Identification Register            */
  uint32_t FCR; /*!< (@ 0x008 )FIFO Control Register                        */

  uint32_t LCR; /*!< (@ 0x00C )Line Control Register                        */
  uint32_t MCR; /*!< (@ 0x010 )Modem Control Register                       */
  uint32_t LSR; /*!< (@ 0x014 )Line Status Register                         */
  uint32_t MSR; /*!< (@ 0x018 )Modem Status Register                        */
  uint32_t SCR; /*!< (@ 0x01C )Scratch Register                             */

} UART_REG;

class UART final : public etissvp::PeripheralBaseEda<etissvp::SoC> {
  SC_HAS_PROCESS(UART);

 public:
  std::unique_ptr<tlm_utils::simple_initiator_socket<UART>> sock_i_{nullptr};
  std::unique_ptr<tlm_utils::simple_target_socket<UART>> sock_t_ext_{nullptr};

  UART(sc_core::sc_module_name, etissvp::PerParams&&,
       etissvp::SoC* owner = nullptr);
  void b_transport(tlm::tlm_generic_payload&, sc_core::sc_time&) override;
  void b_transport_ext(tlm::tlm_generic_payload&, sc_core::sc_time&);

 private:
  UART_REG regs_{};
  AccessType permission_[12];

  typedef enum INTERRUPT_EVENTS{
    S_RDATA_AVAILABLE = 1,
	  S_TBR_EMPTY = 2,
	  S_RLSR_CHANGE = 4,
    R_RDATA_AVAILABLE = 0x10,
    R_TBR_EMPTY = 0x20,
    R_RLSR_CHANGE = 0x40,
  } interrupt_events_t;
  sc_core::sc_event interrupt_event_;
  std::queue<interrupt_events_t> interrupt_event_q_;

  bool send_interrupt_{false};

  void reset() override;
  void sendData(uint8_t);
  void getData(uint8_t&);
  void sendInterrupt();
};

#endif
