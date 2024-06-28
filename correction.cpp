#include "correction.h"
#include "lut.h"


void Correction::gammaCorrection(const cv::Mat& image_original, cv::Mat& image_corrected, const double& gamma)
{
	// scanning with a pointer; verse by verse, column by column
	cv::Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = cv::saturate_cast<uchar>(pow((i / 255.0), gamma) * 255.0);

	// my implementation of a Look Up Table;
	Lut::data_addressing(image_original, lookUpTable, image_corrected);
	return;
}
void Correction::reversedGammaCorrection(const cv::Mat& image_original, cv::Mat& image_corrected, const double& gamma)
{
	cv::Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = cv::saturate_cast<uchar>(pow((i * pow(255, gamma - 1)), 1.0 / gamma));

	Lut::data_addressing(image_original, lookUpTable, image_corrected);
	return;
}