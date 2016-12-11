#include "Particle.h"


Particle::Particle(ofVec2f pos) {
	mPosition = pos;
	mVelocity = ofVec2f(ofRandom(-2.f, 2.f), ofRandom(-2.f, 2.f));
	mAcceleration = ofVec2f(0, 0);
	mLifeSpan = 255.f;
}

void Particle::resetForce() {
	mAcceleration *= 0;
}

void Particle::applyForce(ofVec2f force) {
	mAcceleration += force;
}

void Particle::update(float multiplier) {
	mVelocity += mAcceleration;
	//farther the particle is from the center, less the velocity
	mPosition += mVelocity * multiplier;

	if (mLifeSpan > 0) {
		mLifeSpan -= 2.f;
	}
}

void Particle::draw() {
	/*if (mLifeSpan > 100)
	{
	ofSetColor(mLifeSpan,ofRandom(50,150),ofRandom(100,250));
	}
	else if (mLifeSpan <= 100)
	{*/
		ofSetColor(mLifeSpan, ofRandom(50, 150), ofRandom(100, 250));
	//}

	ofDrawCircle(mPosition, 20.f * ofMap(ofRandom(50, 100), 0, 255.f, 0, 1.f));
}