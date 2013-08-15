//
//  ofxTimerCore.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerCore__
#define __ofxTimerCore__

#include "ofMain.h"

#include "ofxTimerSystemConfig.h"

class ofxTimerSystem;
class ofxTimerModule;
class ofxTimer;

#pragma mark ofxTimerModule

class ofxTimerCore {
    friend ofxTimerSystem;
    friend ofxTimerModule;
public:
    ofxTimerCore();
    virtual ~ofxTimerCore();
protected:
    virtual void fireBody() = 0;
};

ofxTimer createTimerFromCore(ofxTimerCore *core, unsigned int fireDuration, unsigned long long startTime, bool isOnce);

#endif /* defined(__ofxTimerCore__) */
