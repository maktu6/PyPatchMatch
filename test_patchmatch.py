import patchmatch_inpaint as pmi
from skimage import io

input = io.imread('image_files/forest/forest.bmp')
mask = io.imread('image_files/forest/forest_pruned.bmp')
output = pmi.PyPatchMatch_inpaint(input, mask[:,:,0], 1)
print("Done！")