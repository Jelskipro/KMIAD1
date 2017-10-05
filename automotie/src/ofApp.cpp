#include "ofApp.h"

void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this,
		&ofApp::setupArduino);
	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();

	ofSetLogLevel(OF_LOG_NOTICE);
}

void ofApp::update(){
	arduino.update();

}

void ofApp::draw(){

}

void ofApp::keyPressed(int key){
	//if (key == ' ') {

	//}
	//arduino.sendDigital(11, ARD_HIGH);

}

void ofApp::keyReleased(int key) {
	
	//arduino.sendDigital(11, ARD_LOW);

}

void ofApp::setupArduino(const int& version) {
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName()
		<< arduino.getMajorFirmwareVersion()
		<< arduino.getMinorFirmwareVersion() << endl;

	//arduino.sendDigitalPinMode(11, ARD_OUTPUT);
	arduino.sendDigitalPinMode(12, ARD_INPUT);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);

}

void ofApp::digitalPinChanged(const int& pin) {
	ofLog() << "Digital pin" << pin << "value : " << arduino.getDigital(pin) << endl;
	if (arduino.getDigital(pin) == 1)
	{
	}
	if (arduino.getDigital(12)) {
		ofLog() << "Pressed" << endl;

	}
}
