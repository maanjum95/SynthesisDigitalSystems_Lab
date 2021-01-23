// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "key_0"
#define AUTOTB_TVIN_key_0  "../tv/cdatafile/c.aes16_bidir.autotvin_key_0.dat"
// wrapc file define: "key_1"
#define AUTOTB_TVIN_key_1  "../tv/cdatafile/c.aes16_bidir.autotvin_key_1.dat"
// wrapc file define: "key_2"
#define AUTOTB_TVIN_key_2  "../tv/cdatafile/c.aes16_bidir.autotvin_key_2.dat"
// wrapc file define: "key_3"
#define AUTOTB_TVIN_key_3  "../tv/cdatafile/c.aes16_bidir.autotvin_key_3.dat"
// wrapc file define: "inout_0"
#define AUTOTB_TVIN_inout_0  "../tv/cdatafile/c.aes16_bidir.autotvin_inout_0.dat"
#define AUTOTB_TVOUT_inout_0  "../tv/cdatafile/c.aes16_bidir.autotvout_inout_0.dat"
// wrapc file define: "inout_1"
#define AUTOTB_TVIN_inout_1  "../tv/cdatafile/c.aes16_bidir.autotvin_inout_1.dat"
#define AUTOTB_TVOUT_inout_1  "../tv/cdatafile/c.aes16_bidir.autotvout_inout_1.dat"
// wrapc file define: "inout_2"
#define AUTOTB_TVIN_inout_2  "../tv/cdatafile/c.aes16_bidir.autotvin_inout_2.dat"
#define AUTOTB_TVOUT_inout_2  "../tv/cdatafile/c.aes16_bidir.autotvout_inout_2.dat"
// wrapc file define: "inout_3"
#define AUTOTB_TVIN_inout_3  "../tv/cdatafile/c.aes16_bidir.autotvin_inout_3.dat"
#define AUTOTB_TVOUT_inout_3  "../tv/cdatafile/c.aes16_bidir.autotvout_inout_3.dat"
// wrapc file define: "iv_0"
#define AUTOTB_TVIN_iv_0  "../tv/cdatafile/c.aes16_bidir.autotvin_iv_0.dat"
#define AUTOTB_TVOUT_iv_0  "../tv/cdatafile/c.aes16_bidir.autotvout_iv_0.dat"
// wrapc file define: "iv_1"
#define AUTOTB_TVIN_iv_1  "../tv/cdatafile/c.aes16_bidir.autotvin_iv_1.dat"
#define AUTOTB_TVOUT_iv_1  "../tv/cdatafile/c.aes16_bidir.autotvout_iv_1.dat"
// wrapc file define: "iv_2"
#define AUTOTB_TVIN_iv_2  "../tv/cdatafile/c.aes16_bidir.autotvin_iv_2.dat"
#define AUTOTB_TVOUT_iv_2  "../tv/cdatafile/c.aes16_bidir.autotvout_iv_2.dat"
// wrapc file define: "iv_3"
#define AUTOTB_TVIN_iv_3  "../tv/cdatafile/c.aes16_bidir.autotvin_iv_3.dat"
#define AUTOTB_TVOUT_iv_3  "../tv/cdatafile/c.aes16_bidir.autotvout_iv_3.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "inout_0"
#define AUTOTB_TVOUT_PC_inout_0  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_inout_0.dat"
// tvout file define: "inout_1"
#define AUTOTB_TVOUT_PC_inout_1  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_inout_1.dat"
// tvout file define: "inout_2"
#define AUTOTB_TVOUT_PC_inout_2  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_inout_2.dat"
// tvout file define: "inout_3"
#define AUTOTB_TVOUT_PC_inout_3  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_inout_3.dat"
// tvout file define: "iv_0"
#define AUTOTB_TVOUT_PC_iv_0  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_iv_0.dat"
// tvout file define: "iv_1"
#define AUTOTB_TVOUT_PC_iv_1  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_iv_1.dat"
// tvout file define: "iv_2"
#define AUTOTB_TVOUT_PC_iv_2  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_iv_2.dat"
// tvout file define: "iv_3"
#define AUTOTB_TVOUT_PC_iv_3  "../tv/rtldatafile/rtl.aes16_bidir.autotvout_iv_3.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			key_0_depth = 0;
			key_1_depth = 0;
			key_2_depth = 0;
			key_3_depth = 0;
			inout_0_depth = 0;
			inout_1_depth = 0;
			inout_2_depth = 0;
			inout_3_depth = 0;
			iv_0_depth = 0;
			iv_1_depth = 0;
			iv_2_depth = 0;
			iv_3_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{key_0 " << key_0_depth << "}\n";
			total_list << "{key_1 " << key_1_depth << "}\n";
			total_list << "{key_2 " << key_2_depth << "}\n";
			total_list << "{key_3 " << key_3_depth << "}\n";
			total_list << "{inout_0 " << inout_0_depth << "}\n";
			total_list << "{inout_1 " << inout_1_depth << "}\n";
			total_list << "{inout_2 " << inout_2_depth << "}\n";
			total_list << "{inout_3 " << inout_3_depth << "}\n";
			total_list << "{iv_0 " << iv_0_depth << "}\n";
			total_list << "{iv_1 " << iv_1_depth << "}\n";
			total_list << "{iv_2 " << iv_2_depth << "}\n";
			total_list << "{iv_3 " << iv_3_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int key_0_depth;
		int key_1_depth;
		int key_2_depth;
		int key_3_depth;
		int inout_0_depth;
		int inout_1_depth;
		int inout_2_depth;
		int inout_3_depth;
		int iv_0_depth;
		int iv_1_depth;
		int iv_2_depth;
		int iv_3_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern "C" void aes16_bidir (
int key[4],
int inout[4],
int iv[4]);

extern "C" void AESL_WRAP_aes16_bidir (
int key[4],
int inout[4],
int iv[4])
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "inout_0"
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_0, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_0, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_inout_0, AESL_token); // data

			sc_bv<32> *inout_0_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_0', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_0', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					inout_0_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_inout_0, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_inout_0))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: inout_0
				{
					// bitslice(31, 0)
					// {
						// celement: inout(31, 0)
						// {
							sc_lv<32>* inout_lv0_0_0_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (0) => (0) @ (2)
							for (int i_0 = 0; i_0 <= 0; i_0 += 2)
							{
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout_lv0_0_0_2[hls_map_index].range(31, 0) = sc_bv<32>(inout_0_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (0) => (0) @ (2)
							for (int i_0 = 0; i_0 <= 0; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : inout[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : inout[0]
								// output_left_conversion : inout[i_0]
								// output_type_conversion : (inout_lv0_0_0_2[hls_map_index]).to_uint64()
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout[i_0] = (inout_lv0_0_0_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] inout_0_pc_buffer;
		}

		// output port post check: "inout_1"
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_1, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_1, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_inout_1, AESL_token); // data

			sc_bv<32> *inout_1_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_1', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_1', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					inout_1_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_inout_1, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_inout_1))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: inout_1
				{
					// bitslice(31, 0)
					// {
						// celement: inout(31, 0)
						// {
							sc_lv<32>* inout_lv0_1_1_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout_lv0_1_1_2[hls_map_index].range(31, 0) = sc_bv<32>(inout_1_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : inout[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : inout[0]
								// output_left_conversion : inout[i_0]
								// output_type_conversion : (inout_lv0_1_1_2[hls_map_index]).to_uint64()
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout[i_0] = (inout_lv0_1_1_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] inout_1_pc_buffer;
		}

		// output port post check: "inout_2"
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_2, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_2, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_inout_2, AESL_token); // data

			sc_bv<32> *inout_2_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_2', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_2', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					inout_2_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_inout_2, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_inout_2))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: inout_2
				{
					// bitslice(31, 0)
					// {
						// celement: inout(31, 0)
						// {
							sc_lv<32>* inout_lv0_2_2_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout_lv0_2_2_2[hls_map_index].range(31, 0) = sc_bv<32>(inout_2_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : inout[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : inout[0]
								// output_left_conversion : inout[i_0]
								// output_type_conversion : (inout_lv0_2_2_2[hls_map_index]).to_uint64()
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout[i_0] = (inout_lv0_2_2_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] inout_2_pc_buffer;
		}

		// output port post check: "inout_3"
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_3, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_inout_3, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_inout_3, AESL_token); // data

			sc_bv<32> *inout_3_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_3', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'inout_3', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					inout_3_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_inout_3, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_inout_3))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: inout_3
				{
					// bitslice(31, 0)
					// {
						// celement: inout(31, 0)
						// {
							sc_lv<32>* inout_lv0_3_3_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout_lv0_3_3_2[hls_map_index].range(31, 0) = sc_bv<32>(inout_3_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: inout(31, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : inout[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : inout[0]
								// output_left_conversion : inout[i_0]
								// output_type_conversion : (inout_lv0_3_3_2[hls_map_index]).to_uint64()
								if (&(inout[0]) != NULL) // check the null address if the c port is array or others
								{
									inout[i_0] = (inout_lv0_3_3_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] inout_3_pc_buffer;
		}

		// output port post check: "iv_0"
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_0, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_0, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_iv_0, AESL_token); // data

			sc_bv<32> *iv_0_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_0', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_0', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					iv_0_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_iv_0, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_iv_0))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: iv_0
				{
					// bitslice(31, 0)
					// {
						// celement: iv(31, 0)
						// {
							sc_lv<32>* iv_lv0_0_0_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (0) => (0) @ (2)
							for (int i_0 = 0; i_0 <= 0; i_0 += 2)
							{
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv_lv0_0_0_2[hls_map_index].range(31, 0) = sc_bv<32>(iv_0_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (0) => (0) @ (2)
							for (int i_0 = 0; i_0 <= 0; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : iv[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : iv[0]
								// output_left_conversion : iv[i_0]
								// output_type_conversion : (iv_lv0_0_0_2[hls_map_index]).to_uint64()
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv[i_0] = (iv_lv0_0_0_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] iv_0_pc_buffer;
		}

		// output port post check: "iv_1"
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_1, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_1, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_iv_1, AESL_token); // data

			sc_bv<32> *iv_1_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_1', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_1', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					iv_1_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_iv_1, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_iv_1))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: iv_1
				{
					// bitslice(31, 0)
					// {
						// celement: iv(31, 0)
						// {
							sc_lv<32>* iv_lv0_1_1_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv_lv0_1_1_2[hls_map_index].range(31, 0) = sc_bv<32>(iv_1_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (1) => (1) @ (2)
							for (int i_0 = 1; i_0 <= 1; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : iv[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : iv[0]
								// output_left_conversion : iv[i_0]
								// output_type_conversion : (iv_lv0_1_1_2[hls_map_index]).to_uint64()
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv[i_0] = (iv_lv0_1_1_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] iv_1_pc_buffer;
		}

		// output port post check: "iv_2"
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_2, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_2, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_iv_2, AESL_token); // data

			sc_bv<32> *iv_2_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_2', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_2', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					iv_2_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_iv_2, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_iv_2))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: iv_2
				{
					// bitslice(31, 0)
					// {
						// celement: iv(31, 0)
						// {
							sc_lv<32>* iv_lv0_2_2_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv_lv0_2_2_2[hls_map_index].range(31, 0) = sc_bv<32>(iv_2_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (2) => (2) @ (2)
							for (int i_0 = 2; i_0 <= 2; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : iv[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : iv[0]
								// output_left_conversion : iv[i_0]
								// output_type_conversion : (iv_lv0_2_2_2[hls_map_index]).to_uint64()
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv[i_0] = (iv_lv0_2_2_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] iv_2_pc_buffer;
		}

		// output port post check: "iv_3"
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_3, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_iv_3, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_iv_3, AESL_token); // data

			sc_bv<32> *iv_3_pc_buffer = new sc_bv<32>[1];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_3', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'iv_3', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					iv_3_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_iv_3, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_iv_3))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: iv_3
				{
					// bitslice(31, 0)
					// {
						// celement: iv(31, 0)
						// {
							sc_lv<32>* iv_lv0_3_3_2 = new sc_lv<32>[1];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv_lv0_3_3_2[hls_map_index].range(31, 0) = sc_bv<32>(iv_3_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: iv(31, 0)
						{
							// carray: (3) => (3) @ (2)
							for (int i_0 = 3; i_0 <= 3; i_0 += 2)
							{
								// sub                    : i_0
								// ori_name               : iv[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : iv[0]
								// output_left_conversion : iv[i_0]
								// output_type_conversion : (iv_lv0_3_3_2[hls_map_index]).to_uint64()
								if (&(iv[0]) != NULL) // check the null address if the c port is array or others
								{
									iv[i_0] = (iv_lv0_3_3_2[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] iv_3_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "key_0"
		char* tvin_key_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_key_0);

		// "key_1"
		char* tvin_key_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_key_1);

		// "key_2"
		char* tvin_key_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_key_2);

		// "key_3"
		char* tvin_key_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_key_3);

		// "inout_0"
		char* tvin_inout_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_inout_0);
		char* tvout_inout_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_inout_0);

		// "inout_1"
		char* tvin_inout_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_inout_1);
		char* tvout_inout_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_inout_1);

		// "inout_2"
		char* tvin_inout_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_inout_2);
		char* tvout_inout_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_inout_2);

		// "inout_3"
		char* tvin_inout_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_inout_3);
		char* tvout_inout_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_inout_3);

		// "iv_0"
		char* tvin_iv_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_iv_0);
		char* tvout_iv_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_iv_0);

		// "iv_1"
		char* tvin_iv_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_iv_1);
		char* tvout_iv_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_iv_1);

		// "iv_2"
		char* tvin_iv_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_iv_2);
		char* tvout_iv_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_iv_2);

		// "iv_3"
		char* tvin_iv_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_iv_3);
		char* tvout_iv_3 = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_iv_3);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_key_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_key_0, tvin_key_0);

		sc_bv<32>* key_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: key_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: key(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : key[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : key[0]
						// regulate_c_name       : key
						// input_type_conversion : key[i_0]
						if (&(key[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> key_tmp_mem;
							key_tmp_mem = key[i_0];
							key_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = key_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_key_0, "%s\n", (key_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_key_0, tvin_key_0);
		}

		tcl_file.set_num(1, &tcl_file.key_0_depth);
		sprintf(tvin_key_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_key_0, tvin_key_0);

		// release memory allocation
		delete [] key_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_key_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_key_1, tvin_key_1);

		sc_bv<32>* key_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: key_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: key(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : key[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : key[0]
						// regulate_c_name       : key
						// input_type_conversion : key[i_0]
						if (&(key[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> key_tmp_mem;
							key_tmp_mem = key[i_0];
							key_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = key_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_key_1, "%s\n", (key_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_key_1, tvin_key_1);
		}

		tcl_file.set_num(1, &tcl_file.key_1_depth);
		sprintf(tvin_key_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_key_1, tvin_key_1);

		// release memory allocation
		delete [] key_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_key_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_key_2, tvin_key_2);

		sc_bv<32>* key_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: key_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: key(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : key[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : key[0]
						// regulate_c_name       : key
						// input_type_conversion : key[i_0]
						if (&(key[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> key_tmp_mem;
							key_tmp_mem = key[i_0];
							key_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = key_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_key_2, "%s\n", (key_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_key_2, tvin_key_2);
		}

		tcl_file.set_num(1, &tcl_file.key_2_depth);
		sprintf(tvin_key_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_key_2, tvin_key_2);

		// release memory allocation
		delete [] key_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_key_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_key_3, tvin_key_3);

		sc_bv<32>* key_3_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: key_3
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: key(31, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : key[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : key[0]
						// regulate_c_name       : key
						// input_type_conversion : key[i_0]
						if (&(key[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> key_tmp_mem;
							key_tmp_mem = key[i_0];
							key_3_tvin_wrapc_buffer[hls_map_index].range(31, 0) = key_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_key_3, "%s\n", (key_3_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_key_3, tvin_key_3);
		}

		tcl_file.set_num(1, &tcl_file.key_3_depth);
		sprintf(tvin_key_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_key_3, tvin_key_3);

		// release memory allocation
		delete [] key_3_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_inout_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_inout_0, tvin_inout_0);

		sc_bv<32>* inout_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_inout_0, "%s\n", (inout_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_inout_0, tvin_inout_0);
		}

		tcl_file.set_num(1, &tcl_file.inout_0_depth);
		sprintf(tvin_inout_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_inout_0, tvin_inout_0);

		// release memory allocation
		delete [] inout_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_inout_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_inout_1, tvin_inout_1);

		sc_bv<32>* inout_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_inout_1, "%s\n", (inout_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_inout_1, tvin_inout_1);
		}

		tcl_file.set_num(1, &tcl_file.inout_1_depth);
		sprintf(tvin_inout_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_inout_1, tvin_inout_1);

		// release memory allocation
		delete [] inout_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_inout_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_inout_2, tvin_inout_2);

		sc_bv<32>* inout_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_inout_2, "%s\n", (inout_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_inout_2, tvin_inout_2);
		}

		tcl_file.set_num(1, &tcl_file.inout_2_depth);
		sprintf(tvin_inout_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_inout_2, tvin_inout_2);

		// release memory allocation
		delete [] inout_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_inout_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_inout_3, tvin_inout_3);

		sc_bv<32>* inout_3_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_3
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_3_tvin_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_inout_3, "%s\n", (inout_3_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_inout_3, tvin_inout_3);
		}

		tcl_file.set_num(1, &tcl_file.inout_3_depth);
		sprintf(tvin_inout_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_inout_3, tvin_inout_3);

		// release memory allocation
		delete [] inout_3_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_iv_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_iv_0, tvin_iv_0);

		sc_bv<32>* iv_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_iv_0, "%s\n", (iv_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_iv_0, tvin_iv_0);
		}

		tcl_file.set_num(1, &tcl_file.iv_0_depth);
		sprintf(tvin_iv_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_iv_0, tvin_iv_0);

		// release memory allocation
		delete [] iv_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_iv_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_iv_1, tvin_iv_1);

		sc_bv<32>* iv_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_iv_1, "%s\n", (iv_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_iv_1, tvin_iv_1);
		}

		tcl_file.set_num(1, &tcl_file.iv_1_depth);
		sprintf(tvin_iv_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_iv_1, tvin_iv_1);

		// release memory allocation
		delete [] iv_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_iv_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_iv_2, tvin_iv_2);

		sc_bv<32>* iv_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_iv_2, "%s\n", (iv_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_iv_2, tvin_iv_2);
		}

		tcl_file.set_num(1, &tcl_file.iv_2_depth);
		sprintf(tvin_iv_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_iv_2, tvin_iv_2);

		// release memory allocation
		delete [] iv_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_iv_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_iv_3, tvin_iv_3);

		sc_bv<32>* iv_3_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_3
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_3_tvin_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_iv_3, "%s\n", (iv_3_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_iv_3, tvin_iv_3);
		}

		tcl_file.set_num(1, &tcl_file.iv_3_depth);
		sprintf(tvin_iv_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_iv_3, tvin_iv_3);

		// release memory allocation
		delete [] iv_3_tvin_wrapc_buffer;

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		aes16_bidir(key, inout, iv);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_inout_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_inout_0, tvout_inout_0);

		sc_bv<32>* inout_0_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_0_tvout_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_inout_0, "%s\n", (inout_0_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_inout_0, tvout_inout_0);
		}

		tcl_file.set_num(1, &tcl_file.inout_0_depth);
		sprintf(tvout_inout_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_inout_0, tvout_inout_0);

		// release memory allocation
		delete [] inout_0_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_inout_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_inout_1, tvout_inout_1);

		sc_bv<32>* inout_1_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_1_tvout_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_inout_1, "%s\n", (inout_1_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_inout_1, tvout_inout_1);
		}

		tcl_file.set_num(1, &tcl_file.inout_1_depth);
		sprintf(tvout_inout_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_inout_1, tvout_inout_1);

		// release memory allocation
		delete [] inout_1_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_inout_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_inout_2, tvout_inout_2);

		sc_bv<32>* inout_2_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_2_tvout_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_inout_2, "%s\n", (inout_2_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_inout_2, tvout_inout_2);
		}

		tcl_file.set_num(1, &tcl_file.inout_2_depth);
		sprintf(tvout_inout_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_inout_2, tvout_inout_2);

		// release memory allocation
		delete [] inout_2_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_inout_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_inout_3, tvout_inout_3);

		sc_bv<32>* inout_3_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: inout_3
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: inout(31, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : inout[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : inout[0]
						// regulate_c_name       : inout
						// input_type_conversion : inout[i_0]
						if (&(inout[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> inout_tmp_mem;
							inout_tmp_mem = inout[i_0];
							inout_3_tvout_wrapc_buffer[hls_map_index].range(31, 0) = inout_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_inout_3, "%s\n", (inout_3_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_inout_3, tvout_inout_3);
		}

		tcl_file.set_num(1, &tcl_file.inout_3_depth);
		sprintf(tvout_inout_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_inout_3, tvout_inout_3);

		// release memory allocation
		delete [] inout_3_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_iv_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_iv_0, tvout_iv_0);

		sc_bv<32>* iv_0_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_0_tvout_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_iv_0, "%s\n", (iv_0_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_iv_0, tvout_iv_0);
		}

		tcl_file.set_num(1, &tcl_file.iv_0_depth);
		sprintf(tvout_iv_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_iv_0, tvout_iv_0);

		// release memory allocation
		delete [] iv_0_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_iv_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_iv_1, tvout_iv_1);

		sc_bv<32>* iv_1_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_1_tvout_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_iv_1, "%s\n", (iv_1_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_iv_1, tvout_iv_1);
		}

		tcl_file.set_num(1, &tcl_file.iv_1_depth);
		sprintf(tvout_iv_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_iv_1, tvout_iv_1);

		// release memory allocation
		delete [] iv_1_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_iv_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_iv_2, tvout_iv_2);

		sc_bv<32>* iv_2_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_2_tvout_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_iv_2, "%s\n", (iv_2_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_iv_2, tvout_iv_2);
		}

		tcl_file.set_num(1, &tcl_file.iv_2_depth);
		sprintf(tvout_iv_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_iv_2, tvout_iv_2);

		// release memory allocation
		delete [] iv_2_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_iv_3, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_iv_3, tvout_iv_3);

		sc_bv<32>* iv_3_tvout_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: iv_3
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: iv(31, 0)
				{
					// carray: (3) => (3) @ (2)
					for (int i_0 = 3; i_0 <= 3; i_0 += 2)
					{
						// sub                   : i_0
						// ori_name              : iv[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : iv[0]
						// regulate_c_name       : iv
						// input_type_conversion : iv[i_0]
						if (&(iv[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> iv_tmp_mem;
							iv_tmp_mem = iv[i_0];
							iv_3_tvout_wrapc_buffer[hls_map_index].range(31, 0) = iv_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_iv_3, "%s\n", (iv_3_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_iv_3, tvout_iv_3);
		}

		tcl_file.set_num(1, &tcl_file.iv_3_depth);
		sprintf(tvout_iv_3, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_iv_3, tvout_iv_3);

		// release memory allocation
		delete [] iv_3_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "key_0"
		delete [] tvin_key_0;
		// release memory allocation: "key_1"
		delete [] tvin_key_1;
		// release memory allocation: "key_2"
		delete [] tvin_key_2;
		// release memory allocation: "key_3"
		delete [] tvin_key_3;
		// release memory allocation: "inout_0"
		delete [] tvin_inout_0;
		delete [] tvout_inout_0;
		// release memory allocation: "inout_1"
		delete [] tvin_inout_1;
		delete [] tvout_inout_1;
		// release memory allocation: "inout_2"
		delete [] tvin_inout_2;
		delete [] tvout_inout_2;
		// release memory allocation: "inout_3"
		delete [] tvin_inout_3;
		delete [] tvout_inout_3;
		// release memory allocation: "iv_0"
		delete [] tvin_iv_0;
		delete [] tvout_iv_0;
		// release memory allocation: "iv_1"
		delete [] tvin_iv_1;
		delete [] tvout_iv_1;
		// release memory allocation: "iv_2"
		delete [] tvin_iv_2;
		delete [] tvout_iv_2;
		// release memory allocation: "iv_3"
		delete [] tvin_iv_3;
		delete [] tvout_iv_3;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

