# -*- coding: utf-8 -*-
"""
Created on Tue Jun  8 01:11:26 2021

@author: user
"""

#%% 11주차 3번 강의 - 미분

import numpy as np
from skimage import data, img_as_float, img_as_ubyte, exposure, io, color
from skimage.io import imread
from skimage.exposure import cumulative_distribution
from skimage.restoration import denoise_bilateral, denoise_nl_means, estimate_sigma
from skimage.measure import compare_psnr
from skimage.util import random_noise
from skimage.color import rgb2gray
from PIL import Image, ImageEnhance, ImageFilter
from scipy import signal, misc, ndimage
import matplotlib.pylab as pylab
import matplotlib.pylab as plt

def plot_image(image, title):
    pylab.imshow(image), pylab.title(title, size=20), pylab.axis('off')
    
    
#%% Derivatives and gradients
    
# 미분을 해보았어요!
    
ker_x = [[-1, 1]]
ker_y = [[-1], [1]]
im = rgb2gray(imread('./images/chess.png'))
im_x = signal.convolve2d(im, ker_x, mode='same')
im_y = signal.convolve2d(im, ker_y, mode='same')
im_mag = np.sqrt(im_x**2 + im_y**2)
im_dir = np.arctan(im_y/im_x)
pylab.gray()
pylab.figure(figsize=(30,20))
pylab.subplot(231), plot_image(im, 'original'), pylab.subplot(232),
plot_image(im_x, 'grad_x') # x축 미분값
pylab.subplot(233), plot_image(im_y, 'grad_y'), pylab.subplot(234), # y축 미분값
plot_image(im_mag, '||grad||') # 그레디언트의 크기
pylab.subplot(235), plot_image(im_dir, r'$\theta$'), pylab.subplot(236)
pylab.plot(range(im.shape[1]), im[0,:], 'b-', label=r'$f(x,y)|_{x=0}$', linewidth=5) # 탄젠트 세타값
pylab.plot(range(im.shape[1]), im_x[0,:], 'r-', label=r'$grad_x (f(x,y))|_{x=0}$') # 값변화를 그려봄
pylab.title(r'$grad_x (f(x,y))|_{x=0}$', size=30)
pylab.legend(prop={'size': 20})
pylab.show()

#%% Displaying the magnitude and the gradient on the same image

# 진짜 이미지에 미분을 적용해보았어요!

# 커널 설정
ker_x = [[-1, 1]]   # 2차미분 적용 f(x + 1) - f(x - 1) 
ker_y = [[-1], [1]] # 2차미분 적용 f(x + 1) - f(x - 1) 
im = rgb2gray(imread('./images/tiger3.jpg'))
#im = random_noise(im, var=sigma**2)
#im = gaussian(im, sigma=0.25)
print(np.max(im))
# 와! 컨볼루션!  mode='same' : 결과값의 크기를 같게 하겠다.
im_x = np.clip(signal.convolve2d(im, ker_x, mode='same'),0,1)
im_y = np.clip(signal.convolve2d(im, ker_y, mode='same'),0,1)
im_mag = np.sqrt(im_x**2 + im_y**2)
im_ang = np.arctan(im_y/im_x)
plt.gray()
plt.figure(figsize=(20,30))
plt.subplot(321)
plt.imshow(im)
plt.title('original', size=30)
plt.axis('off')
plt.subplot(322)
plt.imshow(im_x)
plt.title('grad_x', size=30)
plt.axis('off')
plt.subplot(323)
plt.imshow(im_y)
plt.title('grad_y', size=30)
plt.axis('off')
plt.subplot(324)
plt.imshow(im_mag)
plt.title('||grad||', size=30)
plt.axis('off')
plt.subplot(325)
plt.imshow(im_ang)
plt.title(r'$\theta$', size=30)
plt.axis('off')
plt.subplot(326)
im = np.zeros((im.shape[0],im.shape[1],3))
im[...,0] = im_mag*np.sin(im_ang)
im[...,1] = im_mag*np.cos(im_ang)
plt.imshow(im)
plt.title(r'||grad||+$\theta$', size=30)
plt.axis('off')
plt.show()

#%% Laplacian
#라플라시안

# 십자형태(+)로 값적혀 있던 거 그대로 써서 커널 설정
ker_laplacian = [[0,-1,0],[-1, 4, -1],[0,-1,0]]

im = rgb2gray(imread('./images/chess.png'))
im1 = np.clip(signal.convolve2d(im, ker_laplacian, mode='same'),0,1)
pylab.gray()
pylab.figure(figsize=(20,10))
pylab.subplot(121), plot_image(im, 'original')
pylab.subplot(122), plot_image(im1, 'laplacian convolved')
pylab.show()