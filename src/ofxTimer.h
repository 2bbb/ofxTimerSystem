//
//  ofxTimer.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimer__
#define __ofxTimer__

#include "ofMain.h"

#include "ofxTimerSystemConfig.h"

class ofxTimerSystem;
class ofxTimerModule;

class ofxTimer {
    typedef ofPtr<ofxTimerModule> ofxTimerModuleRef;
public:
    ofxTimer();
    ofxTimer(ofxTimerModuleRef module);
    ofxTimer &operator=(const ofxTimer &timer);
    
    bool bAlive() const;
    void stop();
    void pause();
    void resume();
    void restart();
    
    void clearTimer();
private:
    ofxTimerModuleRef module;
};

#endif /* defined(__ofxTimer__) */
