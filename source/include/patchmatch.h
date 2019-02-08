#ifndef __INPAINT_H_
#define __INPAINT_H_

#ifdef __cplusplus 
extern "C" {
#endif
#include "defineall.h"
#include "patchmatch.h"
#include "inpaint.h"
IplImage* inpaintPatchMatch(IplImage* input_img, IplImage* maskimage, int radius);
#ifdef __cplusplus
}
#endif


// Variables globales
extern double* G_globalSimilarity;
extern int G_initSim;
#endif