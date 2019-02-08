from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize
import numpy
import sys
import os
import glob

# installation path of OpenCV
SYS_PREFIX = '/usr/local'
lib_folder = os.path.join(SYS_PREFIX, 'lib')

# Find opencv libraries in lib_folder
cvlibs = list()
for file in glob.glob(os.path.join(lib_folder, 'libopencv_*')):
    cvlibs.append(file.split('.')[0])
cvlibs = list(set(cvlibs))
cvlibs = ['opencv_{}'.format(lib.split(os.path.sep)[-1].split('libopencv_')[-1]) for lib in cvlibs]
cvlibs += ['patchmatch']
# print('cvlibs: %s'%cvlibs)
# print('lib_folder: %s'%lib_folder)
setup(
    cmdclass={'build_ext': build_ext},
    ext_modules=cythonize(Extension("patchmatch_inpaint",
                                    sources=["patchmatch_inpaint.pyx", "inpaint_mat.cpp"],
                                    language="c++",
                                    include_dirs=[numpy.get_include(),
                                                  os.path.join(SYS_PREFIX, 'include', 'opencv2'),
                                                  os.path.join(SYS_PREFIX, 'include', 'opencv'),
                                                  'source/include'
                                                 ],
                                    library_dirs=[lib_folder, 'build/source'],
                                    libraries=cvlibs,
                                    )
                          )
)