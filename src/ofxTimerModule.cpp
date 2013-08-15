//
//  ofxTimerModule.cpp
//
//  Created by ISHII 2bit.
//
//

#include "ofxTimerModuleSubclasses.h"
#include "ofxTimerSystem.h"

#pragma mark ofxTimerModule

ofxTimerModule::ofxTimerModule(unsigned int fireDuration,
                               unsigned long long startTime,
                               bool isOnce)
{
    this->fireDuration = fireDuration;
    this->remainTime = fireDuration;
    this->startTime = startTime;
    this->isOnce = isOnce;
    this->isRunning = true;
    this->isDead = false;
}

ofxTimerModule::~ofxTimerModule() {}

void ofxTimerModule::fire(unsigned long long &currentTime) {
    bool isFired = false;
    if(isRunning && (startTime + fireDuration <= currentTime)) {
        fireBody();
        isFired = true;
        startTime = currentTime;
        
        if(isOnce && isFired) {
            isDead = true;
        }
    }
}

#pragma mark -

#pragma mark ofxTimerModuleWrapper

ofxTimerModuleWrapper::ofxTimerModuleWrapper() {
    this->timer = NULL;
}

ofxTimerModuleWrapper::ofxTimerModuleWrapper(ofxTimerModule *timer) {
    this->timer = timer;
}

ofxTimerModuleWrapper::ofxTimerModuleWrapper(const ofxTimerModuleWrapper &t) {
    this->timer = t.timer;
}

ofxTimerModuleWrapper::~ofxTimerModuleWrapper() {
}

ofxTimerModuleWrapper &ofxTimerModuleWrapper::operator=(const ofxTimerModuleWrapper &t) {
    this->timer = t.timer;
    return *this;
}

bool ofxTimerModuleWrapper::bAlive() const {
    return !timer->isDead;
};


void ofxTimerModuleWrapper::stop() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        timer->isRunning = false;
        timer->isDead = true;
        delete timer;
        timer = NULL;
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModuleWrapper::pause() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        timer->isRunning = false;
        timer->remainTime = timer->startTime + timer->fireDuration - ofGetElapsedTimeMillis();
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModuleWrapper::resume() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        timer->startTime = ofGetElapsedTimeMillis() - timer->remainTime;
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModuleWrapper::restart() {
    ofxTimerSystem::sharedInstance->lock();
    if(bAlive()) {
        timer->isRunning = true;
        timer->startTime = ofGetElapsedTimeMillis();
    }
    ofxTimerSystem::sharedInstance->unlock();
}

void ofxTimerModuleWrapper::fire(unsigned long long currentTime) {
    if(timer != NULL && !timer->isDead) timer->fire(currentTime);
}

void ofxTimerModuleWrapper::clean() {
    if(timer) {
        timer->isRunning = false;
        timer->isDead = true;
        delete timer;
        timer = NULL;
    }
}

ofxTimer createTimerFromModule(ofxTimerModule *module) {
    ofxTimerModuleWrapperRef wrapper = ofxTimerModuleWrapperRef(new ofxTimerModuleWrapper(module));
    ofxTimer timer(wrapper);
    return timer;
}