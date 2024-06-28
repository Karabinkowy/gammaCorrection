#pragma once
#include <opencv2/imgproc.hpp>

// void functions with normal and reversed gamma correction
class Correction {
	public:
		static void gammaCorrection(const cv::Mat& image_original, cv::Mat& image_corrected, const double& gamma);
		static void reversedGammaCorrection(const cv::Mat& image_original, cv::Mat& image_corrected, const double& gamma);
};