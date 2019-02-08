#include "patchmatch.h"

IplImage* inpaintPatchMatch(IplImage* input_img, IplImage* maskimage, int radius) 

{
	uchar* data;
	CvSize size;
	double height,width;

	IplImage* output_img=NULL;

	size = cvGetSize(input_img);
	height=size.height;
	width=size.width;

	int channels=maskimage->nChannels;
	int step = maskimage->widthStep/sizeof(uchar);
	int ** mask;
	mask = (int **) calloc((int)(height),sizeof(int*));
    for ( int i=0 ; i<height ; i++)
		mask[i] = (int *) calloc((int)(width),sizeof(int));

	data = (uchar *)maskimage->imageData;
    for ( int i = 0 ; i < height ; ++i )
        for ( int j = 0 ; j < width ; ++j )
            if ( data[i*step+j*channels]==1 )
				mask[i][j]=1;	   


		Inpaint_P inp = initInpaint();
		output_img = inpaint(inp, input_img, (int**)mask, radius);
		
	for( int i = 0 ; i < height ; ++i)
		free(mask[i]);
	free(mask);

		return output_img;
}
