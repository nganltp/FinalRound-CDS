#ifndef __HEADER_H__
#define __HEADER_H__

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/ml.hpp>

#include "api_kinect_cv.h"
#include "api_i2c_pwm.h"
#include "multilane.h"
#include "Hal.h"
#include "LCDI2C.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <thread>
#include <mutex>
#include <pthread.h>

using namespace openni;
using namespace EmbeddedFramework;
using namespace cv;
using namespace std;
using namespace cv::ml;

#define LOW_HSV_BLUE Scalar(104, 148, 55)
#define HIG_HSV_BLUE Scalar(118, 255, 255)

#define LOW_HSV_RED1 Scalar(0, 80, 100)
#define HIG_HSV_RED1 Scalar(5, 255, 255)
#define LOW_HSV_RED2 Scalar(170, 80, 100)
#define HIG_HSV_RED2 Scalar(180, 255, 255)

#define LOW_HSV_GREEN Scalar(34, 80, 100)
#define HIG_HSV_GREEN Scalar(83, 255, 255)

#define GREEN_MIN Scalar(34, 138, 12)
#define GREEN_MAX Scalar(83, 246, 124)

#define LOW_HSV_BLACK Scalar(0, 0, 0)
#define HIG_HSV_BLACK Scalar(255, 240, 183)

#define KERNEL_SIZE 3
#define SIGN_SIZE 32
#define DIF_RATIO_SIGN_WIDTH_PER_HEIGHT 0.2
#define DIF_RATIO_SIGN_AREA 0.1
#define MIN_SIGN_AREA 1800

#define SAMPLE_READ_WAIT_TIMEOUT 1
#define FRAME_WIDTH 320
#define FRAME_HEIGHT 240
#define TEST_DETECT_SIGN 0
#define ACCEPT_SIGN 1
#define N_SAMPLE 1
#define ALPHA 2.0

#define SW1_PIN 160
#define SW2_PIN 161
#define SW3_PIN 163
#define SW4_PIN 164
#define SENSOR 165
#define AREA_MIN 100
#define RATIO_WIDTH_LANE_CROP 1
#define RATIO_HEIGHT_LANE_CROP 0.35
#define CENTER_POINT_Y 0.2

#define NO_SIGN 0
#define SIGN_LEFT 1
#define SIGN_RIGHT 2
#define SIGN_STOP 3

#define KI 0.3
#define KP 0.1
#define KD 0.01

#define THROTTLE_VAL1 35
#define THROTTLE_VAL2 45

#endif
