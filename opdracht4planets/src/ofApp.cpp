#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this,
		&ofApp::setupArduino);
	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();

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
	
	ofDisableArbTex();
	earthTexture.loadImage("earth.png");
	moonTexture.loadImage("moon.png");
	sunTexture.loadImage("sun.png");

	planet.setRadius(radius);
	moon.setRadius(20);

	starDestroyer.loadModel("StarDestroyer.obj", false);
	starDestroyer.setPosition(0, 0, 750);
	starDestroyer.setRotation(0, 180, 90, 0, 90);
}

//--------------------------------------------------------------
void ofApp::update(){
	arduino.update();

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
	ofDisableAlphaBlending();

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
	sun.setRadius(radius * 10);

	sun.draw();

	starDestroyer.drawFaces();

	//sphere from point light
	//ofDrawSphere(Lx, Ly, Lz, 200);

	cam.end();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		
	}
}
void ofApp::setupArduino(const int& version) {
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName()
		<< arduino.getMajorFirmwareVersion()
		<< arduino.getMinorFirmwareVersion() << endl;

	arduino.sendDigitalPinMode(11, ARD_OUTPUT);
	arduino.sendDigitalPinMode(12, ARD_INPUT);
	arduino.sendAnalogPinReporting(0, ARD_ANALOG);
	arduino.sendAnalogPinReporting(1, ARD_ANALOG);

	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);

}

void ofApp::analogPinChanged(const int& pin) {
	radius = arduino.getAnalog(pin) / 19;
	ofLog() << radius << endl;
	ofLog() << "Analog pin" << pin << "value : " << arduino.getAnalog(pin) / 19 << endl;
}
void ofApp::digitalPinChanged(const int& pin) {
	ofLog() << "Digital pin" << pin << "value : " << arduino.getDigital(pin) << endl;
	if (arduino.getDigital(pin) == 1)
	{

	
	}
}
