cmake_minimum_required (VERSION 2.6) 

SET(PROJECT_VERSION "0.1")

# Opencv Package
FIND_PACKAGE( OpenCV REQUIRED )
IF (${OpenCV_VERSION} VERSION_LESS 2.3.0)
	MESSAGE(FATAL_ERROR "OpenCV version is not compatible : ${OpenCV_VERSION}")
ENDIF()


ADD_EXECUTABLE( lane_detection3
                main.cpp
                Line.cpp
                LaneDetection.cpp )
TARGET_LINK_LIBRARIES( lane_detection3  ${OpenCV_LIBS} )




