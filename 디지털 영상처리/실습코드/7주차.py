# -*- coding: utf-8 -*-
"""
Created on Fri Apr 16 15:04:06 2021

@author: user
"""

from PIL import Image
from skimage.io import imread, imshow, show
import scipy.fftpack as fp
from scipy import ndimage, misc, signal
from skimage import data, img_as_float
from skimage.color import rgb2gray
from skimage.transform import rescale
import matplotlib.pylab as pylab
import numpy as np
import numpy.fft
import timeit

def signaltonoise(a, axis=0, ddof=0):
 a = np.asanyarray(a)
 m = a.mean(axis)
 sd = a.std(axis=axis, ddof=ddof)
 return np.where(sd == 0, 0, m/sd)


im = np.array(Image.open('./images/rhino.jpg').convert('L'))
pylab.figure(figsize=(10,10)), pylab.imshow(im, cmap=pylab.cm.gray), pylab.axis('off'), pylab.show()

freq = fp.fft2(im)
(w, h) = freq.shape
half_w, half_h = int(w/2), int(h/2)
freq1 = np.copy(freq)
freq2 = fp.fftshift(freq1)
pylab.figure(figsize=(10,10)), pylab.imshow( (20*np.log10( 0.1 + freq2)).astype(int)), pylab.show()

# apply HPF
freq2[half_w-20:half_w+21,half_h-20:half_h+21] = 0 # 중간 값을 지운것
pylab.figure(figsize=(10,10))
pylab.imshow( (20*np.log10( 0.1 + freq2)).astype(int))
pylab.show()

im1 = np.clip(fp.ifft2(fp.ifftshift(freq2)).real,0,255) # clip pixel values after IFFT
print(signaltonoise(im1, axis=None))
# 0.5901647786775175
pylab.imshow(im1, cmap='gray'), pylab.axis('off'), pylab.show()