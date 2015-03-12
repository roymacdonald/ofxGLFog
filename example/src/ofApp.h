#pragma once

#include "ofMain.h"
#include "ofxGLFog.h"

class ofApp : public ofBaseApp{
public:
	void setup();
	void draw();
	
	void keyPressed(int key);
	
	ofxGLFog fog;
	ofEasyCam cam;
	bool bEnableFog;
};
