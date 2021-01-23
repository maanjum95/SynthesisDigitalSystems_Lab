#ifndef _TOP_H_
#define _TOP_H_

#include "stdint.h"

typedef enum CRYPTDIR{
    ENC = 0,
    DEC = 1
} crpytdir_t;

void aes16_bidir(uint32_t key[4], uint32_t inout[4], uint32_t iv[4]);
		// crpytdir_t cryptdir);

#endif
