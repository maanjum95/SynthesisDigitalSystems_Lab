/**
 * @Author: sharif
 * @Date:   2019-03-09T16:08:07+01:00
 * @Email:  uzair.sharif@tum.de
 * @Project: etissvp-lib
 * @Filename: riscv_cpu.h
 * @Last modified by:   sharif
 * @Last modified time: 2019-03-10T02:05:58+01:00
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

#ifndef __ETISSVP_RISCVCPU_H__
#define __ETISSVP_RISCVCPU_H__

#include <memory>

#include "etissvp/base-tlmcomp/cpu.h"

namespace etissvp {
class RISCVCPUParams final {};

class RISCVCPU : virtual public CPU {
 public:
  RISCVCPU(sc_core::sc_module_name name, RISCVCPUParams&& riscv_cpu_params,
           CPUParams&& cpu_params);
  virtual ~RISCVCPU() = default;
  RISCVCPU(const RISCVCPU&) = default;
  RISCVCPU(RISCVCPU&&) = default;
  RISCVCPU& operator=(const RISCVCPU&) = default;
  RISCVCPU& operator=(RISCVCPU&&) = default;

  void setup() override;

 protected:
  RISCVCPUParams riscv_cpu_params_{};
};

class RISCVCPUFactory final : public CPUFactory {
 public:
  explicit RISCVCPUFactory(etiss::Initializer* etiss_init);

 private:
  RISCVCPUParams riscv_cpu_params_{};

  void initParams() override;
  void genSTD(sc_core::sc_module_name name) override;
  void genREF(sc_core::sc_module_name name) override;
  void genFI(sc_core::sc_module_name name) override;
};
}  // namespace etissvp

#endif
