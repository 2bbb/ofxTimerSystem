//
//  ofxTimer.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimer.h"
#include "ofxTimerSystem.h"
#include "ofxSetTimeoutThread.h"

ofxTimerModule::ofxTimerModule(unsigned int fireDuration, unsigned long long startTime, bool isOnce) {
    this->fireDuration = fireDuration;
    this->remainTime = fireDuration;
    this->startTime = startTime;
    this->isOnce = isOnce;
    this->isRunning = true;
}

ofxTimerModule::~ofxTimerModule() {
    ofLogWarning() << "timer module destructed";
}

bool ofxTimerModule::fire(unsigned long long &currentTime) {
    bool isFired = false;
    if(isRunning && (startTime + fireDuration <= currentTime)) {
        fireBody();
        isFired = true;
        startTime = currentTime;
    }
    return isOnce && isFired;
}

ofxTimer::ofxTimer() {
    this->timer = NULL;
    mute = false;
}

ofxTimer::ofxTimer(ofxTimerModule *timer) {
    this->timer = timer;
    mute = false;
}

ofxTimer::ofxTimer(const ofxTimer &t) {
    this->timer = t.timer;
    mute = false;
}

ofxTimer::~ofxTimer() {
    ofLogWarning() << "timer destructed";
}

ofxTimer &ofxTimer::operator=(const ofxTimer &t) {
    mute = false;
    this->timer = t.timer;
    return *this;
}

bool ofxTimer::stop() {
    if(bAlive()) {
        timer->isRunning = false;
        ofxTimerSystem::removeTimer(this);
        timer = NULL;
    }
}

bool ofxTimer::pause() {
    if(bAlive()) {
        timer->isRunning = false;
        timer->remainTime = timer->startTime + timer->fireDuration - ofGetElapsedTimeMillis();
    }
}

bool ofxTimer::resume() {
    if(bAlive()) {
        timer->startTime = ofGetElapsedTimeMillis() - timer->remainTime;
    }
}

bool ofxTimer::restart() {
    if(bAlive()) {
        timer->isRunning = true;
        timer->startTime = ofGetElapsedTimeMillis();
    }
}

bool ofxTimer::fire(unsigned long long currentTime) {
    mute = false;
    return bAlive() && timer->fire(currentTime);
}


void ofxTimer::clean() {
    mute = true;
    timer->isRunning = false;
    delete timer;
    timer = NULL;
    mute = false;
}
