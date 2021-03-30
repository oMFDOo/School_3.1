import numpy as np
from PIL import Image, ImageFont, ImageDraw
from PIL.ImageChops import add, subtract, multiply, difference, screen
import PIL.ImageStat as stat
from skimage.io import imread, imsave, imshow, show, imread_collection, imshow_collection
from skimage import color, viewer, exposure, img_as_float, data
from skimage.transform import SimilarityTransform, warp, swirl
from skimage.util import invert, random_noise, montage
import matplotlib.image as mpimg
import matplotlib.pylab as plt
from scipy.ndimage import affine_transform, zoom
from scipy import misc


# =============================================================================
# im = Image.open("images/parrot.png") 
# print(im.width, im.height, im.mode, im.format, type(im))
# im.show() 
# 
# im_g = im.convert('L')  
# im_g.save('parrot_gray.png') 
# Image.open("parrot_gray.png").show() 
# =============================================================================

# =============================================================================
# im = mpimg.imread("images/hill.png") 
# print(im.shape, im.dtype, type(im)) 
# plt.figure(figsize=(10,10))
# plt.imshow(im)   
# plt.axis('off'), plt.show()
# 
# im1 = im
# im1[im1 < 0.5] = 0 
# plt.imshow(im1)
# plt.axis('off'), plt.show()
# =============================================================================

# =============================================================================
# im = mpimg.imread("images/lena_small.jpg") 
# methods = ['none', 'nearest', 'bilinear', 'bicubic', 'spline16', 'lanczos']
# fig, axes = plt.subplots(nrows=2, ncols=3, figsize=(15, 12),
#                              subplot_kw={'xticks': [], 'yticks': []})
# fig.subplots_adjust(hspace=0.05, wspace=0.05)
# for ax, interp_method in zip(axes.flat, methods):
#     ax.imshow(im, interpolation=interp_method)
#     ax.set_title(str(interp_method), size=20)
# plt.tight_layout(), plt.show()
# =============================================================================

# =============================================================================
# im = data.astronaut()
# imshow(im) 
# show()
# =============================================================================

# =============================================================================
# im = misc.face() # load the raccoon's face image
# imsave('face.png', im) # uses the Image module (PIL)
# plt.imshow(im)
# plt.axis('off') 
# plt.show()
# =============================================================================

# =============================================================================
# import imageio
# im = imageio.imread('./images/pepper.jpg')
# print(type(im), im.shape, im.dtype)
# plt.imshow(im), plt.axis('off'), plt.show()
# =============================================================================











