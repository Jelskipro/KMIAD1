#include "ofApp.h"
#define DRINK_BUTTON1 11
#define DRINK_BUTTON2 12

void ofApp::setup(){
	ofAddListener(arduino.EInitialized, this,
		&ofApp::setupArduino);
	arduino.connect("COM5");
	arduino.sendFirmwareVersionRequest();

	ofSetLogLevel(OF_LOG_NOTICE);

	response1.load("response1.mp3");
	response2.load("response2.mp3");

	smilleyTalking.load("Talk1.mov");
	smilleyTalking.play();
	smilleyHappy.load("Emotions/HappyB.png");

	isTalking = false;
}

void ofApp::update(){
	arduino.update();
	smilleyTalking.update();
}

void ofApp::draw(){
	smilleyHappy.draw(0, 0, 512, 512);
	if (isTalking != true)
	{
		smilleyTalking.draw(999, 999, 512, 512);

	}
	if (response1.isPlaying() || response2.isPlaying())
	{
		isTalking = true;
		smilleyTalking.draw(0, 0, 512, 512);
	}
}

void ofApp::keyPressed(int key){
	if (key == '1') {
		response2.stop();
		response1.play();
	}
	if (key == '2') {
		response1.stop();
		response2.play();
	}
}

void ofApp::setupArduino(const int& version) {
	ofLog() << "Arduino firmware found " << arduino.getFirmwareName()
		<< arduino.getMajorFirmwareVersion()
		<< arduino.getMinorFirmwareVersion() << endl;

	arduino.sendDigitalPinMode(DRINK_BUTTON1, ARD_INPUT);
	arduino.sendDigitalPinMode(DRINK_BUTTON2, ARD_INPUT);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);

}

void ofApp::digitalPinChanged(const int& pin) {
	ofLog() << "Digital Pin " << pin << " value: " << arduino.getDigital(pin) << endl;
	
	if (arduino.getDigital(12) == 1)
	{
		response2.stop();
		response1.play();
	}
	if (arduino.getDigital(11) == 1)
	{
		response1.stop();
		response2.play();
	}
}
