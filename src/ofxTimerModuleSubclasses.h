//
//  ofxTimer.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerModuleSubclasses__
#define __ofxTimerModuleSubclasses__

#include "ofMain.h"

#include "ofxTimerSystemConfig.h"
#include "ofxTimerModule.h"

template <class Class>
class ofxTimerWithFunctionAndClass : public ofxTimerModule {
public:
    friend class ofxTimerCycle;
    ofxTimerWithFunctionAndClass(Class *c, void (Class::*func)(), unsigned long long fire, bool isOnce = true) : ofxTimerModule(fire, ofGetElapsedTimeMillis(), isOnce) {
        this->c = c;
        this->func = func;
    }
    
    virtual ~ofxTimerWithFunctionAndClass() {};
    virtual void fireBody() {
        (c->*func)();
    }
private:
    Class *c;
    void (Class::*func)();
};

template <class Class, class Argument>
class ofxTimerWithClassAndArguments : public ofxTimerModule {
    friend class ofxTimerCycle;
public:
    ofxTimerWithClassAndArguments(Class *c, void (Class::*func)(Argument *), Argument *arg, unsigned long long fire, bool isOnce = true) : ofxTimerModule(fire, ofGetElapsedTimeMillis(), isOnce)  {
        this->c = c;
        this->func = func;
        this->arg = arg;
    }
    
    virtual ~ofxTimerWithClassAndArguments() {
        delete arg;
    }
    virtual void fireBody() {
        (c->*func)(arg);
    }
    
private:
    Class *c;
    void (Class::*func)(Argument *);
    Argument *arg;
};

#if OFX_TIMER_SYSTEM_ENABLE_BLOCKS

class ofxTimerWithBlocks : public ofxTimerModule {
public:
    ofxTimerWithBlocks(ofxTimerBlocks blocks, unsigned long long fire, bool isOnce = true) : ofxTimerModule(fire, ofGetElapsedTimeMillis(), isOnce) {
        this->blocks = blocks;
    }
    
    virtual void fireBody() {
        blocks();
    }
private:
    ofxTimerBlocks blocks;
};

#endif

#if OFX_TIMER_SYSTEM_ENABLE_LAMBDA

class ofxTimerWithLambda : public ofxTimerModule {
public:
    ofxTimerWithLambda(ofxTimerLambda lambda, unsigned long long fire, bool isOnce = true) : ofxTimerModule(fire, ofGetElapsedTimeMillis(), isOnce) {
        this->lambda = lambda;
    }
    
    virtual void fireBody() {
        lambda();
    }
private:
    ofxTimerLambda lambda;
};

#endif

#endif /* defined(__ofxTimerModuleSubclasses__) */
