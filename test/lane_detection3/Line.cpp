#include "Line.h"

Line::Line(cv::Point a, cv::Point b)
{
	mPointA = a;
	mPointB = b;

	computeSlope();
	computeBias();
}

Line::~Line()
{
}

void Line::computeSlope()
{
	mSlope = (mPointB.y - mPointA.y) / (mPointB.x - mPointA.x + DBL_EPSILON);
}

void Line::computeBias()
{
	mBias = (mPointA.y - mSlope*mPointA.x);
}

void Line::setCoordinates(cv::Point a, cv::Point b)
{
	mPointA = a;
	mPointB = b;
}

std::pair<cv::Point, cv::Point> Line::getCoordinates()
{
	return std::make_pair(mPointA, mPointB);
}

void Line::drawLines(cv::Mat & img, cv::Scalar color, int thickness)
{
	cv::line(img, mPointA, mPointB, color, thickness, 16);
}

