#include "Converter.h"

std::string& Converter::mat2string(cv::Mat m, double sx, double sy, std::string& GrayScale,int i = cv::INTER_LINEAR)
{
	Gframe.upload(m);
	strbuffer.clear();
	cv::cuda::cvtColor(Gframe, Gframe, cv::COLOR_RGB2GRAY);
	cv::cuda::resize(Gframe, Gframe, cv::Size(), sx, sy, i);
	Gframe.download(frame);
	w = frame.cols;
	h = frame.rows;
	for(int r = 0; r < h; r++)
	{
		ptr = frame.ptr<uchar>(r);
		for(int c = 0; c < w; c++)
		{
			strbuffer += GrayScale[*(ptr + c) / (255.0f / (float)GrayScale.length())];
		}
		strbuffer += '\n';
	}
	return strbuffer;
}

std::string& Converter::mat2string(cv::cuda::GpuMat m, double sx, double sy, std::string& GrayScale, int i = cv::INTER_LINEAR)
{
	strbuffer.clear();
	cv::cuda::cvtColor(Gframe, Gframe, cv::COLOR_RGB2GRAY);
	cv::cuda::resize(Gframe, Gframe, cv::Size(), sx, sy, i);
	Gframe.download(frame);
	w = frame.cols;
	h = frame.rows;
	for (int r = 0; r < h; r++)
	{
		ptr = frame.ptr<uchar>(r);
		for (int c = 0; c < w; c++)
		{
			strbuffer += GrayScale[*(ptr + c) / (255.0f / (float)GrayScale.length())];
		}
		strbuffer += '\n';
	}
	return strbuffer;
}

Converter::Converter()
{
	return;
}

Converter::~Converter()
{
	return;
}