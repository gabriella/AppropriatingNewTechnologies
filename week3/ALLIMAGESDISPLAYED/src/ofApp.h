#pragma once

#include "ofMain.h"
#include "ofxMRI.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
   
	
	ofEasyCam cam;
	ofxMRI body1, body2,  melon, body3, tumor;// head, body1;
    //vector<ofImage> slices, melonslices;
    int trans();
};
