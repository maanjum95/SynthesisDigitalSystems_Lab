/**
 * @Author: geier
 * @Date:   2020-04-23
 * @Email:  johannes.geier@tum.de
 * @Filename: edaduino_soc.h
 * @Copyright: Copyright (c) 2020
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
#ifndef __EDADUINO_SOC_H__
#define __EDADUINO_SOC_H__

#include "etissvp/generic-tlmcomp/soc.h"

class EdaDuinoSoCParams final {
 public:

	etissvp::CPUParams cpu_params_{};

	etissvp::MemParams rom_params_{};
	etissvp::MemParams dram_params_{};

	etissvp::PerParams uart_params_{};
    etissvp::PerParams timer_params_{};

    etissvp::PerParams clint_params_{};
    
    etissvp::PerParams aes_ha_params_{};

};

class EdaDuinoSoC final : public etissvp::SoC {
 public:
  EdaDuinoSoC(sc_core::sc_module_name name,
             EdaDuinoSoCParams&& edaduino_soc_params,
             etissvp::SoCParams&& soc_params);

  void setup() override;

  void addCPU( std::unique_ptr<etissvp::CPU> cpu, std::string bus_name);

  protected:
  EdaDuinoSoCParams edaduino_soc_params_{};
  
  // IRQ wires. 16 onwards forwarded to custom riscv irqs. 15 downwards are risc-v specific irqs (unused in this vp)
  std::array<sc_core::sc_signal<bool>, 32> irq_srcs_n_{};
};

#endif /*__EDADUINO_SOC_H__*/
