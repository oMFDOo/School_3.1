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
# im = Image.open("images/lena.jpg")
# im1 = im.copy() 
# n = 5000
# x, y = np.random.randint(0, im.width, n), np.random.randint(0, im.height,n)
# for (x,y) in zip(x,y):
#     im1.putpixel((x, y), 
#                    ((0,0,0) if np.random.rand() < 0.5 else (255,255,255)))
#     # salt-and-pepper noise
# im1.show()
# =============================================================================

# =============================================================================
# im = Image.open("images/parrot.png")
# draw = ImageDraw.Draw(im)
# draw.ellipse((125, 125, 200, 250), fill=(255,255,255,128))
# font = ImageFont.truetype("Arial Unicode.ttf", 23)
# draw.text((10, 5), "Welcome to image processing with python", font=font)
# del draw
# im.show()
# =============================================================================

# =============================================================================
# # im = Image.open("images/parrot.png")
# im_thumbnail = im.copy() # need to copy the original image first
# im_thumbnail.thumbnail((100,100)) # now paste the thumbnail on the image
# im.paste(im_thumbnail, (10,10))
# im.save("parrot_thumb.jpg")
# im.show()
# =============================================================================

# =============================================================================
# im = Image.open("images/parrot.png")
# s = stat.Stat(im)
# print(s.extrema) # maximum and minimum pixel values for each channel R, G, B
# print(s.count)
# print(s.mean)
# print(s.median)
# print(s.stddev)
# 
# pl = im.histogram()
# plt.bar(range(256), pl[:256], color='r', alpha=0.5)
# plt.bar(range(256), pl[256:2*256], color='g', alpha=0.4)
# plt.bar(range(256), pl[2*256:], color='b', alpha=0.3)
# plt.show()
# =============================================================================

# =============================================================================
# im = Image.open("images/parrot.png")
# ch_r, ch_g, ch_b = im.split() 
# plt.figure(figsize=(18,6))
# plt.subplot(1,3,1); plt.imshow(ch_r, cmap=plt.cm.Reds); plt.axis('off')
# plt.subplot(1,3,2); plt.imshow(ch_g, cmap=plt.cm.Greens); plt.axis('off')
# plt.subplot(1,3,3); plt.imshow(ch_b, cmap=plt.cm.Blues); plt.axis('off')
# plt.tight_layout()
# plt.show()
# =============================================================================












