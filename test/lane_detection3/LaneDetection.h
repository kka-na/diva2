#ifndef LANE_DETECTION_H
#define LANE_DETECTION_H
#define PI 3.14159265358979323846 

#include "Line.h"

enum LANE_DETECTION_METHOD {
	BASIC=0,
	ADVANCED
};

class LaneDetection {
	public:
		LaneDetection(LANE_DETECTION_METHOD laneDetectionMethod);
		~LaneDetection();
		void DetectLanes(cv::Mat& frame);

	private:
		//methods for Basic Lane Detection
		void runBasicLaneDetection(cv::Mat& frame);
		void inferTwoLaneLines(std::vector<cv::Vec4i>& hough_lines, cv::Mat& frame);
		void computeLanes(std::vector<Line> lines, cv::Mat& frame);
		double getMedian(std::vector<double> values)const;
		Line smoothenLanesOverTime(std::vector<Line>& laneLines);
		cv::Point getMeanOfPoints(std::vector<cv::Point>& points);
		void removeExcessLines(std::vector<Line> &lines);
		void drawLanes(Line& leftLane, Line& rightLane, cv::Mat& frame);

		//methods for Advance Lane Detection
		void runAdvanceLaneDetection(cv::Mat& frame);

	private:
		LANE_DETECTION_METHOD mLaneDetectionMethod;
		std::vector<Line> mLeftLaneLines;
		std::vector<Line> mRightLaneLines;
		int mLinesBufferSize;
		cv::Rect mRoi;

};

#endif