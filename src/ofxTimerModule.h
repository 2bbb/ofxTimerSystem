//
//  ofxTimerModule.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerModule__
#define __ofxTimerModule__

#include "ofMain.h"

class ofxTimerSystem;
class ofxTimerModuleWrapper;
class ofxTimer;

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

#if __has_extension(blocks)
typedef void (^ofxTimerBlocks)(void);
#endif

#if __has_feature(cxx_lambdas)

#include <tr1/functional>
using std::tr1::function;
typedef function<void(void)> ofxTimerLambda;

#endif

#endif /* defined(__ofxSetTimeoutExample__ofxTimer__) */
