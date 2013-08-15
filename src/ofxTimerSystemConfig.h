//
//  ofxTimerSystemConfig.h
//
//  Created by ISHII 2bit.
//
//

#ifndef __ofxTimerSystemConfig__
#define __ofxTimerSystemConfig__

#if __has_extension(blocks)

#define OFX_TIMER_SYSTEM_ENABLE_BLOCKS (1)
typedef void (^ofxTimerBlocks)(void);

#endif

#if __has_feature(cxx_lambdas)

#include <tr1/functional>

#define OFX_TIMER_SYSTEM_ENABLE_LAMBDA (1)

using std::tr1::function;
typedef function<void(void)> ofxTimerLambda;

#endif

#endif
