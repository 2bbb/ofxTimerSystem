#include "testApp.h"

void testApp::timeoutFunction1() {
    state += 1;
    state = state % 4;
}

void testApp::timeoutFunction2(Arg *arg) {
    arg->state += 1;
    arg->state = arg->state % 4;
    t = ofxSetInterval(this, &testApp::timeoutFunction1, 10);
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetColor(255, 255, 255);
    
    state = 0;
    ofxSetTimeout(this, &testApp::timeoutFunction1, 500);
    ofxSetTimeout(this, &testApp::timeoutFunction1, 1000);
    ofxSetTimeout(this, &testApp::timeoutFunction2, new Arg(state), 1500);
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
    switch (state) {
        case 0:
            ofBackground(0, 0, 0);
            break;
        case 1:
            ofBackground(255, 0, 0);
            break;
        case 2:
            ofBackground(0, 255, 0);
            break;
        case 3:
            ofBackground(0, 0, 255);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == ' ') t.clearTimer();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
