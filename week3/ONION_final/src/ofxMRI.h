#pragma once

#include "ofMain.h"

class ofxMRI  {
public:
	void setup(string filename, int x, int y, int w, int h);
	void update();
    void draw(float s);
    int x, y;
	//void draw(float x = 0, float y = 0, float z = 0);
    

	//ofEasyCam cam;
	vector<ofImage> slices;
    //vector<ofImage>melonslices;
};
