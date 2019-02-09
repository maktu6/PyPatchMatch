CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

FIND_PACKAGE(OpenCV REQUIRED)
include_directories(include)
aux_source_directory(. DIR_LIB_SRCS)
add_compile_options(-fPIC)
add_library (patchmatch STATIC ${DIR_LIB_SRCS})
TARGET_LINK_LIBRARIES(patchmatch ${OpenCV_LIBS})
#MESSAGE(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")



