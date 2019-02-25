from keras.datasets import mnist
from keras.preprocessing.image import ImageDataGenerator
from matplotlib import pyplot
import os
import h5py
from pre_processing import image_preprocess
from keras import backend  as K
K.set_image_dim_ordering('th')
root_dir = 'FACEDATA/Training/Images/'
image_preprocess(root_dir)
with  h5py.File('FaceData.h5') as hf:
    X_train, Y_train = hf['imgs'][:], hf['labels'][:]
    print("Successfully loaded images from FaceData.h5")
X_train=X_train.reshape(X_train.shape[0],3,128,128)
'''(X_train,y_train),(X_test,y_test)=mnist.load_data()

X_test=X_test.reshape(X_test.shape[0],1,28,28)
X_train= X_train.astype('float32')
X_test= X_test.astype('float32')
'''
datagen=ImageDataGenerator()
datagen.fit(X_train)
os.makedirs('images_face')
for X_batch,y_batch in datagen.flow(X_train,Y_train,batch_size=9,save_to_dir='images_face',save_prefix='aug',save_format='png'):
    print("hello")
'''    for i in range(0, 9):
        pyplot.subplot(330 + 1 + i)
        pyplot.imshow(X_batch[i].reshape(28, 28), cmap=pyplot.get_cmap('gray'))
        pyplot.show()
        break
'''
