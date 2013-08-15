//
//  ofxTimerModule.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimerSystem.h"
#include "ofxTimerCore.h"
#include "ofxTimerCoreSubclasses.h"
#include "ofxTimerModule.h"

ofxTimerModule::ofxTimerModule() {
    this->core = NULL;
}

ofxTimerModule::ofxTimerModule(ofxTimerCore *core,
                               unsigned int fireDuration,
                               unsigned long long startTime,
                               bool isOnce)
{
    this->core = core;
    
    this->fireDuration = fireDuration;
    this->remainTime = fireDuration;
    this->startTime = startTime;
    this->isOnce = isOnce;
    this->isRunning = true;
    this->isDead = false;
}

ofxTimerModule::ofxTimerModule(const ofxTimerModule &t) {
    this->core = t.core;
    
    this->fireDuration = t.fireDuration;
    this->remainTime = t.fireDuration;
    this->startTime = t.startTime;
    this->isOnce = t.isOnce;
    this->isRunning = t.isRunning;
    this->isDead = t.isDead;
    
}

ofxTimerModule::~ofxTimerModule() {
#ifdef OFX_TIMER_SYSTEM_DEBUG
    ofLogNotice() << "module is destructed";
#endif
}

ofxTimerModule &ofxTimerModule::operator=(const ofxTimerModule &t) {
    this->core = t.core;
    
    this->fireDuration = t.fireDuration;
    this->remainTime = t.fireDuration;
    this->startTime = t.startTime;
    this->isOnce = t.isOnce;
    this->isRunning = t.isRunning;
    this->isDead = t.isDead;
    
    return *this;
}

bool ofxTimerModule::bAlive() const {
    return !isDead;
};


void ofxTimerModule::stop() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        isRunning = false;
        isDead = true;
        delete core;
        core = NULL;
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModule::pause() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        isRunning = false;
        remainTime = startTime + fireDuration - ofGetElapsedTimeMillis();
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModule::resume() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        startTime = ofGetElapsedTimeMillis() - remainTime;
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModule::restart() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        isRunning = true;
        startTime = ofGetElapsedTimeMillis();
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModule::fire(unsigned long long &currentTime) {
    bool isFired = false;
    if(isRunning && (startTime + fireDuration <= currentTime)) {
        core->fireBody();
        isFired = true;
        startTime = currentTime;
    }
    if(isOnce && isFired) {
        isDead = true;
    }
}

void ofxTimerModule::clean() {
    if(core) {
        isRunning = false;
        isDead = true;
        delete core;
        core = NULL;
    }
}
