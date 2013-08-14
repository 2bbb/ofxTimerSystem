//
//  ofxTimerSystem.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimerSystem.h"
#include "ofxTimer.h"

ofxTimerSystem::ofxTimerSystem() {
    startThread(true, false);
}

void ofxTimerSystem::addTimer(ofxTimerRef timer) {
    if(sharedInstance == NULL) {
        sharedInstance = new ofxTimerSystem();
    }
    timers.push_back(timer);
}

void ofxTimerSystem::removeTimer(ofxTimerRef timer) {
    if(sharedInstance == NULL) {
        sharedInstance = new ofxTimerSystem();
    }
    Timers::iterator it = remove(timers.begin(), timers.end(), timer);
    timers.erase(it, timers.end());
}

void ofxTimerSystem::removeTimer(ofxTimer *timer) {
    if(sharedInstance == NULL) {
        sharedInstance = new ofxTimerSystem();
    }
    Timers::iterator it = timers.begin();
    for(; it != timers.begin(); it++) {
        if(it->get() == timer) timers.erase(it);
    }
}

void ofxTimerSystem::threadedFunction() {
    Timers::iterator it;
    while(true) {
        if(timers.size()) {
            lock();
            unsigned long long currentTime = ofGetElapsedTimeMillis();
            
            for(it = timers.begin(); it != timers.end(); it++) {
                if((*it)->fire(currentTime)) {
                    it = timers.erase(it);
                    if(it == timers.end()) break;
                }
            }
            unlock();
        }
        ofSleepMillis(1);
    }
}

ofxTimerSystem *ofxTimerSystem::sharedInstance = NULL;
ofxTimerSystem::Timers ofxTimerSystem::timers;
