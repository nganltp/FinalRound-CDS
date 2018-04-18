#include "lane_detection.h"

// My function
void filterLane(const Mat &imgLane, bool &isLine, int &centerX, int check)
{
    isLine = false;
    if (check < 0) // Left
    	centerX = 0;
	else // Right
        centerX = imgLane.cols;

    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(imgLane, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    
    if (contours.size() == 0)
        return;
    
    Mat result = Mat::zeros(imgLane.size(), CV_8UC1);
    
    for (int i = 0; i < (int)contours.size(); ++i)
    {
        int area = contourArea(contours[i]);
        if (area >= AREA_MIN)
        {
            drawContours(result, contours, i, Scalar(255), CV_FILLED);
            isLine = true;
            if (check < 0) // Left
            {
                // Find the most right vertice (xmax)
                for (int j = 0; j < contours[i].size(); ++j)
                    if (contours[i][j].x > centerX)
                        centerX = contours[i][j].x;
            }
            else // Right
            {
                for (int j = 0; j < contours[i].size(); ++j)
                {
                    // Find the most left vertice (xmin)
                    if (contours[i][j].x < centerX)
                        centerX = contours[i][j].x;
                }	
            }
        }
    }
    // Line found
    result.copyTo(imgLane);
}

void LaneProcessing(Mat& colorImg, Mat& binImg, Point &centerPoint, Point &centerLeft, Point &centerRight, int &space) 
{
   
    // Define rect to crop binImg into Left and Right
    int xLeftRect = 0;
    int yLeftRect = (1 - RATIO_HEIGHT_LANE_CROP) * binImg.rows;
    int xRightRect = (1.5 - RATIO_WIDTH_LANE_CROP) * binImg.cols;
    int yRightRect = (1 - RATIO_HEIGHT_LANE_CROP) * binImg.rows;
    int widthRect = RATIO_WIDTH_LANE_CROP * binImg.cols / 2;
    int heightRect = RATIO_HEIGHT_LANE_CROP * binImg.rows;
    
    Rect rectLeft(xLeftRect, yLeftRect, widthRect, heightRect);
    Rect rectRight(xRightRect, yRightRect, widthRect, heightRect);
    Mat binLeft = binImg(rectLeft);
    Mat binRight = binImg(rectRight);
    
    // Keep lanes
    //binLeft = keepLanes(binLeft, false);
    //binRight = keepLanes(binRight, false);

    bool isLeft = false;
    bool isRight = false;
    
    // Filter lanes
    Point preCenterLeft = centerLeft;
    Point preCenterRight = centerRight;
    filterLane(binLeft, isLeft, centerLeft.x, -1);
    filterLane(binRight, isRight, centerRight.x, 1);
    
    imshow("LEFT", binLeft);
    imshow("RIGHT", binRight);
    cout << "Left: " << isLeft << " Right: " << isRight << endl;
  /* OLd  
    if (isLeft)
        centerLeft.x += xLeftRect;
    else // Lose center point => get the previous
    {
        putText(colorImg, "No left", Point(60, 100), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255, 255, 0), 1, CV_AA);
        centerLeft.x = preCenterLeft.x;
    }
    if (isRight)
        centerRight.x += xRightRect;
    else // Lose center point => get the previous
    {
        putText(colorImg, "No right", Point(200, 100), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255, 255, 0), 1, CV_AA);
        centerRight.x = preCenterRight.x;
    }
    
    // Backup
    
    centerPoint.x = (centerLeft.x + centerRight.x) / 2;
    centerPoint.y = centerLeft.y = centerRight.y = (1 - CENTER_POINT_Y) * binImg.rows;

*/////Vuong
cout<<"space"           <<space<<endl;
        if(isLeft && isRight)
    {
        space=(centerRight.x - centerLeft.x);
         centerLeft.x += xLeftRect;
         centerRight.x += xRightRect;
         centerPoint.x = (centerLeft.x + centerRight.x) / 2;
         centerPoint.y = centerLeft.y = centerRight.y = (1 - CENTER_POINT_Y) * binImg.rows;

        circle(colorImg, centerPoint, 2, Scalar(255, 255, 0), 3);
        circle(colorImg, centerLeft, 2, Scalar(255, 0, 255), 3);
        circle(colorImg, centerRight, 2, Scalar(0, 255, 255), 3);
        putText(colorImg, "Left - Right", Point(60, 100), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255, 255, 0), 1, CV_AA);
         
    }
    if(!isLeft && isRight)
    {
    centerRight.x += xRightRect;
    centerPoint.x = centerRight.x - space-50;
    centerPoint.y = centerLeft.y = centerRight.y = (1 - CENTER_POINT_Y) * binImg.rows;
    circle(colorImg, centerPoint, 2, Scalar(255, 255, 0), 3);
    circle(colorImg, centerRight, 2, Scalar(0, 255, 255), 3);
    putText(colorImg, "Right", Point(60, 100), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255, 255, 0), 1, CV_AA);
    
    }
    if(isLeft && !isRight)
    {
    centerLeft.x += xLeftRect;
    centerPoint.x = centerLeft.x + space;
    centerPoint.y = centerLeft.y = centerRight.y = (1 - CENTER_POINT_Y) * binImg.rows;
    circle(colorImg, centerPoint, 2, Scalar(255, 255, 0), 3);
    circle(colorImg, centerLeft, 2, Scalar(255, 0, 255), 3);
    putText(colorImg, "Left ", Point(60, 100), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255, 255, 0), 1, CV_AA);
    
    }
    
    // Draw center points
    /*circle(colorImg, centerPoint, 2, Scalar(255, 255, 0), 3);
    circle(colorImg, centerLeft, 2, Scalar(255, 0, 255), 3);
    circle(colorImg, centerRight, 2, Scalar(0, 255, 255), 3);*/
    imshow("color", colorImg);
}

Mat remOutlier(const Mat &gray)
{
    int esize = 1;
    Mat element = getStructuringElement(MORPH_RECT,
                                                Size(2 * esize + 1, 2 * esize + 1),
                                                Point(esize, esize));
    erode(gray, gray, element);
    std::vector<std::vector<Point>> contours, polygons;
    std::vector<Vec4i> hierarchy;
    findContours(gray, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
    for (size_t i = 0; i < contours.size(); ++i)
    {
        std::vector<Point> p;
        approxPolyDP(Mat(contours[i]), p, 2, true);
        polygons.push_back(p);
    }
    Mat poly = Mat::zeros(gray.size(), CV_8UC3);
    for (size_t i = 0; i < polygons.size(); ++i)
    {
        Scalar color = Scalar(255, 255, 255);
        drawContours(poly, polygons, i, color, CV_FILLED);
    }
    return poly;
}

void analyzeFrame(const VideoFrameRef &frame_color, Mat &color_img)
{
    int w = frame_color.getWidth();
    int h = frame_color.getHeight();

    color_img = Mat(h, w, CV_8UC3);
    RGB888Pixel *color_img_data = (RGB888Pixel *)frame_color.getData();
    memcpy(color_img.data, color_img_data, h * w * sizeof(RGB888Pixel));
    cvtColor(color_img, color_img, COLOR_RGB2BGR);

    return;
}

/// Return angle between veritcal line containing car and destination point in degree
double getTheta(Point car, Point dst)
{
    if (dst.x == car.x)
        return 0;
    if (dst.y == car.y)
        return (dst.x < car.x ? -90 : 90);
    double pi = acos(-1.0);
    double dx = dst.x - car.x;
    double dy = car.y - dst.y; // image coordinates system: car.y > dst.y
    if (dx < 0)
        return -atan(-dx / dy) * 180 / pi;
    return atan(dx / dy) * 180 / pi;
}