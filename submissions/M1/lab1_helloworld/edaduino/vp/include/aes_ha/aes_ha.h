/**
 * @Author: J.Geier
 * @Date:   2020-04-24T13:19:42+01:00
 * @Filename: aes_ha.h
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


#ifndef __AES_HA_H__
#define __AES_HA_H__

#include "etissvp/base-tlmcomp/peripheral_base_minres.h"
#include "etissvp/base-tlmcomp/periph.h"
#include "etissvp/generic-tlmcomp/soc.h"
#include "aes_ha_regs.h"


// Forward declaration
class Vaes16_bidir;

/////////////////////////////////////////////////////////////////////////////
// \class Aes_Ha
// \brief ETISS-VP conform peripheral module (top) for HLS'd aes algorithm (Synthesis of Digital System Lab)
/////////////////////////////////////////////////////////////////////////////
class Aes_Ha : public etissvp::PeripheralBaseMinres<Aes_HaRegs, etissvp::SoC> {
  SC_HAS_PROCESS(Aes_Ha);

  typedef enum FSM_STATES{
	  IDLE = 0,
	  START = 1,
	  PROC = 2,
	  DONE = 4
  }fsm_state_t;
  fsm_state_t cur_;
 public:

  Aes_Ha(sc_core::sc_module_name, etissvp::PerParams&&,
            etissvp::SoC* owner = nullptr, const uint64_t subsystem_clkperiod_ps = 10); //~100 MHz
   
protected:  
  
  etissvp::bitfield<uint32_t>& control_{regs->getBitfield("CS", "CONTROL", "aes_ha.control")};
  etissvp::bitfield<uint32_t>& status_ {regs->getBitfield("CS", "STATUS", "aes_ha.status")};
  etissvp::bitfield<uint32_t>& pc_ {regs->getBitfield("PC", "PC", "aes_ha.pc")};

  std::array<etissvp::bitfield<uint32_t>*, 4> ios_{};
  std::array<etissvp::bitfield<uint32_t>*, 4> key_{};

  Vaes16_bidir* hlscore_;
  
  const uint64_t subsystem_clkperiod_ps_;

 private:

  void reset();
  void clkProcess();
  
  std::array<sc_core::sc_signal<uint32_t>, 4> in_{};
  std::array<sc_core::sc_signal<uint32_t>, 4> out_{};
  std::array<sc_core::sc_signal<uint32_t>, 4> k_{};
  std::array<sc_core::sc_signal<bool>, 4> v_{};
  sc_core::sc_signal<bool> start_;
  sc_core::sc_signal<bool> clk_;
  sc_core::sc_signal<bool> rst_;
  sc_core::sc_signal<bool> cryptdir_;
  sc_core::sc_signal<bool> rdy_;
  sc_core::sc_signal<bool> idle_;
  sc_core::sc_signal<bool> done_;
  
  bool set_interrupt(etissvp::bitfield<uint32_t>& timer_, etissvp::bitfield<uint32_t>& cmp_, 
                              uint8_t offset);
};

#endif //__AES_HA_H__
