//
//  ofxTimerModule.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerModule__
#define __ofxTimerModule__

#include "ofMain.h"

#include "ofxTimerSystemConfig.h"

class ofxTimerSystem;
class ofxTimer;

class ofxTimerModule {
    friend ofxTimerSystem;
    friend ofxTimer;
public:
    ofxTimerModule(ofxTimerCore *core, unsigned int fireDuration, unsigned long long startTime, bool isOnce);
    ofxTimerModule(const ofxTimerModule &t);
    ofxTimerModule &operator=(const ofxTimerModule &t);
    virtual ~ofxTimerModule();
    
private:
    ofxTimerModule();
    ofxTimerCore *core;
    
    void fire(unsigned long long &currentTime);
    void clean();
    
    unsigned long long startTime;
    unsigned int fireDuration;
    long long remainTime;
    bool isRunning;
    bool isOnce;
    bool isDead;
    
    bool bAlive() const;
    void stop();
    void pause();
    void resume();
    void restart();
};

typedef ofPtr<ofxTimerModule> ofxTimerModuleRef;

#endif /* defined(__ofxSetTimeoutExample__ofxTimer__) */
