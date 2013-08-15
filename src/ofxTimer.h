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
class ofxTimerModuleWrapper;

class ofxTimer {
    typedef ofPtr<ofxTimerModuleWrapper> ofxTimerModuleWrapperRef;
public:
    ofxTimer();
    ofxTimer(ofxTimerModuleWrapperRef wrapper);
    ofxTimer &operator=(const ofxTimer &timer);
    
    bool bAlive() const;
    void stop();
    void pause();
    void resume();
    void restart();
    
    void clearTimer();
private:
    ofxTimerModuleWrapperRef wrapper;
};

#endif /* defined(__ofxTimer__) */
