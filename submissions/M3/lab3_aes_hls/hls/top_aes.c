#include "../c_src/aes.h"
#include "top_aes.h"

//#define DEBUG

#ifdef DEBUG
#include "stdio.h"
#endif

void aes16_bidir(uint32_t key[4], uint32_t inout[4], uint32_t iv[4]){
		//crpytdir_t cryptdir) {
#pragma HLS ARRAY_PARTITION variable=inout complete dim=1
#pragma HLS ARRAY_PARTITION variable=key complete dim=1
#pragma HLS ARRAY_PARTITION variable=iv complete dim=1

	uint8_t _key[16];
	uint8_t _text[16];
	uint8_t _iv[16];
    struct AES_ctx ctx;
	int i;
	int k;

	for(i = 0; i< 4; ++i){
		for (k = 0; k<4;++k){
			_key[i*4 +k]  = (key[i]   >>(8*k)  );
			_text[i*4 +k] = (inout[i] >>(8*k)  );
			_iv[i*4 +k] = 	(iv[i] >>(8*k)  );
		}
	}
#ifdef DEBUG
    printf("\n\nKEY32:0x");
	for(i = 0; i< 4; ++i){
        printf("%x", key[i]);
    }
    printf("\nKEY8: 0x");
    for(i = 0; i< 16; ++i){
        printf("%02hhx", _key[i]);
    }
    printf("\n\nIN32:0x");
	for(i = 0; i< 4; ++i){
        printf("%x", inout[i]);
    }
    printf("\nIN8: 0x");
    for(i = 0; i< 16; ++i){
        printf("%02hhx", _text[i]);
    }
#endif



    AES_init_ctx_iv(&ctx, _key, _iv);
    AES_CTR_xcrypt_buffer(&ctx, _text, 16);

	for(i = 0; i< 4; ++i){
		inout[i] =  ((uint32_t)(_text[i*4+3]) <<24) |
                    ((uint32_t)(_text[i*4+2]) <<16) |
                    ((uint32_t)(_text[i*4+1]) << 8) |
                    ((uint32_t)(_text[i*4+0]) << 0) ;
		iv[i] =  	((uint32_t)(ctx.Iv[i*4+3]) <<24) |
                    ((uint32_t)(ctx.Iv[i*4+2]) <<16) |
                    ((uint32_t)(ctx.Iv[i*4+1]) << 8) |
                    ((uint32_t)(ctx.Iv[i*4+0]) << 0) ;
	}
#ifdef DEBUG
    printf("\n\nOU32:0x");
	for(i = 0; i< 4; ++i){
        printf("%x", inout[i]);
    }
    printf("\nOU8: 0x");
    for(i = 0; i< 16; ++i){
        printf("%02hhx", _text[i]);
    }
#endif
}
