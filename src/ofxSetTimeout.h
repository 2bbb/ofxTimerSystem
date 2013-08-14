//
//  ofxSetTimeout.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxSetTimeout__
#define __ofxSetTimeout__

#include "ofxSetTimeoutThread.h"
#include "ofxTimerSystem.h"

template <class Class>
ofxTimerRef ofxSetTimeout(Class *c,
                   void (Class::*func)(),
                   unsigned long long fire)
{
    ofxTimerRef timer = ofxTimerRef(new ofxTimer(new ofxTimerThreadFunctionWithClass<Class>(c, func, fire)));
    ofxTimerSystem::addTimer(timer);
    return timer;
}

template <class Class, class Argument>
ofxTimerRef ofxSetTimeout(Class *c,
                   void (Class::*func)(Argument *),
                   Argument *arg,
                   unsigned long long fire)
{
    ofxTimerRef timer = ofxTimerRef(new ofxTimer(new ofxTimerThreadWithClassAndArguments<Class, Argument>(c, func, arg, fire)));
    ofxTimerSystem::addTimer(timer);
    return timer;
}

#endif /* defined(__ofxSetTimeout__) */