/**
 * @Author: J.Geier
 * @Date:   2020-04-24T13:19:42+01:00
 * @Filename: aes_ha_regs.h
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


#ifndef INCLUDE_PERIPHS_AES_HA_REGS_H_
#define INCLUDE_PERIPHS_AES_HA_REGS_H_

#include "etissvp/base-tlmcomp/peripheral_register_base.h"

class Aes_HaRegs : public etissvp::peripheral_register_base<Aes_HaRegs> {
    public:
        
        std::array<etissvp::bitfield_register<uint32_t>, 16> registers{{
            {"CS",          0x0000},        // Control register
			{"PC",			0x0004},		// Performance counter register
			{"PC_CPU_LO",	0x0008},	    // Performance counter register cpu cycles LO-Word
			{"PC_CPU_HI",	0x000C},	    // Performance counter register cpu cycles LO-Word
            {"BYTES_3_0",   0x0100},       	// Input/Output register [3:0]
            {"BYTES_7_4",  	(0x0100 + 4)},  // Input/Output register [7:3]
            {"BYTES_11_8",  0x0100 + 8},    // Input/Output register [11:8]
            {"BYTES_15_12",	(0x0100 + 12)}, // Input/Output register [15:12]
            {"KEY_3_0",   	0x0200},       	// Key register [3:0]
            {"KEY_7_4",  	(0x0200 + 4)},  // Key register [7:3]
            {"KEY_11_8",  	0x0200 + 8},    // Key register [11:8]
            {"KEY_15_12",	(0x0200 + 12)},  // Key register [15:12]
            {"IV_3_0",   	0x0300},       	// IV register [3:0]
            {"IV_7_4",  	(0x0300 + 4)},  // IV register [7:3]
            {"IV_11_8",  	0x0300 + 8},    // IV register [11:8]
            {"IV_15_12",	(0x0300 + 12)}  // IV register [15:12]
        }};
        
        std::array<etissvp::bitfield<uint32_t>, 17> bitfields{{
            {getRegister("CS"),"CONTROL", 0, 16,  "aes_ha.control"},
            {getRegister("CS"),"STATUS",  16, 16, "aes_ha.status"},
			{getRegister("PC"),"PC",      0, 32, "aes_ha.pc"},
			{getRegister("PC_CPU_LO"),"PC_CPU_LO",      0, 32, "aes_ha.pc_cpu_lo"},
			{getRegister("PC_CPU_HI"),"PC_CPU_HI",      0, 32, "aes_ha.pc_cpu_hi"},
            {getRegister("BYTES_3_0"),  "IO_3_0",  0, 32, "aes_ha.io3_0"},
            {getRegister("BYTES_7_4"),  "IO_7_4",  0, 32, "aes_ha.io7_4"},
            {getRegister("BYTES_11_8"),  "IO_11_8",  0, 32, "aes_ha.io11_8"},
            {getRegister("BYTES_15_12"),  "IO_15_12",  0, 32, "aes_ha.io15_12"},
            {getRegister("KEY_3_0"),  "KEY_3_0",  0, 32, "aes_ha.key3_0"},
            {getRegister("KEY_7_4"),  "KEY_7_4",  0, 32, "aes_ha.key7_4"},
            {getRegister("KEY_11_8"),  "KEY_11_8",  0, 32, "aes_ha.key11_8"},
            {getRegister("KEY_15_12"),  "KEY_15_12",  0, 32, "aes_ha.key15_12"},
            {getRegister("IV_3_0"),  "IV_3_0",  0, 32, "aes_ha.iv3_0"},
            {getRegister("IV_7_4"),  "IV_7_4",  0, 32, "aes_ha.iv7_4"},
            {getRegister("IV_11_8"),  "IV_11_8",  0, 32, "aes_ha.iv11_8"},
            {getRegister("IV_15_12"),  "IV_15_12",  0, 32, "aes_ha.iv15_12"}
        }};
        
        Aes_HaRegs(sc_core::sc_module_name name) : peripheral_register_base<Aes_HaRegs>{name} {};
};



#endif /* INCLUDE_PERIPHS_AES_HA_REGS_H_ */
