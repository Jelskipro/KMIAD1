#include "ofApp.h"


void ofApp::setup(){
	primitive = ofConePrimitive(coneRadius, coneHeight, coneRadiusSegments, coneHeightSegments);

	primitive.setMode(OF_PRIMITIVE_TRIANGLES);
}

void ofApp::update(){
	vector<ofMeshFace> triangles = primitive.getMesh().getUniqueFaces();

	float displacement = sin(ofGetElapsedTimef() * 4) * 10;
	for (int i = 0; i < triangles.size(); i++) {
		ofVec3f faceNormal = triangles[i].getFaceNormal();
		for (int j = 0; j < 3; j++) {
			triangles[i].setVertex(j, triangles[i].getVertex(j) + faceNormal * displacement);
		}
	}

	primitive.getMesh().setFromTriangles(triangles);
}

void ofApp::draw(){
	ofBackground(ofColor::black);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	//primitive.draw();
	primitive.drawWireframe();

}

