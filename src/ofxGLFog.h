#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofxGLFog {

public:
    ofxGLFog();
    virtual ~ofxGLFog();


	void setFogColor(ofFloatColor &fogColor);
	void setFogMode(int &fogMode);
	void setDensity(float &density);
	void setFogStart( float &fogStart );
	void setFogEnd( float &fogEnd );
	bool enableCoordinate(bool& enable);

	void enable();
 	void disable();
	bool isEnabled();
	
 	ofFloatColor getFogColor();
	int getFogMode();
	float getDensity();
	float getFogStart();
    float getFogEnd();
	
	GLenum getGlFogMode(int i);

	void drawGui();
	ofxPanel gui;
	ofParameterGroup parameters;
	
protected:
	void setFog();
	bool bIsEnabled;
 	ofParameter<int> fogMode;
    ofParameter<ofFloatColor> fogColor;
	ofParameter<float> density, fogStart, fogEnd;
    ofParameter<bool> bEnableFogCoordinate;

};
















