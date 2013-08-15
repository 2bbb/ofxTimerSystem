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
#include "ofxTimerCoreSubclasses.h"

#pragma mark Class and Function

template <class Class>
ofxTimer ofxSetTimer(Class *c,
                     void (Class::*func)(),
                     unsigned long long fire,
                     bool isLoop)
{
    ofxTimerCore *core = new ofxTimerWithFunctionAndClass<Class>(c, func);
    return createTimerFromCore(core, fire, ofGetElapsedTimeMillis(), !isLoop);
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
    ofxTimerCore *core = new ofxTimerWithClassAndArguments<Class, Argument>(c, func, arg);
    return createTimerFromCore(core, fire, ofGetElapsedTimeMillis(), !isLoop);
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
    ofxTimerCore *core = new ofxTimerWithBlocks(blocks);
    return createTimerFromCore(core, fire, ofGetElapsedTimeMillis(), !isLoop);
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
    ofxTimerCore *core = new ofxTimerWithLambda(lambda);
    return createTimerFromCore(core, fire, ofGetElapsedTimeMillis(), !isLoop);
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
