#include "testApp.h"

extern "C" {
#include "macGlutfix.h"
}

//--------------------------------------------------------------
void testApp::setup(){

	finder.setup("haarcascade_frontalface_default.xml");
	//CGContextRef cgctx = NULL;
	//ofSetVerticalSync(true);
	//tex.allocate(300,300, GL_RGBA);
	image.allocate(300, 300, OF_IMAGE_COLOR);
	//pixels.allocate(300, 300, OF_IMAGE_COLOR);
	
    //load all images
    glasses.loadImage("images/sunGl.png");
    bolt.loadImage("images/bolt.png");
    blueStar.loadImage("images/blueStar.png");
    
    ofEnableAlphaBlending();
    
    
	ofSetFrameRate(30);

}

//--------------------------------------------------------------
void testApp::update(){
	
	int w = 300;
	int h = 300;
    
	
	unsigned char* data = pixelsBelowWindow(ofGetWindowPositionX(),ofGetWindowPositionY(),w,h);
	
	// now, let's get the R and B data swapped, so that it's all OK:
	for (int i = 0; i < w*h; i++){
		
		unsigned char r = data[i*4]; // mem A  
		
		data[i*4]   = data[i*4+1];   
		data[i*4+1] = data[i*4+2];   
		data[i*4+2] = data[i*4+3];   
		data[i*4+3] = r; 
	}
	
	
	if (data!= NULL) {
		//tex.loadData(data, 300, 300, GL_RGBA);
		//tex.readToPixels(pixels);
		//image = pixels;
		image.setFromPixels(data, 300, 300, OF_IMAGE_COLOR_ALPHA, true);
		image.setImageType(OF_IMAGE_COLOR);
		image.update();
		finder.findHaarObjects(image.getPixelsRef());
		
	}
	//cout << imageBelowWindow()[0] << endl;
	
	starx++;

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255,255,255,255);

	image.draw(0,0, ofGetWidth(), ofGetHeight());
	
	ofNoFill();
	
	//for each face "blob" we found, draw a rectangle around the face
    //#2
	for(int i = 0; i < finder.blobs.size(); i++) {
               ofRectangle cur = finder.blobs[i].boundingRect;
    //ofRect(cur);
        //bounding rect is of object ofRect
       
        drawGlasses(cur.x, cur.y, cur.width, cur.height);
        //image.setFromPixels(data, 300, 300, OF_IMAGE_COLOR_ALPHA, true);
        ofPushMatrix();
        ofPushStyle();
        ofTranslate(cur.x + cur.width/2 + sin(ofGetFrameNum()) * 100, cur.y + cur.height/2);
        ofRotateZ(ofGetFrameNum() * 12);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofScale(sin(ofGetFrameNum()/2)+1.2, sin(ofGetFrameNum()/2)+1.2, 0);
        drawStar(0, 0, cur.width, cur.height);
        ofPopStyle();
        ofPopMatrix();

	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::drawGlasses(float facex, float  facey, float facew, float faceh){
    ofSetColor(255,255,255,255);
      glasses.draw( facex-2, facey-5, facew+4, faceh);
    
    //how do enable alpha blending
   // ofTin
    
    ofSetColor(0,255,255,127); // red, 50% transparent

    image.draw(facex+facew/7, facey+faceh/2.6, facew/3.3, faceh/4.8);
    image.draw(facex+facew/1.9, facey+faceh/2.6, facew/3.3, faceh/4.8);
    
    //draw lightning bolts
    ofSetColor(255,255,255,255);
    bolt.draw(facex-4, facey, facew/3, faceh/3);
    bolt.draw(facex-6, facey-2, facew/2, faceh/2);
}
void testApp::drawStar(float starx, float  stary, float starw, float starh){
    ofSetColor(255, 255, 255 , 255); 
//draw blueStar
blueStar.draw(starx, stary, starw, starh);
    
}
