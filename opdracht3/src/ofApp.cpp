#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofAddListener(arduino.EInitialized, this,
		&ofApp::setupArduino);
	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();

	ofSetWindowShape(800, 600);

	speedX = 20;
	speedY = 20;

	ofSetLogLevel(OF_LOG_NOTICE);
}

//--------------------------------------------------------------
void ofApp::update(){
	arduino.update();
	for (int i = 0; i<balls.size(); i++) {
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i<balls.size(); i++) {
		balls[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		
	}
	arduino.sendDigital(11, ARD_HIGH);
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	arduino.sendDigital(11, ARD_LOW);

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

	//ofLog() << "Analog pin" << pin << "value : " << arduino.getAnalog(pin) / 19 << endl;
}
void ofApp::digitalPinChanged(const int& pin) {
	//ofLog() << "Digital pin" << pin << "value : " << arduino.getDigital(pin) << endl;
	if (arduino.getDigital(pin) == 1)
	{
		
		Ball myBall;
		myBall.setup(radius, speedX, speedY, color);
		balls.push_back(myBall);
	}
}