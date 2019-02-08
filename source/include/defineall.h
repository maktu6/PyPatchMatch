#ifndef __GLOBAL_INCLUDE_PATCHMATCH_H__
#define __GLOBAL_INCLUDE_PATCHMATCH_H__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <time.h>
#include "structdef.h"
#include "inpaint.h"
#include "maskedimage.h"
#include "nearestneighborfield.h"
#include "qualitymesures.h"
#include "patchmatch.h"

double max1(double a, double b);
double min1(double a, double b);

#endif
