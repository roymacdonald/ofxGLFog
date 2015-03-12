#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
	cam.enableMouseInput();
	bEnableFog =true;
	ofMatrix4x4 m(0.721631, 0.00136599, 0.692276, 0,0.158998, 0.972939, -0.16766, 0, -0.673771,  0.23106, 0.701886,0, -235.597,   179.47,  270.957, 1);// ignore this.it is just for placing the camera
	cam.setTransformMatrix(m);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::white, ofColor(150));
	cam.begin();
	ofEnableDepthTest();//<-------------- important line, yet optional
	if(bEnableFog){
		fog.enable();//<----------------- important line. must use.
	}
	//Just draw whatever you want. Here we will draw some boxes.
	ofSetColor(255,0,0);
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			ofDrawBox(j*100, 0, -i*100, 60);
		}
	}
	
	if(bEnableFog){
		fog.disable();//<----------------- important line. must use.
	}
	ofDisableDepthTest();//<-------------- important line, yet optional
	cam.end();
	fog.drawGui();//<--------------------- use this to draw the gui. remember to put it after cam.end() if you are using a camera.

	//------- just some stuff to draw instructions.
	string s ="press the spacebar to toggle fog";
	ofBitmapFont f;
	ofRectangle r = f.getBoundingBox(s, 0, 0);
	ofSetColor(0);
	ofDrawBitmapString(s, (ofGetWidth() - r.width)*0.5f, ofGetHeight() - 20 - r.height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		bEnableFog ^= true;
	}
}
