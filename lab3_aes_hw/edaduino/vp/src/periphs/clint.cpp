/**
 * @Author: J.Geier
 * @Date:   2020-04-13T13:19:42+01:00
 * @Filename: clint.cpp
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

#include "periphs/clint.h"


#define ID_CLINT "Clint"

Clint::Clint(sc_core::sc_module_name name, etissvp::PerParams&& params,
             etissvp::SoC* owner,  const uint64_t rtcPeriod_ps )
    : PeripheralBaseMinres(name, std::move(params), owner),
	  rtcPeriod_ps(rtcPeriod_ps){
  reset();

  msip_.setWriteCallback([this](auto&&, uint32_t& valueToWrite) {
    msip_ = valueToWrite;

    SC_REPORT_INFO(ID_CLINT, "New MSIP (IPI) Set");
  });

  mtimecmplo_.setWriteCallback([this](auto&&, uint32_t& valueToWrite) {
    mtimecmplo_ =
        valueToWrite;
    SC_REPORT_INFO(ID_CLINT, "New Compare Value Set (low word)");
  });

  mtimecmphi_.setWriteCallback([this](auto&&, uint32_t& valueToWrite) {
    mtimecmphi_ =
        valueToWrite;
    SC_REPORT_INFO(ID_CLINT, "New Compare Value Set (high word)");
  });
  
  mtimelo_.setWriteCallback([this](auto&&, uint32_t& valueToWrite) {
    mtimelo_ =
        valueToWrite;
    SC_REPORT_INFO(ID_CLINT, "New Timer Value Set (low word)");
  });

  mtimehi_.setWriteCallback([this](auto&&, uint32_t& valueToWrite) {
    mtimehi_ =
        valueToWrite;
    SC_REPORT_INFO(ID_CLINT, "New Timer Value Set (high word)");
  });  
  
  SC_THREAD(clkProcess);
}

void Clint::reset() {
  for (auto& bf : regs->bitfields) {
    bf = 0;
  }
}

void Clint::clkProcess() {
  auto cpu_cycle_time = etiss::cfg().get<int>("Arch::cpuCycleTime_ps", 0);
  sc_core::sc_time base_clk_period{static_cast<double>(cpu_cycle_time),
                                   sc_core::SC_PS};
  uint64_t rtcCounter_ps = 0;
  static const uint64_t _OVERFLOW_ = 0x0FFFFFFFF;
  
  while (true) {

	wait(base_clk_period);

	if(msip_ & 0x1){
		(*irq_out_)[0] = 1;
	}else{
		(*irq_out_)[0] = 0;
	}

	rtcCounter_ps += cpu_cycle_time;
	if(rtcCounter_ps >= rtcPeriod_ps){
		(*irq_out_)[1] = 0;
	    mtimelo_ = mtimelo_ + 1;
	    if(mtimelo_ >= _OVERFLOW_){
	        mtimelo_ = 0;
	        mtimehi_ = mtimehi_ + 1;
	        if(mtimehi_ >= _OVERFLOW_){
	            mtimehi_ = 0;
	        }
	    }
	    uint64_t tmp1 = 0, tmp2 = 0;
	    tmp1 = uint64_t(mtimelo_) | (uint64_t(mtimehi_) << 32);
	    tmp2 = uint64_t(mtimecmplo_) | (uint64_t(mtimecmphi_) << 32);
	    if(tmp1 >= tmp2){
	    	(*irq_out_)[1] = 1;
	    }
		rtcCounter_ps = 0;
	}
  }
}
