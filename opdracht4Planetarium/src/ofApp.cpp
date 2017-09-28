#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(drawGrid.set("Grid", true));
	gui.add(useLight.set("Light", true));
	gui.add(radius.set("Radius", 50, 0, 400));
	gui.add(xRotPos.set("XRotationPoint", 0, 0, 3000));
	gui.add(yRotPos.set("YRotationPoint", 0, 0, 3000));
	gui.add(zRotPos.set("ZRotationPoint", 0, 0, 3000));
	//gui.add(rotateX.set("XRotation", 50, 0, 300));
	//gui.add(rotateY.set("YRotation", 50, 0, 300));
	//gui.add(rotateZ.set("ZRotation", 50, 0, 300));
	gui.add(longitude.set("Longitude", 0, 0, 360));
	gui.add(latitude.set("Latitude", 0, 0, 360));
	gui.add(rotationRadius.set("RotationRadius", 50, 0, 1000));
	gui.add(rotationSpeed.set("RotationSpeed", 1, 0, 25));

	ofBackground(ofColor::black);
	ofSetFrameRate(60);

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor::white);
	light.enable();
	
	//sun
	//planet.setup(600, 0, 100, 0, rotateX, rotateY, rotateZ, 0, 0, 0, 0, ofVec3f(0, 0, 0), ofColor::orange);
	//Earth
	//planet.setup(radius, xPos, yPos, zPos, rotateX, rotateY, rotateZ, longitude, latitude, rotationRadius, rotationSpeed, rotationPoint, color);
	
	//starDestroyer.loadModel("StarDestroyer.obj", false);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i<planets.size(); i++) {
		planets[i].update();

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();

	ofEnableDepthTest();
	cam.begin();

	ofSetColor(ofColor::lightGrey);

	for (int i = 0; i<planets.size(); i++) {
		planets[i].draw();
	}

	if (drawGrid) ofDrawGrid(200);

	if (useLight) {
		ofEnableLighting();
	}
	else {
		ofDisableLighting();
	}

	//starDestroyer.drawFaces();

	cam.end();
	ofDisableDepthTest();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		Planet planet;
		planet.setup(radius, rotateX, rotateY, rotateZ, longitude, latitude, rotationRadius, rotationSpeed, ofVec3f(xRotPos, yRotPos, zRotPos), color);
		planets.push_back(planet);
	}
	//sun
	if (key == 's') {
		Planet planet;
		planet.setup(200, rotateX, rotateY, rotateZ, 0, 0, 0.01f, 0, ofVec3f(xRotPos, yRotPos, zRotPos), ofColor::orange);
		planets.push_back(planet);
	}
	//earth
	if (key == 'e') {
		Planet planet;
		planet.setup(20, rotateX, rotateY, rotateZ, 1, 0, 500, 1, ofVec3f(xRotPos, 150, zRotPos), ofColor::aliceBlue);
		planets.push_back(planet);
	}	
	
	if (key == 'd') {
		if (planets.size() > 0) {
			planets.pop_back();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
