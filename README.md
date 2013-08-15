# ofxTimerSystem


Timer functions (ofxSetTimeout and ofxSetInterval) like JavaScript for openframeworks

## API

__TODO__

* if your system can use Blocks, then you can use blocks type is _^(){}_.
	* blocks : _http://en.wikipedia.org/wiki/Blocks\_(C\_language_extension)_
* if your system can use C++11 lambda, then you can use lambda type is  _std::function<void(void)>_ .
	* but, i only tested in LLVM clang.
	* and of0.8 in Xcode, if we use -std=c++11 then maybe we will get error at "ofTypes.h"…
	* if you will get error with other environment, let's try to edit the blocks of __\# \_\_has\_feature(cxx\_lambdas)__  in "ofxTimerModule.h".


## Cautions

In the function of timer, _DON'T_ call GL function. (System will crash probably!!)

## Update history

### 2013/08/15 ver 0.01 beta release

## License

MIT License.

## Author

* ISHII 2bit [bufferRenaiss co., ltd.]
* ishii[at]buffer-renaiss.com

## At the last

Please create new issue, if there is a problem.
And please throw pull request, if you have a cool idea!!
