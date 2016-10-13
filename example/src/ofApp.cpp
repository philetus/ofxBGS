#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	setCam(&grabber, "C920"); // try to find external webcam
	grabber.initGrabber(GRABBER_WIDTH, GRABBER_HEIGHT);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	if(grabber.isFrameNew()){
		bgs.update(grabber.getPixelsRef());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	bgs.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key == OF_KEY_RIGHT)
		bgs.nextProcessor();
	if(key == OF_KEY_LEFT)
		bgs.previousProcessor();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
