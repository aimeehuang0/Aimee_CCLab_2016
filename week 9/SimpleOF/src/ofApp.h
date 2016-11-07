#pragma once

#include "ofMain.h"

#define MAX_Circle 3000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		float mCircleRadius;
		float velocity;
		float gravity;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofPoint pts[MAX_Circle];
		ofPoint fpts[MAX_Circle];

		int noCircle = 0;
		int noFCircle = 0;
		int nPts;
		int rectSize=30,rectDis=100;
		ofVec2f rectPos;
		ofVec2f dragC;

		//ofVec2f guideC;
};
