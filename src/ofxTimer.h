//
//  ofxTimer.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimer__
#define __ofxTimer__

#include "ofMain.h"

class ofxTimerSystem;
class ofxTimer;

class ofxTimerModule {
    friend ofxTimerSystem;
    friend ofxTimer;
public:
    ofxTimerModule(unsigned int fireDuration, unsigned long long startTime, bool isOnce);
    virtual ~ofxTimerModule();
protected:
    unsigned long long startTime;
    unsigned int fireDuration;
    long long remainTime;
    virtual void fireBody() = 0;
    bool isRunning;
    bool isOnce;
    bool fire(unsigned long long &currentTime);
};

class ofxTimer  {
    friend ofxTimerSystem;
public:
    ofxTimer(ofxTimerModule *timer);
    ofxTimer(const ofxTimer &t);
    ofxTimer &operator=(const ofxTimer &t);
    virtual ~ofxTimer();
    
    bool bAlive() const {
        while(mute) ofSleepMillis(1);
        return timer != NULL;
    };
    
    bool stop();
    bool pause();
    bool resume();
    bool restart();
private:
    bool mute;
    ofxTimer();
    bool fire(unsigned long long currentTime);
    void clean();
    ofxTimerModule *timer;
};

typedef ofPtr<ofxTimer> ofxTimerRef;

#endif /* defined(__ofxSetTimeoutExample__ofxTimer__) */
