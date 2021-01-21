/**
 * @Author: geier
 * @Date:   2020-04-23
 * @Email:  johannes.geier@tum.de
 * @Filename: edaduino_soc.cpp
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
#include "edaduino_soc.h"
#include "riscv_cpu.h"

#include "etissvp/pulp-tlmcomp/periphs/timer.h"
#include  "periphs/uart.h"

#include "periphs/clint.h"
#include "aes_ha/aes_ha.h"

#define ID_EDADUINOSOC "EdaDuinoSoC"

EdaDuinoSoC::EdaDuinoSoC(sc_core::sc_module_name name,
                       EdaDuinoSoCParams&& edaduino_soc_params,
                       etissvp::SoCParams&& soc_params)
    : etissvp::SoC(name, std::move(soc_params)),
      edaduino_soc_params_{std::move(edaduino_soc_params)} {}

void EdaDuinoSoC::setup() {
    static const char* N_MAIN_BUS = "cpu_bus";


    std::string range = etiss::cfg().get<std::string>("vp::elf_file", "");

    if(range != ""){
      std::vector<std::string> elf_file_paths;
      size_t pos = 0;
      std::string delimiter = ",";
      std::string elf_file_path;

      do {
        pos = range.find(delimiter);
        elf_file_path = range.substr(0, pos);
        range.erase(0, pos + delimiter.length());
        if(elf_file_path != ""){
          try {
            auto elf_reader = std::make_unique<ELFIO::elfio>();
            elf_reader->load(elf_file_path);
            elf_readers_.push_back(std::move(elf_reader));
          } catch (const std::out_of_range&) {
            XREPORT_FATAL("elf_reader couldn't load elf file in SoC::setup()");
          }
        }
      } while (pos != std::string::npos);
    }else{
      XREPORT_FATAL("No ELF files found");
    }

    addBus(N_MAIN_BUS, std::move(soc_params_.bus_params_));

    auto bus = buses_.at(N_MAIN_BUS).get();

    addCPU(
    		std::make_unique<etissvp::RISCVCPU>(
    				soc_params_.main_cpu_name_.c_str(),
                    std::move(etissvp::RISCVCPUParams()),
					std::move(edaduino_soc_params_.cpu_params_)),
			std::string(N_MAIN_BUS));

    etissvp::CPU* cpu{nullptr};
    try {
      cpu = cpus_.at(soc_params_.main_cpu_name_).get();
    } catch (const std::out_of_range&) {
      XREPORT_FATAL("cpu not found in EdaDuinoSoC::setup()");
    }

    addMem("dram", std::move(edaduino_soc_params_.dram_params_), N_MAIN_BUS);
    auto dram = mems_.at("dram").get();
    if(dram == nullptr){ // critical
    	XREPORT_FATAL("dram not found in EdaDuinoSoC::setup()");
	}

    addPer<UART>("uart_if", std::move(edaduino_soc_params_.uart_params_), N_MAIN_BUS);
    auto uart = pers_.at("uart_if").get();
    if(uart == nullptr){ // critical
    	XREPORT_FATAL("uart not found in EdaDuinoSoC::setup()");
    }
    uart->bindIRQ(0, &irq_srcs_n_[16]);

    addPer<Timer>("timer", std::move(edaduino_soc_params_.timer_params_), N_MAIN_BUS);
    auto timer = pers_.at("timer").get();
    if(timer == nullptr){ // critical
    	XREPORT_FATAL("timer not found in EdaDuinoSoC::setup()");
    }
    for(size_t i = 0; i < 4; ++i){
    	timer->bindIRQ(i, &irq_srcs_n_[17+i]);
    }

    addPer<Aes_Ha>("aes_ha", std::move(edaduino_soc_params_.aes_ha_params_), N_MAIN_BUS);
    auto aes_ha = pers_.at("aes_ha").get();
    if(aes_ha == nullptr){ // critical
    	XREPORT_FATAL("aes_ha not found in EdaDuinoSoC::setup()");
    }
    aes_ha->bindIRQ(0, &irq_srcs_n_[21]);

    addPer<Clint>("clint", std::move(edaduino_soc_params_.clint_params_), N_MAIN_BUS);
    auto clint = pers_.at("clint").get();
    if(clint == nullptr){ //critical
    	XREPORT_FATAL("clint not found in EdaDuinoSoC::setup()");
    }
    clint->bindIRQ(0, & irq_srcs_n_[3]);
    clint->bindIRQ(1, & irq_srcs_n_[7]);

    cpu->setup();

    for (size_t i = 0; i< irq_srcs_n_.size(); ++i){
        cpu->bindIRQ(i,  irq_srcs_n_[i]);
    }
}

void EdaDuinoSoC::addCPU( std::unique_ptr<etissvp::CPU> cpu, std::string bus_name){
	  cpu->rst_i_(rst_i_);

	  etissvp::Bus* bus{nullptr};
	  try {
	    bus = (buses_.at(bus_name)).get();
	  } catch (const std::out_of_range&) {
	    XREPORT_FATAL("bus not found in SoC::addCPU()");
	  }

	  bus->connectMaster(cpu->instr_sock_i_.get());
	  bus->connectMaster(cpu->data_sock_i_.get());

	  auto ptr = cpu.get();
	  cpus_[cpu->name()] = std::move(cpu);
}
