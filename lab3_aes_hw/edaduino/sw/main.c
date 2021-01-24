////////////////////////////////////////////////////////////////////////////////////
// \file main.c
// \brief target software main application file
////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "bsp.h"

#include "aes.h"
#include "aes_ha_drv.h"
#include "cust_print.h"

#define MSG_ROWS (46)
#define MSG_COLS (192)
#define AES_BLOCK_LEN (16)
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

int aes_done = 0;		//<< Global variable for simple messaging AES Interrupt Service Routine to main application

////////////////////////////////////////////////////////////////////////////////////
// \brief AES_HA ISR
static void aes_ha_irqhandler(void){
    aes_ha_clearInterrupt();
    aes_done = 1;
}

////////////////////////////////////////////////////////////////////////////////////
// \brief (Virtual) board support package configuration. Sets the SysTick time period in µs and custom ISR
static bsp_init_t cfg = {
    .systemtimer_us= 10000, // 10000us=10ms
    .systemtimer_callback = systemtimer_irqhandler,
    .uart_callback = uart_irqhandler,
    .aes_ha_callback = aes_ha_irqhandler
};

////////////////////////////////////////////////////////////////////////////////////
// \brief Bi-directional (Encrypt/Decrypt) using the hardware accelerator (cmake/bsp/inc/aes_ha_drv.h)
// \param msg Message as 1-dimensional byte-array, accepts msg_t format, too.
// \return amount of cycles spent for en-/decrypting the message
uint32_t crypt_msg_hw(uint8_t* msg, const uint8_t* key, const uint8_t* iv){
	uint64_t time1 = 0, time2 = 0;

	uint8_t iv_val[16];
	uint8_t input[16];
	uint8_t encrypted[16];
	uint8_t buffer[16];
	int i, j;

	/* TODO: Invoke the hardware accelerator to en-/decrypt a msg_t data structure.
	 * 		 Return the spent time for setup and actual en-/decryption
	 * Tips: - Driver functions aes_ha_write128B_.../aes_ha_read128B_... take a pointer to a byte-array and accesses the first 128 bit
	 * 		   or rather 16 Byte. A 16 Byte en-/decryption is started by calling aes_ha_start()
	 * 		 - After every en/-decryption, the IV-register in hardware is updated according to the CTR logic. Make sure to update rewrite the IV
	 * 		   for every new message en/decryption
	 * 		 - The (private) Key-register is not updated by the hardware in any way.
	 * 		 - Find a way to determine a finished 128 Bit encryption by interfacing with the AES_HA ISR */
	time1 = get_CpuCycles();

	// writing the key
	aes_ha_write128B_Key(key);

	// copying the iv value
	for (i = 0; i < 16; i++)
		iv_val[i] = iv[i];

	for (i = 0; i < MSG_ROWS*MSG_COLS; i+=16) {
		// Encrypt
		aes_ha_write128B_IV(iv_val);

		// copying message to buffer
		for (j = 0; j < 16; j++)
			buffer[j] = msg[i+j];

		// Processing this 16 byte data
		aes_ha_write128B_IO(buffer);
		aes_ha_read128B_IO(input);
		aes_done = 0;
		aes_ha_start();

		// Wait for encryption to complete
		while(!aes_done)
			aes_ha_read128B_IO(encrypted); // TODO

		// copying buffer back to original message
		for (j = 0; j < 16; j++)
			msg[i+j] = encrypted[j]; // TODO

		// updating iv
		for (j = (AES_BLOCKLEN - 1); j >= 0; j--) {
			if (iv_val[j] == 255) {
				iv_val[j] = 0;
				continue;
			}
			iv_val[j]++;
			break;
		}
	}


	time2 = get_CpuCycles();
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

    /* Note: The following block should report a passed functional test for the hardware accelerator */
    if(aes_ha_Func_test(ETISSVP_LOGGER) <= 0){
    	custom_print_string(ETISSVP_LOGGER, "AES_HA functional test FAILED!\n");
    }else{
    	custom_print_string(ETISSVP_LOGGER, "AES_HA functional test PASSED!\n");
    }

    uint32_t time_hw = 0;

    time_hw = crypt_msg_hw(msg_1d, key, iv);
    display_msg(msg);

    printf("HW - cycles %d\n", time_hw);
    
    while(1){
    	asm("");
    }
}
