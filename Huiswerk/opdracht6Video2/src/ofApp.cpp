#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.load("test.mp4");
	video.play();
	video.setLoopState(OF_LOOP_NORMAL);
	rotate = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
	rotate++;
}

void ofApp::draw(){
	ofSetColor(ofColor::white);
	video.draw(0, 0);

	ofSetColor(ofColor::blue);
	ofTranslate(400, 200);
	ofRotateX(rotate);
	ofRotateY(rotate);
	video.draw(0, 0);

	ofSetColor(ofColor::red);
	ofTranslate(800, 400);
	ofScale(0.7, 0.7, 0.7);
	ofRotateX(rotate);
	ofRotateY(rotate);
	video.draw(0, 0);

}

void ofApp::keyPressed(int key){

}

