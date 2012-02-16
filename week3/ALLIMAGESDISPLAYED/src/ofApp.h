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
	ofxMRI body, melon;
    //vector<ofImage> slices, melonslices;
    int trans();
};
