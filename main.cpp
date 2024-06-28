#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "correction.h"

// write your path to the image
const std::string IMAGE = "image.jpg";
// write your gamma value
// values 
const double GAMMA = 1.3;
// 'n' if normal gamma correction, 'r' if reversed gamma correction
const char MODE_NAME = 'n';






// an example how to use gamma correction and reversed gamma correction
int main(int argc, char** argv)
{

	std::string image_name = IMAGE;
	double gamma = GAMMA;
	char mode = MODE_NAME;

	// if gamma is lower than 0, then correction makes no sense
	if (gamma < 0)
	{
		printf("\nGamma must be bigger than 0\n");
		return 0;
	}



	// try opening the image
	cv::Mat image_original = cv::imread(image_name);
	if (image_original.empty())
	{
		std::cout << "Could not open or find the image!\n" << std::endl;
		return 0;
	}


	cv::Mat image_corrected = cv::Mat::zeros(image_original.size(), image_original.type());
	if (mode == 'n')
		Correction::gammaCorrection(image_original, image_corrected, gamma);
	else if (mode == 'r')
		Correction::reversedGammaCorrection(image_original, image_corrected, gamma);
	cv::Mat _output;
	// presenting original and corrected image side by side
	cv::hconcat(image_original, image_corrected, _output);
	cv::imshow("Images: original, gamma corrected", _output);
	cv::waitKey(0);
	cv::destroyWindow("Images: original, gamma corrected");
	printf("If you want to save the corrected image, print 's'. Else press 'n': ");

	// Option to save the corrected image. 
	uchar key;
	std::cin >> key;
	if (key == 's')
		cv::imwrite("output_" + std::to_string(gamma) + ".jpg", image_corrected);
	return 0;
}