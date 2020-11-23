#include "cust_print.h"

void custom_print_string(volatile char* logger_addr, char* string)
{
  while (*string)
  {
    PRINT_CHAR(logger_addr, *string);
    string++;
  }
}

void custom_print_hex_int8(volatile char* logger_addr, int8_t val)
{
  char hex[5]; /* 2 chars (0x), 2 chars for 2 Bytes, 1 char NULL termination */
  hex[0] = '0';
  hex[1] = 'x';
  if(val <= 0xFF)
  {
    hex[2] = TO_HEX(((val & 0xF0) >> 4));
    hex[3] = TO_HEX((val & 0x0F));
    hex[4] = '\0';
  }
  custom_print_string(logger_addr, hex);
}

void custom_print_hex_int16(volatile char* logger_addr, int16_t val)
{
  char hex[7]; /* 2 chars (0x), 4 chars for 2 Bytes, 1 char NULL termination */
  hex[0] = '0';
  hex[1] = 'x';
  if(val <= 0xFFFF)
  {
    hex[2] = TO_HEX(((val & 0xF000) >> 12));
    hex[3] = TO_HEX(((val & 0x0F00) >> 8));
    hex[4] = TO_HEX(((val & 0x00F0) >> 4));
    hex[5] = TO_HEX((val & 0x000F));
    hex[6] = '\0';
  }
  custom_print_string(logger_addr, hex);
}

void custom_print_hex_int32(volatile char* logger_addr, int32_t val)
{
  char hex[11]; /* 2 chars (0x), 8 chars for 4 Bytes, 1 char NULL termination */
  hex[0] = '0';
  hex[1] = 'x';
  if(val <= 0xFFFFFFFF)
  {
    hex[2] = TO_HEX(((val & 0xF0000000) >> 28));
    hex[3] = TO_HEX(((val & 0x0F000000) >> 24));
    hex[4] = TO_HEX(((val & 0x00F00000) >> 20));
    hex[5] = TO_HEX(((val & 0x000F0000) >> 16));
    hex[6] = TO_HEX(((val & 0x0000F000) >> 12));
    hex[7] = TO_HEX(((val & 0x00000F00) >> 8));
    hex[8] = TO_HEX(((val & 0x000000F0) >> 4));
    hex[9] = TO_HEX((val & 0x0000000F));
    hex[10] = '\0';
  }
  custom_print_string(logger_addr, hex);
}

// void custom_print_hex_int64(volatile char* logger_addr, int64_t val)
// {
//   char hex[19]; /* 2 chars (0x), 16 chars for 8 Bytes, 1 char NULL
//   termination */ hex[0] = '0'; hex[1] = 'x'; if(val <= 0xFFFFFFFFFFFFFFFF)
//   {
//     hex[2] = TO_HEX(((val & 0xF000000000000000) >> 60));
//     hex[3] = TO_HEX(((val & 0x0F00000000000000) >> 56));
//     hex[4] = TO_HEX(((val & 0x00F0000000000000) >> 52));
//     hex[5] = TO_HEX(((val & 0x000F000000000000) >> 48));
//     hex[6] = TO_HEX(((val & 0x0000F00000000000) >> 44));
//     hex[7] = TO_HEX(((val & 0x00000F0000000000) >> 40));
//     hex[8] = TO_HEX(((val & 0x000000F000000000) >> 36));
//     hex[9] = TO_HEX(((val & 0x0000000F00000000) >> 32));
//     hex[10] = TO_HEX(((val & 0x00000000F0000000) >> 28));
//     hex[11] = TO_HEX(((val & 0x000000000F000000) >> 24));
//     hex[12] = TO_HEX(((val & 0x0000000000F00000) >> 20));
//     hex[13] = TO_HEX(((val & 0x00000000000F0000) >> 16));
//     hex[14] = TO_HEX(((val & 0x000000000000F000) >> 12));
//     hex[15] = TO_HEX(((val & 0x0000000000000F00) >> 8));
//     hex[16] = TO_HEX(((val & 0x00000000000000F0) >> 4));
//     hex[17] = TO_HEX((val & 0x000000000000000F));
//     hex[18] = '\0';
//   }
//   custom_print_string(logger_addr, hex);
// }

void custom_print_float(volatile char* logger_addr, float x){

	if (x < 0){
		PRINT_CHAR(logger_addr, '-');
		x = -x;
	}

	float restoreprec = x;
	unsigned d = 0;
	while (x >= 1.0){
		d++;
		x = x / 10.0;
	}

	while (d > 0){
		x = x * 10;
		int i = (int)x;
		if (((float)i)>x)
			i--;
		x = x-(float)i;
		PRINT_CHAR(logger_addr, '0'+i);
		d--;
	}

	PRINT_CHAR(logger_addr, '.');

	x = restoreprec;

	while (x >= 1000000000000.0)
		x = x-1000000000000.0;
	while (x >= 10000000000.0)
		x = x-10000000000.0;
	while (x >= 100000000.0)
		x = x-100000000.0;
	while (x >= 1000000.0)
		x = x-1000000.0;
	while (x >= 10000.0)
		x = x-10000.0;
	while (x >= 100.0)
		x = x-100.0;
	while (x >= 1.0)
		x = x-1.0;

	for (int i = 0;i<10;i++){
		x = x * 10;
		int j = (int)x;
		if (((float)j)>x)
			j--;
		x = x-(float)j;
		PRINT_CHAR(logger_addr, '0'+j);
	}


}


void custom_print_test(volatile char* logger_addr)
{
  // char test
  PRINT_CHAR(logger_addr,'a');
  PRINT_CHAR(logger_addr,'\n');

  // int tests
  PRINT_INT16(logger_addr,1234);
  PRINT_CHAR(logger_addr,'\n');

  int testint = 4321;
  PRINT_INT32(logger_addr,testint);
  PRINT_CHAR(logger_addr,'\n');

  // string tests
  custom_print_string(logger_addr,"static string\n");

  char teststring[] = "dynamic string\n";
  custom_print_string(logger_addr,teststring);

  // float tests
  float a = 137.071354;
  float b = 613.579365;
  float c = a-b;

  custom_print_string(logger_addr,"a = ");
  custom_print_float(logger_addr,a);
  PRINT_CHAR(logger_addr,'\n');

  custom_print_string(logger_addr,"b = ");
  custom_print_float(logger_addr,b);
  PRINT_CHAR(logger_addr,'\n');

  custom_print_string(logger_addr,"c = a - b = ");
  custom_print_float(logger_addr,c);
  PRINT_CHAR(logger_addr,'\n');
}
