////////////////////////////////////////////////////////////////////////////////////
// \file main.c
// \brief target software main application file
////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "bsp.h"

#include "aes.h"
#include "cust_print.h"

int aes_done; //<< unused

#define MSG_ROWS (46)
#define MSG_COLS (192)
typedef uint8_t msg_t[MSG_ROWS][MSG_COLS];
#include "data/msg.c"   // instantiates the encrpyted message of type msg_t
uint8_t* msg_1d = (uint8_t*)msg; // (optional) use matrix as one-dimensional array, i.e. uint8_t msg[MSG_ROWS*MSG_COLS]

const uint8_t key[16] = {
      0x2b, 0x7e, 0x15, 0x16,
      0x28, 0xae, 0xd2, 0xa6,
      0xab, 0xf7, 0x15, 0x88,
      0x09, 0xcf, 0x4f, 0x3c }; //<< (private/secure) key (In a real application, do not put this in plain source code)

const uint8_t iv[16] = {
      0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55,
      0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00 }; //<< (public) key. Assume this got transmitted along the encrypted message

////////////////////////////////////////////////////////////////////////////////////
// \brief SysTick ISR
static void systemtimer_irqhandler(void){
    custom_print_string(ETISSVP_LOGGER, "SysTick - 10ms\n");
}

////////////////////////////////////////////////////////////////////////////////////
// \brief UART ISR
static void uart_irqhandler(void){
    custom_print_string(ETISSVP_LOGGER, "UART interrupt callback taken\n");
}

////////////////////////////////////////////////////////////////////////////////////
// \brief (Virtual) board support package configuration. Sets the SysTick time period in µs and custom ISR
static bsp_init_t cfg = {
    .systemtimer_us= 10000, // 10000us=10ms
    .systemtimer_callback = systemtimer_irqhandler,
    .uart_callback = uart_irqhandler,
    .aes_ha_callback = NULL
};

////////////////////////////////////////////////////////////////////////////////////
// \brief Bi-directional (Encrypt/Decrypt) using the software library (app/aes.h)
// \param msg Message as 1-dimensional byte-array, accepts msg_t format, too.
// \return amount of cycles spent for en-/decrypting the message
uint32_t crypt_msg_sw(uint8_t* msg, const uint8_t* key, const uint8_t* iv){
	uint64_t time1 = 0, time2 = 0;
    struct AES_ctx ctx;

	/* TODO: Invoke the software en-/decrypt a msg_t data structure.
	 * 		 Return the spent time for setup and actual en-/decryption
	 * Tips: - AES_CTR_xcrypt_buffer(..) takes a AES_ctx struct instantiated by AES_init_ctx_iv(..) the (private) key and the IV,
	 * 		   a read-write byte-array buffer (message), and the length of the buffer to en-/decrypt.
	 * 		 - The IV is updated inside the AES_ctx struct within one call to AES_CTR_xcrypt_buffer(..)
	 * 		 - AES_CTR_xcrypt_buffer(..) takes messages with lengths of 16-Byte multiplicity
	 * 		 - Use get_CpuCycles() from bsp.h to retreive the current Cpu cycle count */

    return(time2 - time1);
}

////////////////////////////////////////////////////////////////////////////////////
// \brief Display the message. MSG_ROWS rows of MSG_COLS bytes
// \param msg Message as 2-dimensional byte-array in msg_t format.
void display_msg(const msg_t msg){
	/* TODO: Display the message with printf("%c", <character>)) as specified in the \brief */
    for(int i = 0; i < MSG_ROWS; ++i){
        for (int k = 0; k< MSG_COLS; ++k){
            printf("%c", msg[i][k]);
        }
        printf("\n");
    }
}

int main()
{

    bsp_init(&cfg);

    uint32_t time_sw = 0;

    time_sw = crypt_msg_sw(msg_1d, key, iv);

    display_msg(msg);

    printf("SW - cycles %d\n", time_sw);
    
    while(1){
    	asm("");
    }
}
