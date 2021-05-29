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
# with open('/home/diva2/diva2/GroundStation/AlgorithmTesting/Algorithm/checkpoints/fcn_big_01.json', 'r') as model_file:
#     test_model = model_from_json(model_file.read())
# model_path = sys.argv[1]
model_path = './checkpoints/fcn_big_01.json'
with open(model_path, 'r') as model_file:
    test_model = model_from_json(model_file.read())
test_model.summary()


# In[6]:
## Get Weights 
# test_model.load_weights('./checkpoints/fcn_big_01.h5')
test_model.load_weights('/home/diva2/diva2/GroundStation/AlgorithmTesting/Algorithm/checkpoints/fcn_big_01.h5')
# test_model.load_weights(sys.argv[2])


# In[8]:
## Load Test Images

# test_folder = sys.argv[3] # './training_images/'
test_folder = '/home/diva2/diva2/GroundStation/AlgorithmTesting/Algorithm/training_images/'

# test_folder = './training_images/'
from PIL import Image
dirs = os.listdir( test_folder )
dirs.sort()
x_train=[]
def load_dataset():
    cnt = 0
    # Append images to a list
    for item in dirs:
        cnt = cnt + 1
        if os.path.isfile(test_folder+item):
            im = Image.open(test_folder+item).convert("RGB")
            # print(im.width, im.height)
            im = im.resize((400, 144), resample=0)
            # print(im.width, im.height)
            im = np.array(im)
            x_train.append(im)
    return cnt

count = load_dataset()
print(count)

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
        
        img = cv2.resize(pred[0], frameSize)        
        out.write(img.astype('uint8') * 255)
        
        # plt.figure(1); plt.clf()
        # plt.imshow(pred[0])
        # plt.title(windowName)
        # plt.pause(0.1)
        cv2.imshow('result', img)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break


        ## ================== Accuracy ==================== ##    
        # scores = []
        # lines = []
        # for i in range(0, width):
        #     score = 0.0

        #     y_start_point = 0
        #     y_end_point = height
            
        #     # np.random.nomral 함수를 이용해서 평균 0, 표준편차 0.1인 sample들을 1000개 추출한다.
        #     mean, sigma = 0, 0.1 # mean and standard deviation
        #     Gaussian_sample = np.random.normal(mean, sigma, 1)
        #     x_start_point = width/2 + Gaussian_sample
        #     Gaussian_sample = np.random.normal(mean, sigma, 1)
        #     x_end_point = width/2 + Gaussian_sample
            
        #     slope = (x_end_point - x_start_point) / height
            
        #     for j in range(0, height):
        #         x_current = x_start_point + j * slope
        #         # score += intensity_value_at(j,x_current)
        #         #print('x_current.shape:', x_current.shape)
        #         #print('j=',j,',  x_current=', x_current[0])
        #         #print('img = ', img[j,x_current[0]])
        #         x_current = x_current[0].astype(int)
        #         #print('x_current.shape:', x_current.shape)
        #         #print('j=',j,',  x_current=', x_current)
        #         score += img[j,x_current]
        #     lines.append([slope, x_start_point])
        #     scores.append(score)
        
        # # sort(vector_of_lines.begin(), vector_of_lines.end(), compare_score)
        # zipped_lists = zip(lines, scores)
        # sorted_zipped_lists = sorted(zipped_lists)
        # sorted_lines = [element for _, element in sorted_zipped_lists]
        
        # for i in range(0, 2):
        #     print('score(',i,')/lines(',0,') : ', scores[i], sorted_lines[i])
        # # return line_with_highest_score
        
        # image = np.zeros((height, width), np.float32)
        # image = cv2.cvtColor(image, cv2.COLOR_GRAY2RGB)
        # cv2.line(image, pt1, pt2, color=(255,0,255), thickness=5)
        # cv2.imshow('result', img)
        # if cv2.waitKey(1) & 0xFF == ord('q'):
        #     break
        ## ================== Accuracy END ==================== ##    
        

    out.release()
    cv2.destroyAllWindows()
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



