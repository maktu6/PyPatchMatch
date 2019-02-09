#include <opencv2/opencv.hpp>
extern "C" {
#include "patchmatch.h"
}

cv::Mat inpaintPatchMatch_mat(cv::Mat input_mat, cv::Mat mask_mat, int radius);