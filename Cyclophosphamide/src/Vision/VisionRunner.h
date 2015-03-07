/*
 * VisionRunner.h
 *
 *  Created on: Mar 4, 2015
 *      Author: s-4020395
 */

#ifndef SRC_VISION_VISIONRUNNER_H_
#define SRC_VISION_VISIONRUNNER_H_

#include <pthread.h>
#include "WPILib.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
using namespace cv;
using namespace std;

#define CV_X_RES 320
#define CV_Y_RES 480
#define NO_TOTE_IN_VIEW -420420
#define MIN_AREA_OF_BIN 10000
#define COLOR_RANGE_H 10
#define COLOR_RANGE_S 20
#define COLOR_RANGE_V 28

class VisionRunner: public PIDSource {
private:
	cv::VideoCapture *cap; //capture the video from web cam
	pthread_t main_thread;
	bool enabled = true;
	bool initialize(int xRes, int yRes, int port, float fps);
	void* run(void*);
	static void *initHelper(void *classref);
	double xPosition, yPosition;

	// yellow bin is H=47 S=100 L=50
	int iLowH = 25;  //100
	int iHighH = 35;  //140

	int iLowS = 80; //240
	int iHighS = 100; //255

	int iLowV = 120; //was 100
	int iHighV = 148;

	int xResolution;
public:
	VisionRunner(int xRes, int yRes, int port = 0, float fps = 7.5);
	virtual ~VisionRunner();
	static VisionRunner &getInstance(int xRes = CV_X_RES, int yRes = CV_Y_RES,
			int port = 0, float fps = 7.5);
	void ThreadKill();
	void ThreadStart();
	double getXPosition();
	double getYPosition();
	void setColorValues(int avgH, int avgS, int avgV);
	double PIDGet();
	int getXResolution();
};

#endif /* SRC_VISION_VISIONRUNNER_H_ */
