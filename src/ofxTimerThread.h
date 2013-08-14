//
//  ofxTimerThread.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerThread__
#define __ofxTimerThread__

#include "ofMain.h"
#include "ofxTimerModule.h"

template <class Class>
class ofxTimerThreadWithFunctionAndClass : public ofxTimerModule {
public:
    friend class ofxTimerCycle;
    ofxTimerThreadWithFunctionAndClass(Class *c, void (Class::*func)(), unsigned long long fire, bool isOnce = true) : ofxTimerModule(fire, ofGetElapsedTimeMillis(), isOnce) {
        this->c = c;
        this->func = func;
    }
    
    virtual ~ofxTimerThreadWithFunctionAndClass() {};
    virtual void fireBody() {
        (c->*func)();
    }
private:
    Class *c;
    void (Class::*func)();
};

template <class Class, class Argument>
class ofxTimerThreadWithClassAndArguments : public ofxTimerModule {
    friend class ofxTimerCycle;
public:
    ofxTimerThreadWithClassAndArguments(Class *c, void (Class::*func)(Argument *), Argument *arg, unsigned long long fire, bool isOnce = true) : ofxTimerModule(fire, ofGetElapsedTimeMillis(), isOnce)  {
        this->c = c;
        this->func = func;
        this->arg = arg;
    }
    
    virtual ~ofxTimerThreadWithClassAndArguments() {
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

#if __has_extension(blocks)
// TODO: add blocks version
#endif

#endif /* defined(__ofxSetTimeoutThread__) */
