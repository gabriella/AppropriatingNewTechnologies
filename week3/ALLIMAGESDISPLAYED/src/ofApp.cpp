#include "ofApp.h"

// save http://i.imgur.com/ym71g.gif as data/body.gif

//Coding advice: make fewer decisions so you can make fewer mistakes

int i=50;
int t=0;
int newTr=0;

void ofApp::setup() {
	ofSetVerticalSync(true);
    body.setup("body.gif");
    melon.setup("melon.gif");
	ofEnableAlphaBlending();
}  
  

void ofApp::update() {
}

void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	ofSetColor(255, 64); // make everything more transparent
    
  //  body.draw(0,0,0);
    
        if (trans()==1){
            cout<<"i'm here";
            ofPushMatrix();
            
           ofTranslate(t,0,0);

    body.draw();
    ofPushMatrix();

   ofTranslate(i,30,20);
    ofRotateZ(i);
    melon.draw();
    i++;

            ofPopMatrix();
            ofPopMatrix();

        }

    cam.end();

}
void ofApp::keyPressed(int key){
   // int j=0;

    if((key)=='a')
    {
         newTr=trans();
        
                     t++;
    }
}
int ofApp::trans(){ 
    cout<<"i'm in trans";
     int i=1;
    return i;
}