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
class ofxTimerModuleWrapper;
class ofxTimer;

#pragma mark ofxTimerModule

class ofxTimerModule {
    friend ofxTimerSystem;
    friend ofxTimerModuleWrapper;
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
    bool isDead;
    void fire(unsigned long long &currentTime);
};

#pragma mark -

#pragma mark ofxTimerModuleWrapper

class ofxTimerModuleWrapper {
    friend ofxTimerSystem;
    friend ofxTimer;
public:
    ofxTimerModuleWrapper(ofxTimerModule *timer);
    ofxTimerModuleWrapper(const ofxTimerModuleWrapper &t);
    ofxTimerModuleWrapper &operator=(const ofxTimerModuleWrapper &t);
    virtual ~ofxTimerModuleWrapper();
    
private:
    ofxTimerModuleWrapper();
    void fire(unsigned long long currentTime);
    void clean();
    ofxTimerModule *timer;
    
    bool bAlive() const;
    void stop();
    void pause();
    void resume();
    void restart();
};

typedef ofPtr<ofxTimerModuleWrapper> ofxTimerModuleWrapperRef;

ofxTimer createTimerFromModule(ofxTimerModule *module);

#endif /* defined(__ofxSetTimeoutExample__ofxTimer__) */
