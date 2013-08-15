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
    return createTimerFromModule(module);
}

template <class Class, class Argument>
ofxTimer ofxSetInterval(Class *c,
                        void (Class::*func)(Argument *),
                        Argument *arg,
                        unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithClassAndArguments<Class, Argument>(c, func, arg, fire, false);
    return createTimerFromModule(module);
}

#if __has_extension(blocks)

static ofxTimer ofxSetInterval(ofxTimerBlocks blocks,
                        unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithBlocks(blocks, fire, false);
    return createTimerFromModule(module);
}

#endif

#if __has_feature(cxx_lambdas)

static ofxTimer ofxSetInterval(ofxTimerLambda lambda,
                               unsigned long long fire)
{
    ofxTimerModule *module = new ofxTimerThreadWithLambda(lambda, fire, false);
    return createTimerFromModule(module);
}

#endif

#endif /* defined(__ofxSetInterval__) */
