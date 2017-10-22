#include "ofApp.h"

void ofApp::setup(){
	for (int i = 0; i < 6; i++) {
		voicePlayer[i].load(ofToDataPath("vox" + ofToString(i + 1) + ".wav"));
		voicePlayer[i].setLoop(true);

		voicePlayer[i].play();
		//voicePlayer[i].setPaused(true);
	}

	ofSoundSetVolume(0.2);

}

void ofApp::update(){
	ofSoundUpdate();
	float time = ofGetElapsedTimef();
	float x = time* 0.1f + 30;
	for (int i = 0; i < 6; i++) {
		float y = i * 0.02f;
		float volume = ofNoise(x, y);
		voicePlayer[i].setVolume(volume);
	}
}

void ofApp::draw(){
	for (int i = 0; i < 6; i++) {
		ofSetColor(i * 20 + 128, i * 80, i * 10 + 60);
		ofDrawRectangle(100, i * 30 + 200, voicePlayer[i].getVolume() * 300, 5);
	}
}

void ofApp::keyPressed(int key){
	if (key == '1') {
	
		playing[0] = !playing[0];
		voicePlayer[0].setPaused(playing[0]);
	}
	if (key == '2') {

		playing[1] = !playing[1];
		voicePlayer[1].setPaused(playing[1]);
	}
	if (key == '3') {

		playing[2] = !playing[2];
		voicePlayer[2].setPaused(playing[2]);
	}

}

