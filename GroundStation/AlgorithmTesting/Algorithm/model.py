#!/usr/bin/env python
# coding: utf-8

# In[1]:
## Import Libraries

from tensorflow.keras.layers import Conv2D, MaxPool2D, Dropout, UpSampling2D, Input, Lambda, Conv2DTranspose, concatenate
from classification_models.tfkeras import Classifiers
from tensorflow.keras.models import Sequential
from tensorflow.keras import Model

import numpy as np
import time
import cv2
import os
import sys

import matplotlib.pyplot as plt
import imageio


# In[2]:
## Define a Function to Count a Time Interval

def millis():
    return int(time.time() * 1000)



# In[4]:
## Get Model

from tensorflow.keras.models import model_from_json

# with open('./checkpoints/fcn_big_01.json', 'r') as model_file:
#     test_model = model_from_json(model_file.read())
with open(sys.argv[1], 'r') as model_file:
    test_model = model_from_json(model_file.read())

test_model.summary()


# In[6]:
## Get Weights 

# test_model.load_weights('./checkpoints/fcn_big_01.h5')
test_model.load_weights(sys.argv[2])


# In[8]:
## Load Test Images

test_folder = './training_images/'
from PIL import Image
dirs = os.listdir( test_folder )
dirs.sort()
x_train=[]
def load_dataset():
    # Append images to a list
    for item in dirs:
        if os.path.isfile(test_folder+item):
            im = Image.open(test_folder+item).convert("RGB")
            # print(im.width, im.height)
            im = im.resize((400, 144), resample=0)
            # print(im.width, im.height)
            im = np.array(im)
            x_train.append(im)

load_dataset()

width, height = 1280, 720

images = np.array(x_train)

def apply_to_image():

    windowName = "result"
    # cv2.namedWindow(windowName, cv2.WINDOW_NORMAL)
    frameSize = (width, height)
    out = cv2.VideoWriter('output_video.avi', cv2.VideoWriter_fourcc(*'DIVX'), 60, frameSize, False)

    for image in images:
        image.resize((144,400,3))
        pred = test_model.predict(np.expand_dims(image, 0))
        
        # img = cv2.cvtColor(pred[0], cv2.COLOR_GRAY2BGR)
        img = cv2.resize(pred[0], frameSize)        
        out.write(img.astype('uint8') * 255)
        # plt.figure(1); plt.clf()
        # plt.imshow(pred[0])
        # plt.title(windowName)
        # plt.pause(0.1)
    out.release()
    # plt.show()


apply_to_image()



# In[25]:
## Predict the Model with Test Image

## Show the Result
# plt.figure(figsize=(15, 15))
# plt.subplot(2, 1, 1)
# plt.imshow(image)
# plt.subplot(2, 1, 2)
# plt.imshow(pred[0])

## Save the result : original image (output1), processed image (output2)
# plt.imsave("output1.png", image)
# imageio.imwrite('output2.png', pred[0])


# In[32]:
## Calculate a Prediction Time

start_mil = millis()
predict_count = 100
image = np.random.random((1, 144, 400, 3))
for i in range(predict_count):
    pred = test_model.predict(image)
stop_mil = millis()
print('Prediction took {} millis'.format((stop_mil - start_mil)//predict_count))



