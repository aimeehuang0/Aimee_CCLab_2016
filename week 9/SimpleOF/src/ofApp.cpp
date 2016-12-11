#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255);
	ofSetColor(255.f, 0, 0);
	mCircleRadius = 20.f;
	ofSetCircleResolution(100.f);
	
	rectPos = ofVec2f((ofGetWindowWidth() * 0.5)-(rectSize/2) - rectDis, (ofGetWindowHeight()*0.5) - (rectSize / 2) - rectDis);
	dragC = ofVec2f(0,0);
	noCircle = 0; noFCircle = 0;
		
	velocity = 0.0;
	gravity = 0.81;
}

//--------------------------------------------------------------
void ofApp::update(){
	dragC;
	//velocity = velocity + gravity;
	if (noFCircle > 0) {
		for (int f = 0; f < noFCircle; f++)
		{
			if (fpts[f].y < 0 ) fpts[f].z = 0;
			if (fpts[f].y > ofGetWindowHeight()) fpts[f].z = 1;
			
			if (fpts[f].z == 0) {
				fpts[f].y += gravity;
			}
			else
			{
				fpts[f].y -= gravity;
			}

		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	//draw gravity circle
	ofSetColor(0);
	if (noFCircle > 0) {
		for (int f = 0; f < noFCircle; f++)
		{
			ofSetColor((int)ofRandom(100,200), (int)ofRandom(100, 200), (int)ofRandom(100, 200));
			ofDrawCircle(fpts[f].x, fpts[f].y, 10);
		}
	}
	
	ofSetColor(255, 0, 0);
	//draw circle
	if (noCircle > 1) {
		for (int i = 0; i < noCircle - 1; i++)
		{
			ofDrawCircle(pts[i].x, pts[i].y, mCircleRadius);
		}
	}

	ofSetColor(255.f, 0, 0);
	
	//guide circle
	ofDrawCircle(dragC, mCircleRadius);

	//circle point
	ofRectangle rect;
	rect.x = rectPos.x;
	rect.y = rectPos.y;
	rect.width = rectSize;
	rect.height = rectSize;

	ofSetColor(209.f, 211.f, 212.f);
	for (int y = 0; y < rectDis *3; y += rectDis)
	{
		rect.y = rectPos.y + y;
		for (int x = 0; x < rectDis*3; x += rectDis)
		{
			rect.x = rectPos.x + x;
			ofDrawRectangle(rect);
		}
	}


	//write instruction
	ofSetColor(0);
	ofTranslate(ofGetWindowWidth() / 4, 30);
	ofDrawBitmapString(" Arrow Up = increase size |  Arrow Down = decrease size | drag to draw ", 0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_UP) mCircleRadius += 1;
	if (key == OF_KEY_DOWN) mCircleRadius -= 1;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	dragC.x = x; dragC.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
	//draw circle array
	if (noCircle < MAX_Circle) {
		pts[noCircle].x = x;
		pts[noCircle].y = y;
		noCircle++;
	}

	//guide circle
	dragC.x = x; dragC.y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
	//if( y+velocity > ofGetWindowHeight()) velocity = 0;
	//std::cout << "x=" << x << " y= " << y << " velocity= " << velocity << endl;
	//ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	if (noFCircle < MAX_Circle) {
		fpts[noFCircle].x = x;
		fpts[noFCircle].y = y;
		noFCircle++;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	noCircle = 0;
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
