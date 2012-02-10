 #include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	 ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	tracker.setup();
    //myImage.loadImage("Blue.png");
    
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
	}
}

void testApp::draw() {
	ofSetColor(255);
    ofTranslate(ofGetWidth(), 0);
    ofScale(-1, 1);
    //ofsetdrawbitmapstringmode...model 
    
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    cam.draw(0, 0);

	if(tracker.getFound()) {
	//	tracker.draw();
		ofMesh objectMesh = tracker.getObjectMesh();//3d mesh
		//GET IMAGE MESH
        ofMesh meanMesh = tracker.getMeanObjectMesh();
        ofMesh imageMesh = tracker.getImageMesh();
        mouth = tracker.getObjectFeature(ofxFaceTracker::INNER_MOUTH);

        
        int vertices[] = {54,57,58,55,56};
        int n = 5;
        for(int i = 0; i < n; i++) {
            int j = vertices[i];
            //get vertex at j index
            //   ofVec3f getVertex(j);
            //  int newJ=getWindowHeight()-1-j;
            ofVec3f cur = imageMesh.getVertex(j);
            // ofMesh * 
            //setVertex(newJ);
            //cur.y = cur.y*1.2; 
            cur.y+=sin(ofGetElapsedTimef())*10+cur.y*0.012;
            cur.x+=sin(ofGetElapsedTimef())*10;
            imageMesh.setVertex(j,cur);

        
        cam.getTextureReference().bind();
       // ofTranslate(-1*ofGetWidth(),0);

       // mouth.draw();

    imageMesh.draw();
        
        cam.getTextureReference().unbind();
		//cam.getTextureReference().unbind();
        
        //fast image clone
        //blending 
        
        //draw inside of mouth
              
        mouth.setClosed(true);
        ofPushStyle();
        ofFill();
        ofSetColor(60,0,0);
        ofBeginShape();
        for(int i =0; i<mouth.size(); i++){
            ofVertex(mouth[i]);
        }
        ofEndShape(true);
        ofPopStyle();  
               mouth.draw();
           }
        
        //texture a 3d surface with an image. the mesh is the shpae of the grommets, the pixesl stretched over are "bind"
        //unbind
        
        //beginshape, drawpolyline, look up positions of each vertex in inmage mesh, draw filled poly
        //
	}
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}