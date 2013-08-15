//
//  ofxTimerCoreSubclasses.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerCoreSubclasses__
#define __ofxTimerCoreSubclasses__

#include "ofMain.h"

#include "ofxTimerSystemConfig.h"
#include "ofxTimerCore.h"

template <class Class>
class ofxTimerWithFunctionAndClass : public ofxTimerCore {
public:
    friend class ofxTimerCycle;
    ofxTimerWithFunctionAndClass(Class *c, void (Class::*func)()) {
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
class ofxTimerWithClassAndArguments : public ofxTimerCore {
    friend class ofxTimerCycle;
public:
    ofxTimerWithClassAndArguments(Class *c, void (Class::*func)(Argument *), Argument *arg)  {
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

class ofxTimerWithBlocks : public ofxTimerCore {
public:
    ofxTimerWithBlocks(ofxTimerBlocks blocks) {
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

class ofxTimerWithLambda : public ofxTimerCore {
public:
    ofxTimerWithLambda(ofxTimerLambda lambda) {
        this->lambda = lambda;
    }
    
    virtual void fireBody() {
        lambda();
    }
private:
    ofxTimerLambda lambda;
};

#endif

#endif /* defined(__ofxTimerCoreSubclasses__) */
