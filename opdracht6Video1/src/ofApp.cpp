#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grabber.listDevices();

	grabber.setDeviceID(1);
	grabber.initGrabber(320, 240);
	grabber.setDesiredFrameRate(30);
	grabber.setVerbose(true);

	workspace.allocate(320, 240, ofImageType::OF_IMAGE_COLOR);

	randomRmutation = ofRandom(255);
	randomGmutation = ofRandom(255);
	randomBmutation = ofRandom(255);

}

void ofApp::update() {
	grabber.update();
	if (grabber.isFrameNew()) {
		ofPixels& pixels = grabber.getPixels();
		for (int y = 0; y < pixels.getHeight(); y++) {
			for (int x = 0; x < pixels.getWidth(); x++) {
				ofColor c = pixels.getColor(x, y);
				c.r = randomRmutation - c.r;
				c.g = randomGmutation - c.g;
				c.b = randomBmutation - c.b;

				workspace.setColor(x, y, c);
			}
		}
		image.setFromPixels(workspace);
	}

}
void ofApp::draw(){
	image.draw(0, 0, 320*3, 240 * 3);

	if (drawGrabbedImage) {
		grabber.draw(0, 0);
	}
	
}

void ofApp::keyPressed(int key){
	if (key == 'g') {
		drawGrabbedImage = !drawGrabbedImage;
	}
	else if (key == ' ') {
		randomRmutation = ofRandom(255);
		randomGmutation = ofRandom(255);
		randomBmutation = ofRandom(255);
	}
}


