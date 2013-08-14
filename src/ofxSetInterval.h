//
//  ofxSetInterval.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxSetInterval__
#define __ofxSetInterval__

#include "ofxSetTimeoutThread.h"

template <class Class>
ofxTimerRef ofxSetInterval(Class *c,
                           void (Class::*func)(),
                           unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadFunctionWithClass<Class>(c, func, fire, false);
    ofxTimerRef timer = ofxTimerRef(new ofxTimer(module));
    ofxTimerSystem::addTimer(timer);
    return timer;
}

template <class Class, class Argument>
ofxTimerRef ofxSetInterval(Class *c,
                           void (Class::*func)(Argument *),
                           Argument *arg,
                           unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithClassAndArguments<Class, Argument>(c, func, arg, fire, false);
    ofxTimerRef timer = ofxTimerRef(new ofxTimer(module));
    ofxTimerSystem::addTimer(timer);
    return timer;
}


#endif
