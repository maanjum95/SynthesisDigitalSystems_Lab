/**
 * @Author: sharif
 * @Date:   2019-04-15T12:13:30+02:00
 * @Email:  uzair.sharif@tum.de
 * @Filename: external_uart_device.cpp
 * @Last modified by:   sharif
 * @Last modified time: 2019-04-15T12:13:40+02:00
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

#include "periphs/uart_device.h"

#define UART_UNIX_FIFO
#ifdef UART_UNIX_FIFO
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <poll.h>
static const char* FIFOIN = ".tmp/uartdevicefifoin";
static const char* FIFOOUT = ".tmp/uartdevicefifoout";

int ExternalUARTDevice::writeFIFO(unsigned char* ptr) {
  static int fd_fifo = 0;
  int n;
  struct stat attribut;

  if(fd_fifo == 0){
    if ((mkfifo (FIFOOUT,  S_IRUSR | S_IWUSR)) == -1) {
    /* FIFO bereits vorhanden - kein fataler Fehler */
      if(errno != EEXIST){
        exit (EXIT_FAILURE);
      }
    }
    if (stat (FIFOOUT, &attribut) == -1) {
      exit (EXIT_FAILURE);
    }

    if ((fd_fifo = open (FIFOOUT, O_RDWR)) == -1) {//O_RDWR)) == -1) {
      //perror ("open()");
      exit (EXIT_FAILURE);
    }
  }

  const char* p = reinterpret_cast<const char*>(ptr);
  n = write (fd_fifo, p, 1);
  return (n);

}

int ExternalUARTDevice::readFIFO(unsigned char* ptr) {
   static int fd_fifo = 0;
   int n;
   struct stat attribut;

   if(fd_fifo == 0) {
    if ((mkfifo (FIFOIN,  S_IRUSR | S_IWUSR)) == -1) {
      /* FIFO bereits vorhanden - kein fataler Fehler */
      if(errno != EEXIST){
        exit (EXIT_FAILURE);
      }
    }
    if (stat (FIFOIN, &attribut) == -1) {
      exit (EXIT_FAILURE);
    }

    if ((fd_fifo = open (FIFOIN, O_RDWR )) == -1) {
      //perror ("open()");
      exit (EXIT_FAILURE);
    }
  }

  n = read(fd_fifo, ptr, 1);
  //printf("Read: %c\n", *ptr);
  return n;
}
#endif

ExternalUARTDevice::ExternalUARTDevice(sc_core::sc_module_name name)
    : sc_core::sc_module{name} {
  sock_t_.register_b_transport(this, &ExternalUARTDevice::b_transport);
  SC_THREAD(sense_input);

}

void ExternalUARTDevice::b_transport(tlm::tlm_generic_payload& gp,
                                     sc_core::sc_time& delay) {
   unsigned char* ptr = gp.get_data_ptr();

   if(gp.get_command() == tlm::TLM_WRITE_COMMAND) {

      #ifdef UART_UNIX_FIFO
      auto ret = writeFIFO(ptr);

      if (ret <= 0){
         gp.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
      }
      else {
         gp.set_response_status(tlm::TLM_OK_RESPONSE);
      }

      #else //only stdout:
      std::cout << *ptr << std::endl;
      gp.set_response_status(tlm::TLM_OK_RESPONSE);
      #endif
   }
   else {

      #ifdef UART_UNIX_FIFO
      unsigned char* ptr = gp.get_data_ptr();
      static unsigned char last = ' ';
      //auto ret = readFIFO(ptr);

      if(!inbuf_.empty()){
        *ptr = inbuf_[0];
        inbuf_.erase(inbuf_.begin());
        gp.set_response_status(tlm::TLM_OK_RESPONSE);
        last = *ptr;
      }else{
        last = *ptr;
        gp.set_response_status(tlm::TLM_OK_RESPONSE);
      }

      #else
      #endif
   }
}


bool canReadFromPipe(int fd){
    //file descriptor struct to check if POLLIN bit will be set
    //fd is the file descriptor of the pipe
    struct pollfd fds{ .fd = fd, .events = POLLIN };
    //poll with no wait time
    int res = poll(&fds, 1, 0);

    //if res < 0 then an error occurred with poll
    //POLLERR is set for some other errors
    //POLLNVAL is set if the pipe is closed
    if(res < 0||fds.revents&(POLLERR|POLLNVAL))
    {
        //an error occurred, check errno
    }
    return fds.revents&POLLIN;
}

void ExternalUARTDevice::sense_input() {
  sc_core::sc_time delay{sc_core::SC_ZERO_TIME};

  static int fd_fifo = 0;
  int n;
  struct stat attribut;

  while(1) {
    wait(1000, sc_core::SC_NS);
    if(fd_fifo == 0) {
      if ((mkfifo (FIFOIN,  S_IRUSR | S_IWUSR)) == -1) {
        /* FIFO bereits vorhanden - kein fataler Fehler */
        if(errno != EEXIST){
          exit (EXIT_FAILURE);
        }
      }
      if (stat (FIFOIN, &attribut) == -1) {
        exit (EXIT_FAILURE);
      }

      if ((fd_fifo = open (FIFOIN, O_RDWR )) == -1) {
        //perror ("open()");
        exit (EXIT_FAILURE);
      }
    }
    else{
      if(canReadFromPipe(fd_fifo)){
        unsigned char event = 1;
        do{
          unsigned char in;
          read(fd_fifo, &in, 1);
          inbuf_.push_back(in);
        }while(canReadFromPipe(fd_fifo));

        tlm::tlm_generic_payload gp{};
        gp.set_data_ptr(&event);
        gp.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
        gp.set_data_length(1);
        sock_i_->b_transport(gp, delay);
      }
      else if(inbuf_.empty()){
        unsigned char event = 0;
        tlm::tlm_generic_payload gp{};
        gp.set_data_ptr(&event);
        gp.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
        gp.set_data_length(1);
        sock_i_->b_transport(gp, delay);
      }
    }
  }
}
