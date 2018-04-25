#ifndef __IMAGE_PROCESSING_H__
#define __IMAGE_PROCESSING_H__

#include "header.h"
#include "image_processing.h"

void get_hsv_mask(const Mat &hsv, Mat &mask, bool blue, bool red, bool black, bool white);
void hist_equalize(Mat &img);


#endif