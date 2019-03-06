//there will be a main function which will be the top function which i need to design
#include "ap_fixed.h"
#include "ap_int.h"
#include "layers.h"
#include "common_parameters.h"

void myCNN(input_datatype input[INPUT_WIDTH][INPUT_HEIGHT][NO_OF_CHANNELS],output_datattype OUTPUT[24])
{
	Convolution(input,output_layer1,w1);// Normal Convolution Layer Output should be the output of activations
	Binary_Convolution(output_layer1,output_layer2,w2);//Convolutional
        Binary_Convloution(output_layer2,output_layer3,w3);
	Fully_connected(output_layer3,output_layer4,w4);
	Fully_connected(output_layer4,OUTPUT,w5);	






}
