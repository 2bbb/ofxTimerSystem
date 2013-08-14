//
//  ofxSetInterval.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxSetInterval__
#define __ofxSetInterval__

#include "ofxTimerThread.h"
#include "ofxTimer.h"

template <class Class>
ofxTimer ofxSetInterval(Class *c,
                        void (Class::*func)(),
                        unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithFunctionAndClass<Class>(c, func, fire, false);
    ofxTimerModuleWrapperRef wrapper = ofxTimerModuleWrapperRef(new ofxTimerModuleWrapper(module));
    ofxTimer timer(wrapper);
    return timer;
}

template <class Class, class Argument>
ofxTimer ofxSetInterval(Class *c,
                        void (Class::*func)(Argument *),
                        Argument *arg,
                                        unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithClassAndArguments<Class, Argument>(c, func, arg, fire, false);
    ofxTimerModuleWrapperRef wrapper = ofxTimerModuleWrapperRef(new ofxTimerModuleWrapper(module));
    ofxTimer timer(wrapper);
    return timer;
}

#if __has_extension(blocks)
// TODO: add blocks version
#endif

#endif
