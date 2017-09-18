#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 0, 200));
	gui.add(speedX.set("SpeedX", 50, 0, 200));
	gui.add(speedY.set("SpeedY", 50, 0, 200));
	gui.add(color.set("Color", ofColor::white));

	ofSetWindowShape(800, 600);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i<balls.size(); i++) {
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
	for (int i = 0; i<balls.size(); i++) {
		balls[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		ofLog() << "SPATIE" << endl;
		Ball myBall;
		myBall.setup(radius, speedX, speedY, color);
		balls.push_back(myBall);
	
	}
	else
	{
		ofLog() << "er is op een toets gedrukt" << endl;
		
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
