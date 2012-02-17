#include "ofApp.h"

// save http://i.imgur.com/ym71g.gif as data/body.gif

//Coding advice: make fewer decisions so you can make fewer mistakes

int i=50;
int t=0;
int j=50;
int newTr=0;

void ofApp::setup() {
	ofSetVerticalSync(true);
    //body.setup("body.gif",0,0,0,0);
   // melon.setup("melon.gif",100,100,100,100);
    tumor.setup("Wilms_Tumor_CTScan.gif", 0,0,0,0);

    melon.setup("Wilms_Tumor_CTScan.gif", 0,0,0,0);
//head.setup("982748.gif", 0,0,0,0);
    body1.setup("gifye.gif", 0,0,0,0);
    body2.setup("gifye.gif", 0,0,0,0);
    body3.setup("gifye.gif",0,0,0,0);

    
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
            ofRotateY(-j);
    //body.draw(3);
            //head.draw(3);
    ofPushMatrix();

   ofTranslate(30,30,i);
    ofRotateZ(i);
            ofSetColor(255,255,0,50);
   melon.draw(3);
            ofSetColor(255, 64); // make everything more transparent
           body2.draw(6);
            ofSetColor(0,255,0, 29); // make everything more transparent

            tumor.draw(10);
            ofPopMatrix();
            ofPushMatrix();
            ofTranslate(25,j/5,-25);
            ofRotateZ(j);
            ofSetColor(255,100,0, 50); // make everything more transparent
           // ofSetColor(0,0,255, 64); // make everything more transparent
           // body3.draw(10);
            body1.draw(8);
            ofPopMatrix();
            ofPopMatrix();
            ofSetColor(255,255,255,255);
        }
    i--;
    j--;

    cam.end();

}
void ofApp::keyPressed(int key){
   // int j=0;

    if((key)=='a')
    {
         trans();
        
                     t++;
    }
}
int ofApp::trans(){ 
    cout<<"i'm in trans";
     int moving = 1;
    return moving;
}