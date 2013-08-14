//
//  ofxSetTimeout.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxSetTimeout__
#define __ofxSetTimeout__

#include "ofxTimerThread.h"
#include "ofxTimer.h"

template <class Class>
ofxTimer ofxSetTimeout(Class *c,
                       void (Class::*func)(),
                       unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithFunctionAndClass<Class>(c, func, fire);
    ofxTimerModuleWrapperRef timer = ofxTimerModuleWrapperRef(new ofxTimerModuleWrapper(module));
    return timer;
}

template <class Class, class Argument>
ofxTimer ofxSetTimeout(Class *c,
                       void (Class::*func)(Argument *),
                       Argument *arg,
                       unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithClassAndArguments<Class, Argument>(c, func, arg, fire);
    ofxTimerModuleWrapperRef timer = ofxTimerModuleWrapperRef(new ofxTimerModuleWrapper(module));
    return timer;
}

#if __has_extension(blocks)
// TODO: add blocks version
#endif

#endif /* defined(__ofxSetTimeout__) */