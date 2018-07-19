#include "ofxGLFog.h"

ofxGLFog::ofxGLFog():bIsEnabled(false){

	parameters.setName("Fog Params");
	parameters.add(fogMode.set("fog Mode",2,0,2));
	parameters.add(fogColor.set("Color", ofColor::white, ofColor::white,ofColor(0,0,0,0)));
	parameters.add(density.set("density",0.001f, 0, 0.01f ));
	parameters.add(fogStart.set("fogStart", 1000, -20000,20000));
	parameters.add(fogEnd.set("fogEnd", -15000, -20000,20000));
	parameters.add(bEnableFogCoordinate.set("enableFogCoordinate", false));
	
	fogMode.addListener(this, &ofxGLFog::setFogMode);
	fogColor.addListener(this, &ofxGLFog::setFogColor);
	density.addListener(this, &ofxGLFog::setDensity);
	fogStart.addListener(this, &ofxGLFog::setFogStart);
	fogEnd.addListener(this, &ofxGLFog::setFogEnd);
	bEnableFogCoordinate.addListener(this, &ofxGLFog::enableCoordinate);
	
	gui.setup("Fog Settings", "Fog_Settings.xml");
	gui.add(parameters);
	gui.loadFromFile("Fog_Settings.xml");
	
}


ofxGLFog::~ofxGLFog(){
	
	fogMode.removeListener(this, &ofxGLFog::setFogMode);
	fogColor.removeListener(this, &ofxGLFog::setFogColor);
	density.removeListener(this, &ofxGLFog::setDensity);
	fogStart.removeListener(this, &ofxGLFog::setFogStart);
	fogEnd.removeListener(this, &ofxGLFog::setFogEnd);
	bEnableFogCoordinate.removeListener(this, &ofxGLFog::enableCoordinate);
}

void ofxGLFog::setFog(){
    GLfloat fogCol[4] = { fogColor->r, fogColor->g, fogColor->b, fogColor->a };

    glFogi(GL_FOG_MODE, getGlFogMode(fogMode) );
    glFogfv(GL_FOG_COLOR, fogCol);
    glFogf(GL_FOG_DENSITY, density);
    glHint(GL_FOG_HINT, GL_DONT_CARE);
    glFogf(GL_FOG_START, fogStart);
    glFogf(GL_FOG_END, fogEnd);

    if(bEnableFogCoordinate){
        glFogi(GL_FOG_COORD_SRC, GL_FOG_COORD);
    }else {
        glFogi(GL_FOG_COORD_SRC, GL_FRAGMENT_DEPTH);
    }
}

void ofxGLFog::setFogColor(ofFloatColor& fogColor){
    this->fogColor=fogColor;
	setFog();
}

void ofxGLFog::setFogMode(int &fogMode){
    this->fogMode = fogMode;
	setFog();
}

void ofxGLFog::setDensity(float& density){
    this->density = density;
	setFog();
}
void ofxGLFog::setFogStart( float& fogStart){
    this->fogStart = fogStart;
	setFog();
}

void ofxGLFog::setFogEnd(float& fogEnd ){
    this->fogEnd = fogEnd;
	setFog();
}

bool ofxGLFog::enableCoordinate(bool & enable){
	bEnableFogCoordinate = enable;
	setFog();
	return true;
}

void ofxGLFog::enable(){
	if (!bIsEnabled) {
		setFog();
		bIsEnabled = true;
	}
    glEnable(GL_FOG);
}

void ofxGLFog::disable(){
    glDisable(GL_FOG);
	bIsEnabled = false;
}

GLenum ofxGLFog::getGlFogMode(int i){
	switch (i) {
		case 0:
			return GL_LINEAR;
			break;
		case 1:
			return GL_EXP;
			break;
		case 2:
			return GL_EXP2;
			break;
		default:
			return 0;
			break;
	}
}
bool ofxGLFog::isEnabled(){
	return bIsEnabled;
}
ofFloatColor ofxGLFog::getFogColor(){
    return fogColor.get();
}

int ofxGLFog::getFogMode(){
    return fogMode;
}

float ofxGLFog::getDensity(){
    return density;
}

float ofxGLFog::getFogStart(){
    return fogStart;
}

float ofxGLFog::getFogEnd(){
    return fogEnd;
}
void ofxGLFog::drawGui(){
	gui.draw();
}