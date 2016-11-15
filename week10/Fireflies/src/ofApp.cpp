#include "ofApp.h"
//base

//--------------------------------------------------------------
void ofApp::setup(){
	mGravity = ofVec2f(0.f, 0.02f);
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < mSystems.size(); i++)
	{
		mSystems[i].update(mGravity);

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < mSystems.size(); i++)
	{
		mSystems[i].draw();
	}

	for (int i = 0; i < mSystems.size() - 1; i++) {
		for (int j = i + 1; j < mSystems.size(); j++) {
			pDist.resize(mSystems.size() - 1);
			//pDist[i] = ofDist(0.1, 0.20,0.10,0.5);
			pDist[i] = ofDist(mSystems[i].mPosition.x, mSystems[i].mPosition.y, mSystems[j].mPosition.x, mSystems[j].mPosition.y);
			cout << pDist[i] << endl;
			if (pDist[i] <= 50) {
				mSystems[i].mVelocity.x *= -1;
				mSystems[i].mVelocity.y *= -1;
				mSystems[j].mVelocity.x *= -1;
				mSystems[j].mVelocity.y *= -1;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//create new particle system after press
	ParticleSystem system(ofVec2f(x, y));
	mSystems.push_back(system);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
