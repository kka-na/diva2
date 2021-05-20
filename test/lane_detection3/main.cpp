#include "LaneDetection.h"

const std::string window_name = "Lane Detection";

// const std::string video_src = "test_video.mp4";
cv::Mat frame;

LANE_DETECTION_METHOD lane_detection_method = LANE_DETECTION_METHOD::BASIC;
LaneDetection LaneDetectionObject(lane_detection_method);

int main(int argc, char *argv[])
{
	printf("lane detection3 : start\n");
	std::string video_src = argv[1];
	cv::namedWindow(window_name, cv::WINDOW_FREERATIO);
	cv::VideoCapture cap(video_src);

	if (cap.isOpened())
	{
		printf("lane detection3 : cap.isOpend\n");
		int cnt = 0;
		while (1)
		{
			if (cap.read(frame))
			{
				LaneDetectionObject.DetectLanes(frame);

				cv::imshow(window_name, frame);

				char k = cv::waitKey(1);
				if (k == 27 || k == 'q')
				{
					printf("k==27\n");
					break;
				}
				else if (k == 'p')
				{
					printf("k=='p'\n");
					cv::waitKey(0);
				}
			}
			else
			{
				std::cout << "Video Finished!!!" << '\n';
				cv::destroyAllWindows();
				std::cin.get();
				break; }
		}
	}
	printf("lane detection3 : cap is not opened\n");

	return 0;
}
