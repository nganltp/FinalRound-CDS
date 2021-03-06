#include "openni2.h"
using namespace framework;
OpenNI2::OpenNI2()
{

}

OpenNI2::~OpenNI2()
{

}

bool OpenNI2::init(bool is_colorize_disp, bool is_fixed_max_disp, int image_mode, bool *retrived_img_flags) {
    this->is_colorize_disp = is_colorize_disp;
    this-> is_fixed_max_disp = is_fixed_max_disp;
    this-> image_mode = image_mode;
    std::cout << "Openning Device ..." << std::endl;
    capture.open(cv::CAP_OPENNI2);
    if ( !capture.isOpened()) {
        std::cout << "Can not open a capture object" << std::endl;
        return false;
    }
    
    capture.set(cv::CAP_PROP_OPENNI2_MIRROR, false);
    if (image_mode >= 0) {
        bool mode_res = false;
        switch (image_mode) {
            case 0:
                mode_res = capture.set(CV_CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, cv::CAP_OPENNI_VGA_30HZ);
				
                break;
            case 1:
                mode_res = capture.set(cv::CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, cv::CAP_OPENNI_SXGA_15HZ);
                break;
            case 2:
                mode_res = capture.set(cv::CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, cv::CAP_OPENNI_SXGA_30HZ );
                break;
                //The following modes are only supported by the Xtion Pro Live
            case 3:
                mode_res = capture.set(cv::CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, cv::CAP_OPENNI_QVGA_30HZ );
                break;
            case 4:
                mode_res = capture.set(cv::CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE, cv::CAP_OPENNI_QVGA_60HZ );

                break;
            default:
                CV_Error( cv::Error::StsBadArg, "Unsupported image mode property.\n");
        }
        if (!mode_res)
            std::cout << "\nThis image mode is not supported by the device, the default value (CV_CAP_OPENNI_SXGA_15HZ) will be used.\n" << std::endl;
    }
    // turn on depth, color and IR if needed
    if (retrived_img_flags != NULL) {
        if (retrived_img_flags[0] || retrived_img_flags[1] || retrived_img_flags[2])
            capture.set(cv::CAP_OPENNI_DEPTH_GENERATOR_PRESENT, true);
        else
            capture.set(cv::CAP_OPENNI_DEPTH_GENERATOR_PRESENT, false);
        if (retrived_img_flags[3] || retrived_img_flags[4])
            capture.set(cv::CAP_OPENNI_IMAGE_GENERATOR_PRESENT, true);
        else
            capture.set(cv::CAP_OPENNI_IMAGE_GENERATOR_PRESENT, false);
        if (retrived_img_flags[5])
            capture.set(cv::CAP_OPENNI_IR_GENERATOR_PRESENT, true);
        else
            capture.set(cv::CAP_OPENNI_IR_GENERATOR_PRESENT, false);
    } else {
        capture.set(cv::CAP_OPENNI_DEPTH_GENERATOR_PRESENT, true);
        capture.set(cv::CAP_OPENNI_IMAGE_GENERATOR_PRESENT, true);
    }


    // Print some avalible device settings.
    if (capture.get(cv::CAP_OPENNI_DEPTH_GENERATOR_PRESENT))
    {
        std::cout << "\nDepth generator output mode:" << std::endl <<
            "FRAME_WIDTH      " << capture.get(cv::CAP_PROP_FRAME_WIDTH) << std::endl <<
            "FRAME_HEIGHT     " << capture.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl <<
            "FRAME_MAX_DEPTH  " << capture.get(cv::CAP_PROP_OPENNI_FRAME_MAX_DEPTH) << " mm" << std::endl <<
            "FPS              " << capture.get(cv::CAP_PROP_FPS) << std::endl <<
            "REGISTRATION     " << capture.get(cv::CAP_PROP_OPENNI_REGISTRATION) << std::endl;
    }
    else
    {
        std::cout << "\nDevice doesn't contain depth generator or it is not selected." << std::endl;
    }

    if( capture.get(cv::CAP_OPENNI_IMAGE_GENERATOR_PRESENT ) )
    {
        std::cout <<
            "\nImage generator output mode:" << std::endl <<
            "FRAME_WIDTH   " << capture.get( cv::CAP_OPENNI_IMAGE_GENERATOR+cv::CAP_PROP_FRAME_WIDTH ) << std::endl <<
            "FRAME_HEIGHT  " << capture.get( cv::CAP_OPENNI_IMAGE_GENERATOR+cv::CAP_PROP_FRAME_HEIGHT ) << std::endl <<
            "FPS           " << capture.get( cv::CAP_OPENNI_IMAGE_GENERATOR+cv::CAP_PROP_FPS ) << std::endl;
    }
    else
    {
        std::cout << "\nDevice doesn't contain image generator or it is not selected." << std::endl;
    }

    if( capture.get(cv::CAP_OPENNI_IR_GENERATOR_PRESENT)==false ) //test code == false
    {
        std::cout <<
            "\nIR generator output mode:" << std::endl <<
            "FRAME_WIDTH   " << capture.get(cv::CAP_OPENNI_IR_GENERATOR + cv::CAP_PROP_FRAME_WIDTH) << std::endl <<
            "FRAME_HEIGHT  " << capture.get(cv::CAP_OPENNI_IR_GENERATOR + cv::CAP_PROP_FRAME_HEIGHT) << std::endl <<
            "FPS           " << capture.get(cv::CAP_OPENNI_IR_GENERATOR + cv::CAP_PROP_FPS) << std::endl;
    }
    else
    {
        std::cout << "\nDevice doesn't contain IR generator or it is not selected." << std::endl;
    }
    return true;
}

bool OpenNI2::getDepthMap(cv::Mat &depth) {
    if (!capture.grab()) {
        std::cout << "Can not grab images." << std::endl;
        return false;
    }
    bool res = capture.retrieve(depth, cv::CAP_OPENNI_DEPTH_MAP);
    return res;
}

bool OpenNI2::getValidDepthMap(cv::Mat &valid_depth) {
    if (!capture.grab()) {
        std::cout << "Can not grab images." << std::endl;
        return false;
    }
    bool res = capture.retrieve(valid_depth, cv::CAP_OPENNI_VALID_DEPTH_MASK);
    return res;
}
bool OpenNI2::getDisparityMap(cv::Mat &disparity) {
    if (!capture.grab()) {
        std::cout << "Can not grab images." << std::endl;
        return false;
    }
    bool res = capture.retrieve(disparity, cv::CAP_OPENNI_DISPARITY_MAP);
    return res;
}

bool OpenNI2::getBGRImage(cv::Mat &img) {
    if (!capture.grab()) {
        std::cout << "Can not grab images." << std::endl;
        return false;
    }
    bool res = capture.retrieve(img, cv::CAP_OPENNI_BGR_IMAGE);
    return res;
}

bool OpenNI2::getGrayImage(cv::Mat &gray) {
    if (!capture.grab()) {
        std::cout << "Can not grab images." << std::endl;
        return false;
    }
    bool res = capture.retrieve(gray, cv::CAP_OPENNI_GRAY_IMAGE);
    return res;
}

bool OpenNI2::getIRImage(cv::Mat &ir) {
    if (!capture.grab()) {
        std::cout << "Can not grab images." << std::endl;
        return false;
    }
    bool res = capture.retrieve(ir, cv::CAP_OPENNI_IR_IMAGE);
    return res;
}

bool OpenNI2::getImage(cv::Mat &img, int type) {
    if (!capture.grab()) {
        std::cout << "Can not grab images." << std::endl;
        return false;
    }
    bool res = capture.retrieve(img, type);
    return res;
}

bool OpenNI2::getData(cv::Mat &color, cv::Mat &depth, cv::Mat &gray, cv::Mat &disparity)
{
	if (!capture.grab())
	{
		std::cout << "Can not grab data." << std::endl;
	}
	bool res = capture.retrieve(color, cv::CAP_OPENNI_BGR_IMAGE);
	res *= capture.retrieve(depth, cv::CAP_OPENNI_DEPTH_MAP);
	res *= capture.retrieve(gray, cv::CAP_OPENNI_GRAY_IMAGE);
	res *= capture.retrieve(disparity, cv::CAP_OPENNI_DISPARITY_MAP);
	return res;
} 
