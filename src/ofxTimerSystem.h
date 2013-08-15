//
//  ofxTimerSystem.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerSystem__
#define __ofxTimerSystem__

#include "ofMain.h"

#include "ofxTimerSystemConfig.h"
#include "ofxTimer.h"
#include "ofxTimerSystemFunctions.h"

class ofxTimerCore;
class ofxTimerModule;

class ofxTimerSystem : public ofThread {
    typedef ofPtr<ofxTimerModule> ofxTimerModuleRef;
    typedef vector<ofxTimerModuleRef> Timers;
    
    friend ofxTimerCore;
    friend ofxTimerModule;
    friend ofxTimer;
public:
    void threadedFunction();
private:
    ofxTimerSystem();
    static void addTimer(ofxTimerModuleRef timer);
    void addTimerWithLock(ofxTimerModuleRef timer);
    static void removeTimer(ofxTimerModuleRef timer);
    static void removeTimer(ofxTimerModule *timer);
    void removeTimerWithLock(ofxTimerModule *timer);
    static ofxTimerSystem *sharedInstance;
    static Timers timers;
};

#endif /* defined(__ofxTimerSystem__) */
