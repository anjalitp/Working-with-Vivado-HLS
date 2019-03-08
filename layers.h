ck,#include "common_parameters.h"

int find_hammingweight(int value)
{
    int sum=0;
  //  cout<<"First four bits"<<hamming_weight[value&0xF]<<"Middle one bit"<<hamming_weight[(value>>4)&1];
  //  cout<<"last 4 bits"<<hamming_weight[value>>1];
    while(value>1)
    {
      sum=hamming_weight[value&0xF]+sum;
      //cout<<(value&0xF)<<"value"<<endl;
      value=value>>4;
  //    cout<<sum<<" ";
    //  cout<<"value"<<value;
    }
    sum+=value;
   //cout<<sum;
return sum;
}


void Convolution(input_datatype input[layer.input_width],output[layer.output_width],weight,configuration layer)
{

	input:for(int i=0;i<OUTPUT_LAYER1_WIDTH;++i){
		for(int j=0;j<OUTPUT_LAYER1_HEIGHT;++j){
	filter:	 for(int t=0;t<3;++t){
			int sum=0;
	kernel:	     	for(int ki=0;ki<KERNEL_SIZE;++ki){
			       int kj=0;

				while(kj<KERNEL_SIZE)
			       {
				 if(weight[NO_OF_FILTERS*t+ki*K+kj)
				 sum=sum+input_G[(i+ki)*INPUT_WIDTH+j+kj]*weight[NO_OF_FILTERS*t+ki*K+kj];
				else
				 sum=sum-input_G[(i+ki)*INPUT_WIDTH+j+kj]*weight[NO_OF_FILTERS*t+ki*K+kj];
				 
				 ++kj;
			       }
			}

		}
	}
	

}
void Binary_Convolution(input_datatype input[INPUT_WIDTH],output[OUTPUT_LAYER1],weight)
{
	int index=0;
	input:for(int i=0;i<OUTPUT_LAYER1_WIDTH;++i){
		for(int j=0;j<OUTPUT_LAYER1_HEIGHT;++j){
	filter:	 for(int t=0;t<3;++t){
			9bit sum=0;
	kernel:	     	for(int ki=0;ki<KERNEL_SIZE;++ki){
			       int kj=0;

				while(kj<KERNEL_SIZE)
			       {
				
				1bit temp=nput_G[(i+ki)*INPUT_WIDTH+j+kj]^weight[NO_OF_FILTERS*t+ki*K+kj];
				sum=sum|1;
				sum=sum<<1;				 
				 ++kj;
			       }
			}
			output[index++]=hamming_weight(sum);

		}
	}
	

}


void Fully_Connected_Layer(int *input,int* weight,int *output)
{
  int index=-1;

  for(int i=0;i<FC_OUT;++i)
  { output[++index]=0;
    int sum=0;
    for(int j=0;j<FC_IN;++j)
     {
        sum=input[i]^weight[i*FX_+j];
        if(sum==1)
        sum=sum<<1;
        //cout<<sum<<endl;

     }
    // cout<<find_hammingweight(sum)<<" ";
     output[index]+=find_hammingweight(sum);
  //  cout<<output[index]<<endl;

  }

}

void batchNormalization()
{





}


