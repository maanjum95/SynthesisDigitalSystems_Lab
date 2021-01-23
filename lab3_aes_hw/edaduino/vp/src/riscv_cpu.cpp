/**
 * @Author: sharif
 * @Date:   2019-03-09T15:36:21+01:00
 * @Email:  uzair.sharif@tum.de
 * @Project: etissvp-lib
 * @Filename: riscv_cpu.cpp
 * @Last modified by:   sharif
 * @Last modified time: 2019-03-10T02:10:34+01:00
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

#include "etissvp/riscv-comp/riscv_cpu.h"

#define ID_ETISSVP_RISCVCPU "etissvp: RISCVCPU"

etissvp::RISCVCPU::RISCVCPU(sc_core::sc_module_name name,
                            RISCVCPUParams&& riscv_cpu_params,
                            CPUParams&& cpu_params)
    : CPU(name, std::move(cpu_params)),
      riscv_cpu_params_{std::move(riscv_cpu_params)} {
  etiss::cfg().set<std::string>("CPUArch", "RISCV");
}

void etissvp::RISCVCPU::setup() {
  CPU::setup();

  etiss_core_->setTimer(false);
}

etissvp::RISCVCPUFactory::RISCVCPUFactory(etiss::Initializer* etiss_init)
    : etissvp::CPUFactory{etiss_init} {}

void etissvp::RISCVCPUFactory::initParams() {
  CPUFactory::initParams();

  cpu_params_.num_irqs_ = 32;
}

void etissvp::RISCVCPUFactory::genSTD(sc_core::sc_module_name name) {
  genHelper<RISCVCPU, RISCVCPUParams, CPUParams>(
      name, std::move(riscv_cpu_params_), std::move(cpu_params_));
}

void etissvp::RISCVCPUFactory::genREF(sc_core::sc_module_name name) {
  SC_REPORT_FATAL(ID_ETISSVP_RISCVCPU, "currently we dont support FI on RISCVCPU");
}

void etissvp::RISCVCPUFactory::genFI(sc_core::sc_module_name name) {
  SC_REPORT_FATAL(ID_ETISSVP_RISCVCPU, "currently we dont support FI on RISCVCPU");
}
