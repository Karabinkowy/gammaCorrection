#include "lut.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

void Lut::data_addressing(const cv::Mat& input, const cv::Mat& lookUpTable, cv::Mat& output) {
	
	int _rows, _cols;
	_rows = input.size().height;
	_cols = input.size().width;
	int _cn = input.channels();

	uchar _index;

	for (int i = 0; i < _rows; ++i)
	{
		for (int j = 0; j < _cols; ++j)
		{
			for (int c = 0; c < _cn; ++c)
			{
				_index = input.at<cv::Vec3b>(i, j)[c];
				output.at<cv::Vec3b>(i, j)[c] = lookUpTable.at<uchar>(_index);

			}
		}
	}
	return;
}

