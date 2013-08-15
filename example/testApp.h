#pragma once

#include "ofMain.h"
#include "ofxTimerSystem.h"

class Arg {
public:
    Arg(int &_state) : state(_state) {};
    int &state;
};

class testApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    void timeoutFunction1();
    void timeoutFunction2(Arg *arg);
    int state;
    
    ofxTimer t;

#if __has_extension(blocks)
    bool blocksBindValue;
#endif
    
#if __has_feature(cxx_lambdas)
    bool lambdaBindValue;
#endif

};