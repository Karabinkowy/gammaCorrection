#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

// my implementation of a Look Up Table
class Lut {
public:
	static void data_addressing(const cv::Mat& input, const cv::Mat& lookUpTable, cv::Mat& output);
};