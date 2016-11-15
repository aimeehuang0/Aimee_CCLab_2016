#pragma once

#include "ofMain.h"

class Particle {
public:

	Particle(ofVec2f pos);

	void update(float multiplier);
	void draw();
	void applyForce(ofVec2f force);
	void resetForce();

	ofVec2f mPosition, mVelocity, mAcceleration;
	float mLifeSpan;
};