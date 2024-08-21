#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 1.44);

	for (int base_x = -240; base_x <= 240; base_x += 10) {

		for (int base_z = -240; base_z <= 240; base_z += 10) {

			auto noise_value = ofMap(ofNoise(base_x * 0.005, base_z * 0.005, ofGetFrameNum() * 0.0085), 0, 1, 0, 10);
			int int_noise_value = noise_value;

			for (int i = 0; i < 10; i++) {

				if (i < int_noise_value) {

					ofPushMatrix();
					ofTranslate(base_x, -150 + i * 10, base_z);

					ofSetColor(0);
					ofFill();
					ofDrawBox(9.5);

					ofSetColor(255);
					ofNoFill();
					ofDrawBox(10);

					ofPopMatrix();
				}
				else if (int_noise_value < i) {

					ofPushMatrix();
					ofTranslate(base_x, 150 - (10 - i) * 10, base_z);

					ofSetColor(0);
					ofFill();
					ofDrawBox(9.5);

					ofSetColor(255);
					ofNoFill();
					ofDrawBox(10);

					ofPopMatrix();
				}
				else {

				}
			}
		}
	}

	this->cam.end();

	/*
	int start = 500;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}