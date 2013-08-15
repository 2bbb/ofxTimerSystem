//
//  ofxTimerCore.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimerCore.h"
#include "ofxTimerModule.h"
#include "ofxTimer.h"

ofxTimerCore::ofxTimerCore() {}

ofxTimerCore::~ofxTimerCore() {
#ifdef OFX_TIMER_SYSTEM_DEBUG
    ofLogNotice() << "core is destructed";
#endif
}

ofxTimer createTimerFromCore(ofxTimerCore *core,
                             unsigned int fireDuration,
                             unsigned long long startTime,
                             bool isOnce)
{
    ofxTimerModuleRef module = ofxTimerModuleRef(new ofxTimerModule(core, fireDuration, startTime, isOnce));
    ofxTimer timer(module);
    return timer;
}