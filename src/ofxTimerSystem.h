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

class ofxTimerSystem : public ofThread {
    typedef vector<ofxTimerRef> Timers;
public:
    static void addTimer(ofxTimerRef timer);
    static void removeTimer(ofxTimerRef timer);
    static void removeTimer(ofxTimer *timer);
    void threadedFunction();
private:
    ofxTimerSystem();
    static ofxTimerSystem *sharedInstance;
    static Timers timers;
};


#endif /* defined(__ofxTimerSystem__) */
