/*
 * VisionRunner.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: s-4020395
 */

#include <Vision/VisionRunner.h>
using namespace cv;
using namespace std;

VisionRunner::VisionRunner(int xRes, int yRes, int port, float fps) {
	xResolution = xRes;
	initialize(xRes, yRes, port, fps);
	cap = new VideoCapture();
}

VisionRunner::~VisionRunner() {}

VisionRunner &VisionRunner::getInstance(int xRes, int yRes, int port,
		float fps) {
	static VisionRunner _inst(xRes, yRes, port, fps);
	return _inst;
}

int VisionRunner::getXResolution(){
	return xResolution;
}

void VisionRunner::ThreadKill() {
	pthread_exit(&main_thread);
}

void VisionRunner::ThreadStart() {
	pthread_create(&main_thread, NULL, &initHelper, (void*) this);
}

void *VisionRunner::initHelper(void *classref) {
	return ((VisionRunner*) classref)->run(NULL);
}

double VisionRunner::getXPosition() {
	return xPosition;
}

double VisionRunner::getYPosition() {
	return yPosition;
}

void VisionRunner::setColorValues(int avgH, int avgS, int avgV) {
	iLowH = avgH - COLOR_RANGE_H / 2;
	iHighH = avgH + COLOR_RANGE_H / 2;

	iLowS = avgS - COLOR_RANGE_S / 2;
	iHighS = avgS + COLOR_RANGE_S / 2;

	iLowV = avgV - COLOR_RANGE_V / 2;
	iHighV = avgV + COLOR_RANGE_V / 2;
}

void *VisionRunner::run(void*) {
	while (enabled) {
		Mat imgOriginal;

		bool bSuccess = cap->read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
		} else {
			Mat imgHSV;

			cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

			Mat imgThresholded;

			//Vec3b hsv = imgHSV.at<Vec3b>(160, 120);
			//	cout<<(int)hsv.val[0]<<","<<(int)hsv.val[1]<<","<<(int)hsv.val[2]<<endl; //value
			inRange(imgHSV, Scalar(iLowH, iLowS, iLowV),
					Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

			//morphological opening (remove small objects from the foreground)
			erode(imgThresholded, imgThresholded,
					getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			dilate(imgThresholded, imgThresholded,
					getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

			//morphological closing (fill small holes in the foreground)
			dilate(imgThresholded, imgThresholded,
					getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			erode(imgThresholded, imgThresholded,
					getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

			//Calculate the moments of the thresholded image
			Moments oMoments = moments(imgThresholded);
			//	cout<<oMoments.m00<<endl;
			if (oMoments.m00 > MIN_AREA_OF_BIN) {
				//	  cout << " area is " << oMoments.m00 << endl;
				//calculate the position of the ball
				xPosition = (oMoments.m10 / oMoments.m00) - xResolution / 2;
				yPosition = (oMoments.m01 / oMoments.m00);
				//cout << "item is at " << posX - 160.0 << endl;
			} else {
				xPosition = NO_TOTE_IN_VIEW;
			}
		}
	}
	return NULL;
}

bool VisionRunner::initialize(int xRes, int yRes, int port, float fps) {
	cap->open(port, xRes, yRes, fps);
	if (!cap->isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}
	initHelper(this);
	cout << "done successfully" << endl;
	return 0;
}

double VisionRunner::PIDGet() {
	return xPosition;
}

