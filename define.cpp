//there will be a main function which will be the top function which i need to design
#include "ap_fixed.h"
#include "ap_int.h"
#include "layers.h"
#include "common_parameters.h"

void myCNN(input_datatype input[INPUT_WIDTH][INPUT_HEIGHT][NO_OF_CHANNELS],output_datattype OUTPUT[24])
{
	struct configuration layer;
	layer.input_height=48;
	layer.input_width=48;
	layer.no_of_channels=3;
	layer.output_width=46;
	layer.kernel_size=3;
	layer.output_height=46;
	layer.no_of_filters=32;

	Convolution(input,output_layer1,w1,layer);// Normal Convolution Layer Output should be the output of activations

	layer.input_height=46;
	layer.input_width=46;
	layer.no_of_channels=32;
	layer.output_width=44;
	layer.kernel_size=3;
	layer.output_height=44;
	layer.no_of_filters=32;

	Binary_Convolution(output_layer1,output_layer2,w2,layer);//Convolutional

	layer.input_height=44;
	layer.input_width=44;
	layer.no_of_channels=32;
	layer.output_width=42;
	layer.kernel_size=3;
	layer.output_height=42;
	layer.no_of_filters=32;

        Binary_Convloution(output_layer2,output_layer3,w3,layer);

	layer.input_height=4096;
	layer.input_width=0;
	layer.no_of_channels=1;
	layer.output_width=0;
	layer.kernel_size=0;
	layer.output_height=64;
	layer.no_of_filters=1;

	Fully_connected(output_layer3,output_layer4,w4,layer);
	Fully_connected(output_layer4,OUTPUT,w5);	






}
