#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grabber.setDeviceID(0);
	grabber.initGrabber(320, 240);

	sphere1.setRadius(100);
	sphere1.setPosition(-50, 100, 100);
	sphere1.mapTexCoordsFromTexture(grabber.getTexture());

	sphere2.setRadius(20);
	sphere2.setPosition(80, 200, 100);
	sphere2.mapTexCoordsFromTexture(grabber.getTexture());

	sphere3.setRadius(166);
	sphere3.setPosition(-25, 0, 0);
	sphere3.mapTexCoordsFromTexture(grabber.getTexture());

	sphere4.setRadius(55);
	sphere4.setPosition(100, 50, 30);
	sphere4.mapTexCoordsFromTexture(grabber.getTexture());


	light.setDirectional();
	light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);

	ofEnableDepthTest();
	cam.setVFlip(true);
	cam.begin();

	grabber.getTexture().bind();

	sphere1.draw();
	sphere2.draw();
	sphere3.draw();
	sphere4.draw();

	grabber.getTexture().unbind();

	cam.end();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
