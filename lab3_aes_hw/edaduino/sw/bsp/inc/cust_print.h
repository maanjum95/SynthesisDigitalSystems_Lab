/**
@copyright
<pre>
        Copyright (c) 2014 Institute for Electronic Design Automation, TU Munich

        The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
        FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
        LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
        THE SOFTWARE.
</pre>
@author Josef Weinzierl

@date November 22, 2016
*/
/**
        @file

        @brief provides custom print functions

        @detail
*/

#ifndef __CUST_PRINT_H__
#define __CUST_PRINT_H__

#include <inttypes.h>

#define TO_HEX(i) ((i) <= 9 ? '0' + (i) : 'A' - 10 + (i))

#define PRINT_CHAR(LOGGER_ADDR, VAL) *(volatile char*)(LOGGER_ADDR) = (VAL)

#define PRINT_INT16(LOGGER_ADDR, VAL) *(volatile int16_t*)(LOGGER_ADDR) = (VAL)

#define PRINT_INT32(LOGGER_ADDR, VAL) *(volatile int32_t*)(LOGGER_ADDR) = (VAL)

// #define PRINT_INT64(LOGGER_ADDR, VAL)\
//   *(volatile int64_t*) (LOGGER_ADDR) = (VAL)

void custom_print_string(volatile char* logger_addr, char* string);

void custom_print_hex_int8(volatile char* logger_addr, int8_t val);

void custom_print_hex_int16(volatile char* logger_addr, int16_t val);

void custom_print_hex_int32(volatile char* logger_addr, int32_t val);

// void custom_print_hex_int64(volatile char* logger_addr, int64_t val);

void custom_print_float(volatile char* logger_addr, float x);

void custom_print_test(volatile char* logger_addr);

#endif /*__CUST_PRINT_H__*/
