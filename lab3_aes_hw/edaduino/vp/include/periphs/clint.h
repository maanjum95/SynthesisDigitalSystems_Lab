/**
 * @Author: J.Geier
 * @Date:   2020-04-13T13:19:42+01:00
 * @Filename: clint.h
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


#ifndef __CLINT_H__
#define __CLINT_H__

#include "etissvp/base-tlmcomp/peripheral_base_minres.h"
#include "etissvp/base-tlmcomp/periph.h"
#include "etissvp/generic-tlmcomp/soc.h"
#include "clint_regs.h"

/////////////////////////////////////////////////////////////////////////////
// \class Clint
// \brief RISC-V Core-local Interrupt Controller (CLINT). A RISC-V privilege spec. 1.11 compatible CLINT (Adapted from Pulp Ariane CLINT: https://github.com/pulp-platform/ariane/tree/master/src/clint)
/////////////////////////////////////////////////////////////////////////////
class Clint : public etissvp::PeripheralBaseMinres<ClintRegs, etissvp::SoC> {
  SC_HAS_PROCESS(Clint);

 public:
  //std::array<sc_core::sc_in<bool>, 32> irq_i_{};

  Clint(sc_core::sc_module_name, etissvp::PerParams&&,
            etissvp::SoC* owner = nullptr, const uint64_t rtcPeriod_ps = 30517578); //~32.768kHz
  
  //void b_transport(tlm::tlm_generic_payload&, sc_core::sc_time&) override;
 
protected:  
  
  etissvp::bitfield<uint32_t>& msip_{regs->getBitfield("MSIP", "MSIP", "clint.MSIP")};
  etissvp::bitfield<uint32_t>& mtimecmplo_{regs->getBitfield("MTIMECMPLO", "MTIMECMPLO", "clint.MTIMECMPLO")};
  etissvp::bitfield<uint32_t>& mtimecmphi_{regs->getBitfield("MTIMECMPHI", "MTIMECMPHI", "clint.MTIMECMPHI")};
  etissvp::bitfield<uint32_t>& mtimelo_{regs->getBitfield("MTIMELO", "MTIMELO", "clint.MTIMELO")};
  etissvp::bitfield<uint32_t>& mtimehi_{regs->getBitfield("MTIMEHI", "MTIMEHI", "clint.MTIMEHI")};
  
  const uint64_t rtcPeriod_ps;

 private:

  void reset();
  void clkProcess();

  bool set_interrupt(etissvp::bitfield<uint32_t>& timer_, etissvp::bitfield<uint32_t>& cmp_, 
                              uint8_t offset);
};

#endif //__CLINT_H__
