/**
 * @Author: geier
 * @Date:   2020-04-23
 * @Email:  johannes.geier@tum.de
 * @Filename: main.cpp
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

#include "etiss/ETISS.h"
#include "systemc"

#include "edaduino_vp.h"
#include "utils/logging.h"

#define VPCONFIGFILE "ini/vpcfg.ini"

int sc_main(int argc, char** argv) {
	bool physical = false;

    etissvp::SetCmdlineArgs(argc, argv);

    auto etiss_init = etissvp::GetETISSInit();

    //etiss::Initializer etiss_init{argc, argv};

    //Handling of reports
    sc_report_handler::set_log_file_name("vp_logging");   //Logging file

    // Configure VP:
    // 1) Use defaults from above
    EdaDuinoVPDefaultConfig cfg;
    // 2) Load/Replace with sets from ext. config file
    cfg.loadFromFile(VPCONFIGFILE);

    // Instantiate VP.  
    EdaDuinoVP vp{cfg, etiss_init};
    vp.setup();


    sc_core::sc_start();

    return 0;
}
