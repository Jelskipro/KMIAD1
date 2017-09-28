#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(drawGrid.set("Grid", true));
	gui.add(useLight.set("Light", true));
	gui.add(radius.set("Radius", 50, 0, 400));
	gui.add(longitude.set("Longitude", 0, 0, 360));
	gui.add(latitude.set("Latitude", 0, 0, 360));
	gui.add(rotationRadius.set("RotationRadius", 1000, 0, 1000));
	gui.add(rotationSpeed.set("RotationSpeed", 1, 0, 25));
	gui.add(Lx.set("LightX", 0, 0, 1000));
	gui.add(Ly.set("LightY", 0, 0, 1000));
	gui.add(Lz.set("LightZ", 0, 0, 1000));

	ofBackground(ofColor::black);
	ofSetFrameRate(60);

	//light.setDirectional();
	//light.setPosition(-200, -200, -200);
	//light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	//light.setDiffuseColor(ofColor::white);
	

	rotationPoint = ofVec3f(0, 0, 0);

	color = ofColor::greenYellow;
	
	ofDisableArbTex();
	earthTexture.loadImage("earth.png");
	moonTexture.loadImage("moon.png");
	sunTexture.loadImage("sun.png");

	planet.setRadius(radius);
	moon.setRadius(20);
	sun.setRadius(400);

	starDestroyer.loadModel("StarDestroyer.obj", false);
	starDestroyer.setPosition(0, 0, 750);
	starDestroyer.setRotation(0, 180, 90, 0, 90);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (longitude < 360)
	{
		longitude = longitude + rotationSpeed;
	}
	else
	{
		longitude = 0;
	}
	light.setPointLight();
	light.setPosition(Lx, Ly, Lz);
	light.setDiffuseColor(ofColor::orangeRed);
	//light.setAmbientColor(ofColor::orangeRed);
	light.enable();
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();

	ofEnableDepthTest();
	cam.begin();

	if (drawGrid) ofDrawGrid(200);

	if (useLight) {
		ofEnableLighting();
	}
	else {
		ofDisableLighting();
	}
	
	planet.orbit(longitude, latitude, rotationRadius, rotationPoint);
	earthTexture.getTextureReference().bind();
	planet.draw();

	moon.setParent(planet, false);
	moon.orbit(longitude, latitude, 200, ofVec3f(0, 0, 0));
	moonTexture.getTextureReference().bind();
	moon.draw();

	sun.orbit(0, 0, 0, rotationPoint);
	sunTexture.getTextureReference().bind();
	//sun.draw();

	starDestroyer.drawFaces();

	ofSetColor(ofColor::seaGreen);
	ofDrawSphere(Lx, Ly, Lz, 200);

	cam.end();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		
	}
}

