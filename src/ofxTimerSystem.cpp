//
//  ofxTimerSystem.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimerSystem.h"
#include "ofxTimerModule.h"

ofxTimerSystem::ofxTimerSystem() {
    startThread(true, false);
}

void ofxTimerSystem::addTimer(ofxTimerModuleRef timer) {
    if(sharedInstance == NULL) {
        sharedInstance = new ofxTimerSystem();
    }
    sharedInstance->addTimerWithLock(timer);
}

void ofxTimerSystem::addTimerWithLock(ofxTimerModuleRef timer) {
    timers.push_back(timer);
}

void ofxTimerSystem::removeTimer(ofxTimerModuleRef timer) {
    removeTimer(timer.get());
}

void ofxTimerSystem::removeTimer(ofxTimerModule *timer) {
    if(sharedInstance == NULL) {
        sharedInstance = new ofxTimerSystem();
    }
    sharedInstance->removeTimerWithLock(timer);
}

void ofxTimerSystem::removeTimerWithLock(ofxTimerModule *timer) {
    Timers::iterator it = timers.begin();
    for(; it != timers.end(); it++) {
        if(it->get() == timer) {
            it = timers.erase(it);
        }
    }
}

void ofxTimerSystem::threadedFunction() {
    Timers::iterator it;
    while(isThreadRunning()) {
        if(timers.size()) {
            unsigned long long currentTime = ofGetElapsedTimeMillis();
            
            for(it = timers.begin(); it != timers.end(); it++) {
                lock();
                (*it)->fire(currentTime);
                unlock();
            }
            
            for(it = timers.begin(); it != timers.end(); it++) {
                lock();
                if((*it)->core != NULL && !(*it)->bAlive()) {
                    (*it)->clean();
                    it = timers.erase(it);
                    if(it == timers.end()) break;
                }
                unlock();
            }
        }
        ofSleepMillis(10);
    }
}

ofxTimerSystem *ofxTimerSystem::sharedInstance = NULL;
ofxTimerSystem::Timers ofxTimerSystem::timers;
