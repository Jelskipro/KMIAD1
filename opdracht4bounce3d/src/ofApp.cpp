#include "ofApp.h"

void ofApp::setup() {
	gui.setup();
	gui.add(drawGrid.set("Grid", false));
	gui.add(useLight.set("Light", false));
	gui.add(radius.set("Radius", 50, 0, 200));
	gui.add(speedX.set("SpeedX", 50, 0, 200));
	gui.add(speedY.set("SpeedY", 50, 0, 200));
	gui.add(color.set("Color", ofColor::white));

	ofBackground(ofColor::black);
	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor::white);
	light.enable();

	//Default waarden die niet al te hoog zijn
	speedX = 4;
	speedY = 4;
	speedZ = 4;
	radius = 25;
}

void ofApp::update() {
	for (int i = 0; i<balls.size(); i++) {
		balls[i].update();
	}
}

void ofApp::draw() {
	gui.draw();

	ofEnableDepthTest();
	cam.begin();

	ofSetColor(ofColor::yellow);
	ofDrawSphere(0, 0, 200, 100);

	if (drawGrid) ofDrawGrid(200);

	if (useLight) {
		ofEnableLighting();
	}
	else {
		ofDisableLighting();
	}
	
	for (int i = 0; i<balls.size(); i++) {
		balls[i].draw();
	}

	cam.end();
	ofDisableDepthTest();
}
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		Ball3d myBall;
		myBall.setup(radius, speedX, speedY, speedZ, color);
		balls.push_back(myBall);
	}
}