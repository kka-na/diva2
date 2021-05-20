#include "LaneDetection.h"
#include <numeric>


LaneDetection::LaneDetection(LANE_DETECTION_METHOD laneDetectionMethod)
{
	mLaneDetectionMethod = laneDetectionMethod;
	mLeftLaneLines = {};
	mRightLaneLines = {};
	mLinesBufferSize = 10;
	mRoi = cv::Rect(1, 309, 959, 229);
}

LaneDetection::~LaneDetection()
{
	mLeftLaneLines = {};
	mRightLaneLines = {};
}

void LaneDetection::DetectLanes(cv::Mat & frame)
{
	if (mLaneDetectionMethod == LANE_DETECTION_METHOD::BASIC)
	{
		runBasicLaneDetection(frame);
	}
	else {
		runAdvanceLaneDetection(frame);
	}
}

void LaneDetection::runBasicLaneDetection(cv::Mat & frame)
{
	// delete the lines from the front if the size is greater than the linesBufferSize
	removeExcessLines(mLeftLaneLines);
	removeExcessLines(mRightLaneLines);
	
	cv::Mat resized_img, gray_img, blur_img, edge_img;
	
	cv::Size gaussian_filter_size = cv::Size(17, 17);
	
	double canny_threshold1 = 50;
	double canny_threshold2 = 80;

	std::vector<cv::Vec4i> hough_lines;
	double rho = 2;
	double theta = PI / 180.0;
	int hough_threshold = 1;
	int min_line_len = 15;
	int max_line_gap = 5;

	// resize to 960x540
	cv::resize(frame, resized_img, cv::Size(960, 540));

	// convert to grayscale
	cv::cvtColor(resized_img, gray_img, cv::COLOR_BGR2GRAY);

	// perform Gaussian blur
	cv::GaussianBlur(gray_img, blur_img, gaussian_filter_size, 0.0);

	// perform Canny Edge Detection
	cv::Canny(blur_img, edge_img, canny_threshold1, canny_threshold2);

	// perform Hough Transform
	cv::HoughLinesP(edge_img, hough_lines, rho, theta, hough_threshold, min_line_len, max_line_gap);
	inferTwoLaneLines(hough_lines, frame);
	// process and smoothen out the lines

}

void LaneDetection::inferTwoLaneLines(std::vector<cv::Vec4i>& hough_lines, cv::Mat& frame)
{
	std::vector<Line> potential_lines;
	for (auto& l : hough_lines)
	{
		cv::Point a = cv::Point(l[0], l[1]);
		cv::Point b = cv::Point(l[2], l[3]);
		Line lineObject(a, b);
		double slope = abs(lineObject.getLineSlope());
		if (0.5 <= slope && slope <= 2)
		{
			potential_lines.push_back(lineObject);
		}
	}

	computeLanes(potential_lines, frame);

	Line smoothLeftLine = smoothenLanesOverTime(mLeftLaneLines);
	Line smoothRightLine = smoothenLanesOverTime(mRightLaneLines);

	drawLanes(smoothLeftLine, smoothRightLine, frame);
}

void LaneDetection::computeLanes(std::vector<Line> lines, cv::Mat & frame)
{
	std::vector<Line> positive_slope_lines;
	std::vector<Line> negative_slope_lines;
	std::vector<double> negative_lines_bias;
	std::vector<double> positive_lines_bias;
	std::vector<double> negative_lines_slope;
	std::vector<double> positive_lines_slope;

	for (auto l : lines)
	{
		double slope = l.getLineSlope();
		double bias = l.getLineBias();
		if (slope > 0)
		{
			positive_slope_lines.push_back(l);
			positive_lines_bias.push_back(bias);
			positive_lines_slope.push_back(slope);
		}
		else if (slope < 0)
		{
			negative_slope_lines.push_back(l);
			negative_lines_bias.push_back(bias);
			negative_lines_slope.push_back(slope);
		}
	}

	double negative_bias = getMedian(negative_lines_bias);
	double negative_slope = getMedian(negative_lines_slope);

	cv::Point leftLinePoint1 = cv::Point(0, negative_bias);
	cv::Point leftLinePoint2 = cv::Point(-std::round((negative_bias / negative_slope)), 0);
	Line LeftLane(leftLinePoint1, leftLinePoint2);

	double positive_bias = getMedian(positive_lines_bias);
	double positive_slope = getMedian(positive_lines_slope);
	cv::Point rightLinePoint1 = cv::Point(0, positive_bias);
	cv::Point rightLinePoint2 = cv::Point(std::round((frame.rows - positive_bias)/positive_slope), frame.rows);
	Line RightLane(rightLinePoint1, rightLinePoint2);

	mLeftLaneLines.push_back(LeftLane);
	mRightLaneLines.push_back(RightLane);
}

double LaneDetection::getMedian(std::vector<double> values) const
{
	size_t n = values.size() / 2;
	std::nth_element(values.begin(), values.begin() + n, values.end());
	
	// DASOL
	double vn;
	if(values.size()==0) vn=0;
	else vn=values[n];
	
	return vn;
}

Line LaneDetection::smoothenLanesOverTime(std::vector<Line>& laneLines)
{
	std::vector<cv::Point> point1vector;
	std::vector<cv::Point> point2vector;
	
	for (auto _line : laneLines)
	{
		point1vector.push_back(_line.getCoordinates().first);
		point2vector.push_back(_line.getCoordinates().second);
	}
	
	cv::Point meanPoint1 = getMeanOfPoints(point1vector);
	cv::Point meanPoint2 = getMeanOfPoints(point2vector);

	return Line(meanPoint1, meanPoint2);
}

cv::Point LaneDetection::getMeanOfPoints(std::vector<cv::Point>& points)
{
	if (points.size() > 1)
	{
		cv::Point sum = std::accumulate(points.begin(), points.end(), cv::Point2f(0.0f, 0.0f), std::plus<cv::Point2f>());
		return cv::Point(sum.x / points.size(), sum.y / points.size());
	}
	else 
	{
		return points[0];
	}
}

void LaneDetection::removeExcessLines(std::vector<Line>& lines)
{
	while (lines.size() > mLinesBufferSize)
	{
		lines.erase(lines.begin());
	}
}

void LaneDetection::drawLanes(Line & leftLane, Line & rightLane, cv::Mat & frame)
{
	cv::Mat frame_copy = frame.clone();

	cv::Mat lineImgTemp = frame.clone();
	leftLane.drawLines(lineImgTemp);
	rightLane.drawLines(lineImgTemp);

	cv::Mat lineImg = lineImgTemp(mRoi);
	lineImg.copyTo(frame(mRoi));

	cv::addWeighted(frame, 0.85, frame_copy, 1.0, 0.0, frame);
}

void LaneDetection::runAdvanceLaneDetection(cv::Mat & frame)
{
	//TODO - Advance Lane Detection
}