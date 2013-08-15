//
//  ofxTimer.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimer.h"
#include "ofxTimerModuleSubclasses.h"
#include "ofxTimerSystem.h"

ofxTimer::ofxTimer() {
}

ofxTimer::ofxTimer(ofxTimerModuleWrapperRef _wrapper) {
    wrapper = _wrapper;
    ofxTimerSystem::addTimer(wrapper);
}

ofxTimer &ofxTimer::operator=(const ofxTimer &timer) {
    wrapper = timer.wrapper;
}

inline bool ofxTimer::bAlive() const {
    return wrapper->timer != NULL;
};

inline void ofxTimer::stop() {
    return wrapper->stop();
}

inline void ofxTimer::pause() {
    return wrapper->pause();
}

inline void ofxTimer::resume() {
    return wrapper->resume();
}

inline void ofxTimer::restart() {
    return wrapper->restart();
}

void ofxTimer::clearTimer() {
    if(wrapper) wrapper->stop();
    wrapper.reset();
}