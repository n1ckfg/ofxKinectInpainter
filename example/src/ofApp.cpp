#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	kinect.init();
	kinect.open();
	
	inpainter.setup(kinect.getWidth(), kinect.getHeight());
	depthImg.allocate(kinect.getWidth(), kinect.getHeight());
	inpaintedImg.allocate(kinect.getWidth(), kinect.getHeight());
}

//--------------------------------------------------------------
void ofApp::update() {
	float t = ofGetElapsedTimef();
	kinect.update();
	
	depthImg.setFromPixels(kinect.getDepthPixels(), kinect.getWidth(), kinect.getHeight());
	
	inpaintedImg = depthImg;
	inpainter.inpaint(inpaintedImg);
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 2)+"fps - Inpainting radius: " 
					 + ofToString(inpainter.getInpaintingRadius()) + "px    downsampling: " 
					 + ofToString((inpainter.getDownsampling())) + ":1");
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetHexColor(0xFFFFFF);
	depthImg.draw(0, 0);
	inpaintedImg.draw(depthImg.getWidth(), 0);
	ofSetHexColor(0xFF0000);
	ofDrawBitmapString("Raw Kinect View", 20, 20);
	
	ofDrawBitmapString("Inpainted Kinect View", depthImg.getWidth() + 20, 20);
	
	ofEnableAlphaBlending();
	glColor4f(0, 0, 0, 0.7);
	ofRect(10, ofGetHeight()-30, 540, 15);
	ofSetHexColor(0x44CC44);
	ofDrawBitmapString("Move your mouse to change the inpaint radius and downsample factor", 20, ofGetHeight()-20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
	inpainter.setInpaintingRadius(ofMap(x, 0, ofGetWidth(), 1, 10, true));
	inpainter.setDownsampling(ofMap(y, 0, ofGetHeight(), 1, 20, true));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { 

}