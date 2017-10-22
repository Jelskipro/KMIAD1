#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowShape(800, 600);
	for (int i = 0; i<NBALLS; i++) {
		myBall[i].setup();
	}
	
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i<NBALLS; i++) {
		myBall[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	for (int i = 0; i<NBALLS; i++) {
		myBall[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------