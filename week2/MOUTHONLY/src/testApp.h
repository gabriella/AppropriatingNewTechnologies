#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"
using namespace ofxCv;
using namespace cv;

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
		
	ofEasyCam easyCam;
    ofImage myImage; 
    ofPolyline mouth;
    ofPolyline lefteye;
   // ofxFaceTracker destTracker;

};
