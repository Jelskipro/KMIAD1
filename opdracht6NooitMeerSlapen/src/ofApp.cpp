#include "ofApp.h"

void ofApp::setup(){
	videoGrabber.listDevices();

	videoGrabber.setDeviceID(0);
	videoGrabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
	videoGrabber.setDesiredFrameRate(30);

	workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);

}

void ofApp::update(){
	videoGrabber.update();

	if (videoGrabber.isFrameNew()) {
		ofPixels& pixels = videoGrabber.getPixels();
		for (size_t y = 0; y < pixels.getHeight(); y++) {
			for (size_t x = 0; x < pixels.getWidth(); x++) {

				ofColor col = pixels.getColor(drawLeft ? x : pixels.getWidth() - x, y);

				workspace.setColor(x, y, col);
				workspace.setColor(pixels.getWidth() - x, y, col);
			}
		}

		image.setFromPixels(workspace);
		image.mirror(false, true);
	}
}

void ofApp::draw(){
	//Randoms voor spooky teleporting effect
	image.draw(0, 0, CAM_WIDTH * 3 * ofRandom(3), CAM_HEIGHT * 3 * ofRandom(3));
}

void ofApp::keyPressed(int key){
	 if (key == ' ') {
        drawLeft = !drawLeft;
    }
}

