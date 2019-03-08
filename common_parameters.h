const int INPUT_HEIGHT=48;
const int INPUT_WIDTH=48;
const int KERNEL_SIZE=3;
const int NO_OF_FILTERS=4;
const int FC_OUT=64;
const int FC_IN=128;
const int K=3;
const int OUTPUT_LAYER1_WIDTH;
const int OUTPUT_LAYER1_HEIGTH;
typedef ap_fixed<16,6> input_datatype;
typedef ap_int<1> weight;
typedef ap_int<9> 9bit;
typedef ap_int<1> 1bit;
struct configuration{

	int input_height;
	int input_width;
	int no_of_channels;
	int kernel_size;
	int output_width;
	int output_height;
	

};

