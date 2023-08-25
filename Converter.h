#pragma once

#include <iostream>
#include <string>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/opengl.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/cudaimgproc.hpp>
//#include <opencv2/cuda>
#include <opencv2/cudawarping.hpp> 

class Converter
{
public:
	Converter(void);
	~Converter(void);
	std::string& mat2string(cv::Mat, double, double, std::string&, int);
	std::string& mat2string(cv::cuda::GpuMat, double, double, std::string&, int);
private:
	cv::Mat frame;
	cv::cuda::GpuMat Gframe;
	std::string strbuffer;
	int h;
	int w;
	uchar* ptr;
};

