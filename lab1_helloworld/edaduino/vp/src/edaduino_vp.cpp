/**
 * @Author: geier
 * @Date:   2020-03-19
 * @Email:  johannes.geier@tum.de
 * @Filename: edaduino_vp.cpp
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

#include "edaduino_vp.h"

#include "periphs/uart.h"
#include "etissvp/generic-tlmcomp/mem.h"
#include "etissvp/generic-tlmcomp/soc.h"
#include "utils/config.h"
#include "riscv_cpu.h"

#define ID_EDADUINOVP "EdaDuinoVP"

EdaDuinoVPDefaultConfig::EdaDuinoVPDefaultConfig(){
    // Bus
    set("bus.masters", 2);
	set("bus.slaves", 5);
	set("bus.type", 2);
    // CPU
    set("cpu.name", "edaduino_core");
    set("cpu.arch", "RISCV");
	set("cpu.irqs", 32);
	// ROM
//	set("rom.name", "ROM");
//	set("rom.start", 0x00000000);
//	set("rom.size", 0x00080000);
//	set("rom.delay_ps", 0);
//	set("rom.file", "dummyrom");
	// CLINT
	set("clint.start", 0x02000000);
	set("clint.size", 0x000C0000);
    set("clint.irqs", 2);
	set("clint.regs", 5);
	// UART
	set("uart.start", 0x10000000);
	set("uart.size", 0x00001000);
    set("uart.irqs", 1);
	set("uart.regs", 12);
    // AES_HA
	set("aes_ha.start", 0x10001000);
	set("aes_ha.size",  0x00001000);
    set("aes_ha.irqs",  1);
	set("aes_ha.regs",  5);
	// TIMER
	set("timer.start", 0x18000000);
	set("timer.size", 0x00001000);
    set("timer.irqs", 4);
	set("timer.regs", 12);
	// DRAM
	set("dram.name", "DRAM");
	set("dram.start", 0x00000000);
	set("dram.size",  0x00100000);
	set("dram.delay_ps", 0);
}


EdaDuinoVP::EdaDuinoVP(const etissvp::Config &cfg, etiss::Initializer* etiss_init) : etiss_init_{etiss_init} {

    etissvp::SoCParams _soc_params;
    _soc_params.etiss_init_ = etiss_init_;
    _soc_params.bus_params_.num_masters_ = cfg.getSubConfig("bus").get<size_t>("masters");
    _soc_params.bus_params_.num_slaves_ = cfg.getSubConfig("bus").get<size_t>("slaves");
    _soc_params.main_cpu_name_ =  cfg.getSubConfig("cpu").get<std::string>("name");
    
    EdaDuinoSoCParams _edaduino_soc_params;

    _edaduino_soc_params.cpu_params_.etiss_init_ = etiss_init;
    _edaduino_soc_params.cpu_params_.num_irqs_ = cfg.getSubConfig("cpu").get<size_t>("irqs");
    _edaduino_soc_params.cpu_params_.irq_handler_type_ = etiss::EDGE_TRIGGERED;
    
    _edaduino_soc_params.dram_params_.base_addr_ = cfg.getSubConfig("dram").get<uint64_t>("start");
    _edaduino_soc_params.dram_params_.size_ = cfg.getSubConfig("dram").get<size_t>("size");
    _edaduino_soc_params.dram_params_.has_ram_ = true;
    _edaduino_soc_params.dram_params_.is_rom_ = false;
    _edaduino_soc_params.dram_params_.ACCESS_TIME = sc_core::sc_time(cfg.getSubConfig("dram").get<unsigned>("delay_ps"), sc_core::SC_PS);
    
    _edaduino_soc_params.uart_params_.base_addr   = cfg.getSubConfig("uart").get<uint64_t>("start");
    _edaduino_soc_params.uart_params_.size        = cfg.getSubConfig("uart").get<size_t>("size");
    _edaduino_soc_params.uart_params_.num_irqs    = cfg.getSubConfig("uart").get<size_t>("irqs");
    _edaduino_soc_params.uart_params_.num_regs    = cfg.getSubConfig("uart").get<size_t>("regs");

    _edaduino_soc_params.timer_params_.base_addr   = cfg.getSubConfig("timer").get<uint64_t>("start");
    _edaduino_soc_params.timer_params_.size        = cfg.getSubConfig("timer").get<size_t>("size");
    _edaduino_soc_params.timer_params_.num_irqs    = cfg.getSubConfig("timer").get<size_t>("irqs");
    _edaduino_soc_params.timer_params_.num_regs    = cfg.getSubConfig("timer").get<size_t>("regs");

    _edaduino_soc_params.clint_params_.base_addr   = cfg.getSubConfig("clint").get<uint64_t>("start");
    _edaduino_soc_params.clint_params_.size        = cfg.getSubConfig("clint").get<size_t>("size");
    _edaduino_soc_params.clint_params_.num_irqs    = cfg.getSubConfig("clint").get<size_t>("irqs");
    _edaduino_soc_params.clint_params_.num_regs    = cfg.getSubConfig("clint").get<size_t>("regs");
    
    _edaduino_soc_params.aes_ha_params_.base_addr   = cfg.getSubConfig("aes_ha").get<uint64_t>("start");
    _edaduino_soc_params.aes_ha_params_.size        = cfg.getSubConfig("aes_ha").get<size_t>("size");
    _edaduino_soc_params.aes_ha_params_.num_irqs    = cfg.getSubConfig("aes_ha").get<size_t>("irqs");
    _edaduino_soc_params.aes_ha_params_.num_regs    = cfg.getSubConfig("aes_ha").get<size_t>("regs");

    core_ = std::make_unique<EdaDuinoSoC>("edaduino_soc", std::move(_edaduino_soc_params), std::move(_soc_params));
}

void EdaDuinoVP::setup() {

    reset_gen_.rst_o_(rst_);

    auto soc = dynamic_cast<EdaDuinoSoC*>(core_.get());
    if (!soc) {
        SC_REPORT_FATAL(ID_EDADUINOVP, "soc couldn't be created properly");
    }
    soc->setup();
    soc->rst_i_(rst_);
    soc->connectExternalDevice<UART>("uart_if", &(uart_device_.sock_t_),
                                    &(uart_device_.sock_i_));

}
