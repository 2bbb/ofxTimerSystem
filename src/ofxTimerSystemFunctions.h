//
//  ofxTimerSystemFunctions.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerSystemFunctions__
#define __ofxTimerSystemFunctions__

#include "ofxTimer.h"

#include "ofxTimerSystemConfig.h"
#include "ofxTimerModuleSubclasses.h"

#pragma mark Class and Function

template <class Class>
ofxTimer ofxSetTimer(Class *c,
                     void (Class::*func)(),
                     unsigned long long fire,
                     bool isLoop)
{
    ofxTimerModule *module = new ofxTimerWithFunctionAndClass<Class>(c, func, fire, !isLoop);
    return createTimerFromModule(module);
}

template <class Class>
ofxTimer ofxSetInterval(Class *c,
                        void (Class::*func)(),
                        unsigned long long fire)
{
    return ofxSetTimer(c, func, fire, true);
}

template <class Class>
ofxTimer ofxSetTimeout(Class *c,
                       void (Class::*func)(),
                       unsigned long long fire)
{
    return ofxSetTimer(c, func, fire, false);
}

#pragma mark -

#pragma mark Class and Function and Arguments

template <class Class, class Argument>
ofxTimer ofxSetTimer(Class *c,
                     void (Class::*func)(Argument *),
                     Argument *arg,
                     unsigned long long fire,
                     bool isLoop)
{
    ofxTimerModule *module = new ofxTimerWithClassAndArguments<Class, Argument>(c, func, arg, fire, !isLoop);
    return createTimerFromModule(module);
}

template <class Class, class Argument>
ofxTimer ofxSetInterval(Class *c,
                        void (Class::*func)(Argument *),
                        Argument *arg,
                        unsigned long long fire)
{
    return ofxSetTimer(c, func, arg, fire, true);
}

template <class Class, class Argument>
ofxTimer ofxSetTimeout(Class *c,
                       void (Class::*func)(Argument *),
                       Argument *arg,
                       unsigned long long fire)
{
    return ofxSetTimer(c, func, arg, fire, false);
}

#pragma mark -

#pragma mark Blocks

#ifdef OFX_TIMER_SYSTEM_ENABLE_BLOCKS

static ofxTimer ofxSetTimer(ofxTimerBlocks blocks,
                            unsigned long long fire,
                            bool isLoop)
{
    ofxTimerModule *module = new ofxTimerWithBlocks(blocks, fire, !isLoop);
    return createTimerFromModule(module);
}

static ofxTimer ofxSetInterval(ofxTimerBlocks blocks,
                               unsigned long long fire)
{
    return ofxSetTimer(blocks, fire, true);
}

static ofxTimer ofxSetTimeout(ofxTimerBlocks blocks,
                              unsigned long long fire)
{
    return ofxSetTimer(blocks, fire, false);
}

#endif

#pragma mark -

#pragma mark Lambda

#ifdef OFX_TIMER_SYSTEM_ENABLE_LAMBDA

static ofxTimer ofxSetTimer(ofxTimerLambda lambda,
                            unsigned long long fire,
                            bool isLoop)
{
    ofxTimerModule *module = new ofxTimerWithLambda(lambda, fire, !isLoop);
    return createTimerFromModule(module);
}

static ofxTimer ofxSetInterval(ofxTimerLambda lambda,
                               unsigned long long fire)
{
    return ofxSetTimer(lambda, fire, true);
}

static ofxTimer ofxSetTimeout(ofxTimerLambda lambda,
                              unsigned long long fire)
{
    return ofxSetTimer(lambda, fire, false);
}

#endif

#endif
