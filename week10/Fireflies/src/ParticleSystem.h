#pragma once

#include "ofMain.h"
#include "Particle.h"

class ParticleSystem {
public:

	ParticleSystem(ofVec2f position);
	void update(ofVec2f force);
	void draw();

	ofVec2f mPosition,mVelocity;
	int		mEmitRate;
	bool	mIsAddingParticles;
	bool	mCollide = false;
	vector<Particle> mParticleList;
	
	
};
