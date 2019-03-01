from keras.models import Sequential
from keras.layers.core import Dense,Activation
from keras.layers.convolutional import Convolution2D
import keras

model = Sequential()
model.add(Dense(4,name='dense1', use_bias=False,input_dim=2))
model.add(Activation('relu',name='relu1'))
model.add(Dense(10, activation='relu',use_bias=0,name='final_layer'))
model.compile(optimizer='rmsprop',
              loss='categorical_crossentropy',
              metrics=['accuracy'])

# Generate dummy data
import numpy as np
data = np.random.random((1000, 2))
labels = np.random.randint(10, size=(1000, 1))

# Convert labels to categorical one-hot encoding
one_hot_labels = keras.utils.to_categorical(labels, num_classes=10)

# Train the model, iterating on the data in batches of 32 samples
model.fit(data, one_hot_labels, epochs=10, batch_size=32)
print(model.get_layer('dense1').get_weights()[0])
weight_layer1=model.get_layer('dense1').get_weights()[0]
#weight_layer2=model.get_layer('relu1').get_activations()[0]

weight_layer3=model.get_layer('final_layer').get_weights()[0]

weight_layer1_array=[]
weight_layer3_array=[]
print("Storing the weights of layer 1")

for i in weight_layer1 :
    for j in i:
            weight_layer1_array.append(j)

print("Storing the weights of Layer 3")
for i in weight_layer3 :
    for j in i:
            weight_layer3_array.append(j)

input_for_prediction =np.array([1,2])
input_for_prediction=np.reshape(input_for_prediction,(1,2))
print("Model output for input 1 and 2")
print(model.predict(input_for_prediction))
i_model=keras.Model(inputs=model.input,outputs=model.get_layer('final_layer').output);
r=i_model.predict(input_for_prediction)

print("Answer computed by the CNN is given by",r)
print("Printing theweight array",weight_layer1_array)
output=[0,0,0,0]
input=[1,2]
FC_IN=2
FC_OUT=4
for i in range (0,FC_OUT):
    for j in range(0,FC_IN):
        #print("input=",input[j],"output=",output[i],"weight=",weight_layer1_array[i+(j*2)])
        output[i]=output[i]+(input[j]*weight_layer1_array[i+(j*FC_OUT)])
                #print("input=",input[j],"output=",output[i],"weight=",weight_layer1_array[i+(j*2)])
print("Final output of layer 1",output)
for i in range(0,FC_OUT):
        if (output[i]<0):
            output[i]=float(0)
print("Final output of layer 2",output)
output_1=[0,0,0,0,0,0,0,0,0,0]
print("Final Layer weights",weight_layer3_array)
for i in range (0,10):
    for j in range(0,4):
        #print("input=",input[j],"output=",output[i],"weight=",weight_layer1_array[i+(j*2)])
        output_1[i]=output_1[i]+(output[j]*weight_layer3_array[i+(j*10)])
        #print("input=",input[j],"output=",output[i],"weight=",weight_layer1_array[i+(j*2)])
for i in range(0,10):
        if (output_1[i]<0):
            output_1[i]=float(0)
print("Final Output=",output_1)


#Moving on to CNN Model
CNNModel=Sequential()
CNNModel.add(Convolution2D(1,(3,3),input_shape=(3,4,4),name='layer1',data_format='channels_first'))
# Generate dummy data
import numpy as np
data_convolution = np.random.random((1000,48))
data_convolution= np.resize(data_convolution,(1000,3,4,4))
labels = np.random.randint(10, size=(1000, 1))
CNNModel.compile(optimizer='rmsprop',
              loss='categorical_crossentropy',
              metrics=['accuracy'])
CNNModel.fit(data_convolution, one_hot_labels, epochs=10, batch_size=32)
