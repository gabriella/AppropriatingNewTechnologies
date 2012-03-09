#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bSendSerialMessage = false;
	ofSetLogLevel(OF_LOG_NOTICE);

	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup( PORT );

	current_msg_string = 0;


	ofBackground( 30, 30, 130 );
    
    
    
    serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	//----------------------------------- note:
	// < this should be set
	// to whatever com port
	// your serial device is
	// connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
    
	serial.setup(0, 9600); //open the first device
    
	//serial.setup("COM4");  						  // windows example
	//serial.setup("/dev/tty.usbserial-A4001JEC",9600); // mac osx example
	//serial.setup("/dev/ttyUSB0", 9600);			  //linux example
    


}

//--------------------------------------------------------------
void testApp::update(){

	// hide old messages
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )
	{
		if ( timers[i] < ofGetElapsedTimef() )
			msg_strings[i] = "";
	}

	// check for waiting messages
	while( receiver.hasWaitingMessages() )
	{
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage( &m );

		// check for mouse moved message
		if ( m.getAddress() == "/gesture/blink" )
		{
            
            cout<< m.getArgAsInt32(0)<<endl;
            if(m.getArgAsInt32(0)==0){
            screenColor = 0;
                message=0;
                //serial.writeByte('1');

            }
            
		
        else{screenColor = 255;
            message=1;
            serial.writeByte('0');
        }
            
            serial.flush();  
            //if (bSendSerialMessage){
            //ofSerial.writeByte('0');

        //}
		}
}
}


//--------------------------------------------------------------
void testApp::draw(){

	
    ofSetColor(screenColor);
    ofRect(0,0,ofGetWindowWidth(), ofGetWindowHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

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
