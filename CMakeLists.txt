PROJECT(patchmatch_mat)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

FIND_PACKAGE( OpenCV REQUIRED )
include_directories(source/include)
add_subdirectory (source)
set (EXTRA_LIBS ${EXTRA_LIBS} patchmatch)
# Declare the target (an executable)
ADD_EXECUTABLE(patchmatch_mat inpaint_mat.cpp)
#add_library (patchmatch_mat SHARED inpaint_mat)

TARGET_LINK_LIBRARIES(patchmatch_mat ${OpenCV_LIBS} ${EXTRA_LIBS})

#MESSAGE(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")



