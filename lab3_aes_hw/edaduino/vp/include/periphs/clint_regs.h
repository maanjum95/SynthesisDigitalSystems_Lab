/**
 * @Author: J.Geier
 * @Date:   2020-04-21T13:19:42+01:00
 * @Filename: clint_regs.h
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


#ifndef INCLUDE_PERIPHS_CLINT_REGS_H_
#define INCLUDE_PERIPHS_CLINT_REGS_H_

#include "etissvp/base-tlmcomp/peripheral_register_base.h"

class ClintRegs : public etissvp::peripheral_register_base<ClintRegs> {
    public:
        std::array<etissvp::bitfield_register<uint32_t>, 5> registers{{
            {"MSIP",        0x0000},         //Interprocess Interrupt Pending
            {"MTIMECMPLO",  0x4000},           //Timer compare register low word  ( 31:0 )
            {"MTIMECMPHI", 	(0x4000 + 4)},         //Timer compare register high word ( 63:32 )
            {"MTIMELO",     0xBFF8},         //Timer (count) register low word  ( 31:0 )
            {"MTIMEHI",     (0xBFF8 +4)}          //Timer (count) register high word ( 63:32 )
        }};
        std::array<etissvp::bitfield<uint32_t>, 5> bitfields{{
            {getRegister("MSIP"),"MSIP", 0, 1,"clint.MSIP"},
            {getRegister("MTIMECMPLO"), "MTIMECMPLO", 0, 32, "clint.MTIMECMPLO"},
            {getRegister("MTIMECMPHI"), "MTIMECMPHI", 0, 32, "clint.MTIMECMPHI"},
            {getRegister("MTIMELO"),    "MTIMELO", 0, 32, "clint.MTIMELO"},
            {getRegister("MTIMEHI"),    "MTIMEHI", 0, 32, "clint.MTIMEHI"}
        }};
        ClintRegs(sc_core::sc_module_name name) : peripheral_register_base<ClintRegs>{name} {};
};



#endif /* INCLUDE_PERIPHS_CLINT_REGS_H_ */
