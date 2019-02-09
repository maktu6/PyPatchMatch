#include "inpaint_mat.hpp"
#include <iostream>

cv::Mat inpaintPatchMatch_mat(cv::Mat input_mat, cv::Mat mask_mat, int radius) 
{
    IplImage* output_img=NULL;
    IplImage* input_img = cvCreateImage(cvSize(input_mat.cols, input_mat.rows), 8, 3);
    IplImage ipltemp = input_mat;
    cvCopy(&ipltemp, input_img);
    IplImage* mask_img = cvCreateImage(cvSize(mask_mat.cols, mask_mat.rows), 8, 1);
    ipltemp = mask_mat; 
    cvCopy(&ipltemp, mask_img);

    output_img = inpaintPatchMatch(input_img, mask_img, radius);
    cv::Mat output_mat = cv::Mat(output_img);

    cvReleaseImage(&input_img);
    cvReleaseImage(&mask_img);

    return output_mat;
}

int main()
{
    using namespace cv;
    using namespace std;
    Mat input, mask_rgb, mask, output;
    input = imread("../image_files/forest/forest.bmp");
    mask = imread("../image_files/forest/forest_pruned.bmp", 0);
    // cvtColor(mask_rgb, mask, CV_BGR2GRAY);
    cout << mask.type() << endl;
    cout << mask.rows << endl;
    
    output = inpaintPatchMatch_mat(input, mask, 2);
    
    return 0;
}