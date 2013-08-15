//
//  ofxTimer.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimer.h"
#include "ofxTimerCore.h"
#include "ofxTimerModule.h"
#include "ofxTimerSystem.h"

ofxTimer::ofxTimer() {}

ofxTimer::ofxTimer(ofxTimerModuleRef module) {
    this->module = module;
    ofxTimerSystem::addTimer(module);
}

ofxTimer &ofxTimer::operator=(const ofxTimer &timer) {
    module = timer.module;
}

inline bool ofxTimer::bAlive() const {
    return module->core != NULL;
};

inline void ofxTimer::stop() {
    return module->stop();
}

inline void ofxTimer::pause() {
    return module->pause();
}

inline void ofxTimer::resume() {
    return module->resume();
}

inline void ofxTimer::restart() {
    return module->restart();
}

void ofxTimer::clearTimer() {
    if(module) module->stop();
    module.reset();
}