#include "../hls/top_aes.h"

#include "stdio.h"
#include "stdlib.h"

#ifdef CPLUSPLUS
#include <cstdlib>
union dat_t{
	uint8_t _b[16];
	uint32_t _w[4];
};
#endif

int main(void) {
    FILE         *fp;
    unsigned char predict = 0x55;

#ifdef CPLUSPLUS
    dat_t key
#else
    uint8_t key[16]
#endif
    = {
      (uint8_t)0x2b, (uint8_t)0x7e, (uint8_t)0x15, (uint8_t)0x16,
      (uint8_t)0x28, (uint8_t)0xae, (uint8_t)0xd2, (uint8_t)0xa6,
      (uint8_t)0xab, (uint8_t)0xf7, (uint8_t)0x15, (uint8_t)0x88,
      (uint8_t)0x09, (uint8_t)0xcf, (uint8_t)0x4f, (uint8_t)0x3c};

#ifdef CPLUSPLUS
    dat_t plain_text
#else
    uint8_t plain_text[16]
#endif      
    = {
      (uint8_t)0x6b, (uint8_t)0xc1, (uint8_t)0xbe, (uint8_t)0xe2,
      (uint8_t)0x2e, (uint8_t)0x40, (uint8_t)0x9f, (uint8_t)0x96,
      (uint8_t)0xe9, (uint8_t)0x3d, (uint8_t)0x7e, (uint8_t)0x11,
      (uint8_t)0x73, (uint8_t)0x93, (uint8_t)0x17, (uint8_t)0x2a};
    
    uint8_t publicKey[16]={
    	    (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55,
    	    (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55, (uint8_t)0x55,
    	    (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00,
    	    (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00, (uint8_t)0x00};

    uint8_t iv[16];
    uint8_t d_i[16];
    uint8_t d_e[16];
    uint8_t d_d[16];  
      
    printf("\n*** AES Test ***\n\n");  
      
    fp=fopen("out.dat","w");
    
    fprintf(fp,"KEY: 0x");
#ifdef CPLUSPLUS
    for(int i = 0; i < sizeof(key._b); i++){
        fprintf(fp,"%02hhx", key._b[i]);
    }    
    fprintf(fp,"\nD_i: 0x");
    for(int i = 0; i < sizeof(plain_text._b); i++){
        d_i[i] = plain_text._b[i];
        fprintf(fp,"%02hhx", plain_text._b[i]);
    }
    
    //aes16_bidir(key._w, plain_text._w, CRYPTDIR::ENC);
    aes16_bidir(key._w, plain_text._w, iv);
    
    fprintf(fp,"\nD_e: 0x");
    for(int i = 0; i < sizeof(plain_text._b); i++){
        d_e[i] = plain_text._b[i];
        fprintf(fp,"%02hhx", plain_text._b[i]);
    }

    //aes16_bidir(key._w, plain_text._w, CRYPTDIR::DEC);
    aes16_bidir(key._w, plain_text._w, iv);
    
    fprintf(fp,"\nD_d: 0x");
    for(int i = 0; i < sizeof(plain_text._b); i++){
        d_d[i] = plain_text._b[i];
        fprintf(fp,"%02hhx", plain_text._b[i]);
    }
#else
    int i = 0;
    for(i = 0; i < sizeof(key); i++){
        fprintf(fp,"%02hhx", key[i]);
    }    
    fprintf(fp,"\nD_i: 0x");
    for(i = 0; i < sizeof(plain_text); i++){
        d_i[i] = plain_text[i];
        fprintf(fp,"%02hhx", plain_text[i]);
    }
    
    for(i = 0; i < sizeof(iv); ++i) iv[i] = publicKey[i];
    aes16_bidir((uint32_t*)key, (uint32_t*)plain_text, (uint32_t*)iv);
    
    fprintf(fp,"\nD_e: 0x");
    for(i = 0; i < sizeof(plain_text); i++){
        d_e[i] = plain_text[i];
        fprintf(fp,"%02hhx", plain_text[i]);
    }
    for(i = 0; i < sizeof(iv); ++i) iv[i] = publicKey[i];
    aes16_bidir((uint32_t*)key, (uint32_t*)plain_text, (uint32_t*)iv);

    fprintf(fp,"\nD_d: 0x");
    for(i = 0; i < sizeof(plain_text); i++){
        d_d[i] = plain_text[i];
        fprintf(fp,"%02hhx", plain_text[i]);
    }
#endif    
    fclose(fp);
    
    system("cat out.dat");
    printf("\n\n");
    
    printf ("Comparing against output data ...\n");
    if (system("diff -w out.dat out.gold.dat")) {
        if(system("diff -w out.dat testbench/out.gold.dat")){
            fprintf(stdout, "*******************************************\n");
            fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
            fprintf(stdout, "*******************************************\n");
        }else{
            for(i = 0; i< sizeof(d_i); i++)if(d_i[i]!=d_d[i])return (0); 
            fprintf(stdout, "*******************************************\n");
            fprintf(stdout, "PASS: The output matches the golden output!\n");
            fprintf(stdout, "*******************************************\n");
            return 0;
        }
        return 1;
    } else {
        for(i = 0; i< sizeof(d_i); i++)if(d_i[i]!=d_d[i])return (0); 
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "PASS: The output matches the golden output!\n");
        fprintf(stdout, "*******************************************\n");
        return 0;
    }
}
