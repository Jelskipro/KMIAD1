#include "ofApp.h"


void ofApp::setup(){
	conePrimitive = ofConePrimitive(coneRadius, coneHeight, coneRadiusSegments, coneHeightSegments);
	spherePrimitive.setRadius(sphereRadius);

	conePrimitive.setMode(OF_PRIMITIVE_TRIANGLES);
	spherePrimitive.setMode(OF_PRIMITIVE_TRIANGLES);

}

void ofApp::update(){
	vector<ofMeshFace> triangles = conePrimitive.getMesh().getUniqueFaces();

	float displacement = sin(ofGetElapsedTimef() * 400) * 100;
	for (int i = 0; i < triangles.size(); i++) {
		ofVec3f faceNormal = triangles[i].getFaceNormal();
		for (int j = 0; j < 3; j++) {
			triangles[i].setVertex(j, triangles[i].getVertex(j) + faceNormal * displacement);
		}
	}

	conePrimitive.getMesh().setFromTriangles(triangles);
	
	vector<ofMeshFace> trianglesSphere = spherePrimitive.getMesh().getUniqueFaces();

	float displacementSphere = sin(ofGetElapsedTimef() * 4) * 10;
	for (int i = 0; i < trianglesSphere.size(); i++) {
		ofVec3f faceNormalSphere = trianglesSphere[i].getFaceNormal();
		for (int j = 0; j < 3; j++) {
			trianglesSphere[i].setVertex(j, trianglesSphere[i].getVertex(j) + faceNormalSphere * displacementSphere);
		}
	}
	spherePrimitive.getMesh().setFromTriangles(trianglesSphere);

}

void ofApp::draw(){
	ofBackground(ofColor::black);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	//primitive.draw();
	conePrimitive.drawWireframe();
	spherePrimitive.drawWireframe();

}

