//
//  ofxSetTimeoutThread.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxSetTimeoutThread__
#define __ofxSetTimeoutThread__

#include "ofMain.h"
#include "ofxTimer.h"

template <class Class>
class ofxTimerThreadFunctionWithClass : public ofxTimerModule {
public:
    friend class ofxTimerCycle;
    ofxTimerThreadFunctionWithClass(Class *c, void (Class::*func)(), unsigned long long fire, bool isOnce = true) : ofxTimerModule(fire, ofGetElapsedTimeMillis(), isOnce) {
        this->c = c;
        this->func = func;
    }
    
    virtual ~ofxTimerThreadFunctionWithClass() {};
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

#endif /* defined(__ofxSetTimeoutThread__) */
