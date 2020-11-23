/**
 * @Author: geier
 * @Date:   2020-04-23
 * @Email:  johannes.geier@tum.de
 * @Filename: edaduino_vp.h
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

#ifndef __EDADUINO_VP_SIMPLE_H__
#define __EDADUINO_VP_SIMPLE_H__

#include "etissvp/generic-tlmcomp/reset_gen.h"
#include "periphs/uart_device.h"
#include "edaduino_soc.h"
#include "utils/config.h"

class EdaDuinoVPDefaultConfig : public etissvp::Config {
 public:
  EdaDuinoVPDefaultConfig();
};


class EdaDuinoVP final {
 public:
  explicit EdaDuinoVP(const etissvp::Config &cfg, etiss::Initializer*);
  void setup();

 private:
  sc_core::sc_signal<bool> rst_{"reset_sig"};

  etiss::Initializer* etiss_init_{nullptr};
  
  etissvp::ResetGenerator reset_gen_{"reset_generator", 10};
  std::unique_ptr<etissvp::SoC> core_{nullptr};
  
  ExternalUARTDevice uart_device_{"uart_device"};
};

#endif /* __EDADUINO_VP_SIMPLE_H__*/
