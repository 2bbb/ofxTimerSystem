//
//  ofxTimerSystem.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerSystem__
#define __ofxTimerSystem__

#include "ofMain.h"
#include "ofxTimer.h"

class ofxTimerModule;
class ofxTimerModuleWrapper;

class ofxTimerSystem : public ofThread {
    typedef ofPtr<ofxTimerModuleWrapper> ofxTimerModuleWrapperRef;
    typedef vector<ofxTimerModuleWrapperRef> Timers;
    
    friend ofxTimerModule;
    friend ofxTimerModuleWrapper;
    friend ofxTimer;
public:
    void threadedFunction();
private:
    ofxTimerSystem();
    static void addTimer(ofxTimerModuleWrapperRef timer);
    void addTimerWithLock(ofxTimerModuleWrapperRef timer);
    static void removeTimer(ofxTimerModuleWrapperRef timer);
    static void removeTimer(ofxTimerModuleWrapper *timer);
    void removeTimerWithLock(ofxTimerModuleWrapper *timer);
    static ofxTimerSystem *sharedInstance;
    static Timers timers;
};

#include "ofxSetTimeout.h"
#include "ofxSetInterval.h"

#endif /* defined(__ofxTimerSystem__) */
