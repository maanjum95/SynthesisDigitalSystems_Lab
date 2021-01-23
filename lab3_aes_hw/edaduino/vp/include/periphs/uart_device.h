/**
 * @Author: sharif
 * @Date:   2019-04-15T12:10:40+02:00
 * @Email:  uzair.sharif@tum.de
 * @Filename: external_uart_device.h
 * @Last modified by:   sharif
 * @Last modified time: 2019-04-15T12:10:51+02:00
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

#ifndef __EXTERNAL_UART_DEVICE_H__
#define __EXTERNAL_UART_DEVICE_H__

#include "systemc"
#include "tlm_utils/simple_initiator_socket.h"
#include "tlm_utils/simple_target_socket.h"

class ExternalUARTDevice final : sc_core::sc_module {
  SC_HAS_PROCESS(ExternalUARTDevice);


 public:
  tlm_utils::simple_target_socket<ExternalUARTDevice> sock_t_{"target_socket"};
  tlm_utils::simple_initiator_socket<ExternalUARTDevice> sock_i_{
      "initiator_socket"};

  ExternalUARTDevice(sc_core::sc_module_name);
  void b_transport(tlm::tlm_generic_payload&, sc_core::sc_time&);

 private:
  void sense_input();
  int readFIFO(unsigned char* buf);
  int writeFIFO(unsigned char* buf);

  std::vector<char> inbuf_;
};

#endif
