#ifndef LINE_H
#define LINE_H

#include <opencv2/opencv.hpp>

class Line 
{
	public:
		Line(cv::Point a, cv::Point b);
		~Line();

		void setCoordinates(cv::Point a, cv::Point b);
		std::pair<cv::Point, cv::Point> getCoordinates();
		void drawLines(cv::Mat& img, cv::Scalar color = cv::Scalar(0, 0, 255), int thickness = 8);
		double getLineSlope() const { return mSlope; }
		double getLineBias() const { return mBias; }

	private:
		void computeSlope();
		void computeBias();


	private:
		cv::Point mPointA;
		cv::Point mPointB;
		double mSlope;
		double mBias;
};

#endif
