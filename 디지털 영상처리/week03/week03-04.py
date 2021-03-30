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
# 
# im = Image.open('images/flowers.png') # read image into an Image object with PIL
# im = np.array(im) # create a numpy ndarray from the Image object
# imshow(im) # use skimage imshow to display the image
# plt.axis('off'), show()
# =============================================================================

# =============================================================================
# im = imread('images/flowers.png') # read image into numpy ndarray with skimage
# im = Image.fromarray(im) # create a PIL Image object from the numpy ndarray
# im.show() # display the image with PIL Image.show() method
# =============================================================================


# =============================================================================
# lena = mpimg.imread("images/lena.jpg") # read the image as a numpy ndarray
# lena = lena.copy()
# lena[0][0] = 12
# lx, ly, _ = lena.shape
# X, Y = np.ogrid[0:lx, 0:ly]
# mask = (X - lx / 2) ** 2 + (Y - ly / 2) ** 2 > lx * ly / 4
# lena[mask,:] = 0 
# plt.figure(figsize=(10,10))
# plt.imshow(lena), plt.axis('off'), plt.show()
# =============================================================================


# =============================================================================
# im = Image.open("images/parrot.png")
# print(im.mode) # RGB
# im.save("parrot.jpg")
# =============================================================================

# =============================================================================
# im = Image.open("images/hill.png")
# print(im.mode) # RGBA
# im.convert('RGB').save("hill.jpg")
# =============================================================================

# =============================================================================
# im = imread("images/Ishihara.png")
# im_g = color.rgb2gray(im)
# plt.subplot(121), plt.imshow(im, cmap='gray'), plt.axis('off')
# plt.subplot(122), plt.imshow(im_g, cmap='gray'), plt.axis('off')
# plt.show()
# =============================================================================


# =============================================================================
# im1 = mpimg.imread("images/messi.jpg") / 255 # scale RGB values in [0,1]
# im2 = mpimg.imread("images/ronaldo.jpg") / 255
# i = 1
# plt.figure(figsize=(18,15))
# for alpha in np.linspace(0,1,20):
#     plt.subplot(4,5,i)
#     plt.imshow((1-alpha)*im1 + alpha*im2)
#     plt.axis('off')
#     i += 1
# plt.subplots_adjust(wspace=0.05, hspace=0.05)
# plt.show()
# =============================================================================






