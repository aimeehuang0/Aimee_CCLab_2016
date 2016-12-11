#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(ofVec2f position)
{
	mPosition = position;
	mEmitRate = 10;
	mIsAddingParticles = true;

}

void ParticleSystem::update(ofVec2f force) {
	//if(mParticleList.size()<5){
	if (mIsAddingParticles) {
		//push particles in the array
		Particle particle(mPosition);
		mParticleList.push_back(particle);
	}

	for (int i = 0; i < mParticleList.size(); i++)
	{
		//calculate the difference between center and particle position
		ofVec2f diff = ofVec2f(abs(mParticleList[i].mPosition.x - mPosition.x),abs(mParticleList[i].mPosition.y - mPosition.y));
	
		mParticleList[i].resetForce();
		//applying force to every particles
		mParticleList[i].applyForce(force);
		mParticleList[i].update(ofMap(diff.length(),0,200,4,1));
	
		if (diff.length() >= ofRandom(200, 400)) {
			//stop adding particle if there is any  particle of diff if higher than a certain length
			mIsAddingParticles = false;

			//erase this particle
			if (mParticleList.size() > 0)
			{
				mParticleList.erase(mParticleList.begin() + i);
			}
		}
	}
	mPosition += mVelocity;
}
void ParticleSystem::draw() {
	for (int i = 0; i < mParticleList.size(); i++)
	{
		mParticleList[i].draw();
	}
	
}