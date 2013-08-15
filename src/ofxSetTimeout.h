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
    return createTimerFromModule(module);
}

template <class Class, class Argument>
ofxTimer ofxSetTimeout(Class *c,
                       void (Class::*func)(Argument *),
                       Argument *arg,
                       unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithClassAndArguments<Class, Argument>(c, func, arg, fire);
    return createTimerFromModule(module);
}

#if __has_extension(blocks)

static ofxTimer ofxSetTimeout(ofxTimerBlocks blocks,
                       unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithBlocks(blocks, fire);
    return createTimerFromModule(module);
}

#endif

// TODO: add C++11 lambda version

#endif /* defined(__ofxSetTimeout__) */