# Pass_Robot
The 1 board version of pass robot

To target is to integrate the master and slave board of crimson 2019

## Possible change:

### Use VESC or C620 to replace quadratic cylinder

Isolate quadratic cylinder task

### Use VESC as chassis wheel instead of Maxon motor

Isolate Maxon motor code

### Add a new file called general_config.h

Add a new file to increase flexibility of different design

## Modification: 

### main.cpp

(1) Ensure that automode is always false

There are four functions related to autoMode changes
~~~
void high_func_L1(){
  if (!autoMode);
    autoMode = true;
}
~~~
~~~
void high_func_R1(){
  if (autoMode);
    autoMode = false;
}
~~~
~~~
void fall_func_L1(){
  if (!autoMode);
    autoMode = true;
}
~~~
~~~
void fall_func_R1(){
  if (autoMode);
    autoMode = false;
}
~~~
So that's obvious: L1: active automode, R1: manual mode

There is an example of #ifdef:

~~~
#define HW_HAS_SIN_COS_ENCODER

#ifdef HW_HAS_SIN_COS_ENCODER
	mode = ENCODER_MODE_SINCOS;
	index_found = true;
#else
	mode = ENCODER_MODE_NONE;
	index_found = false;
#endif
~~~

Use #ifdef and #endif to bypass:(Use #ifndef here)

1. autoMode changing to true 

2. motorUpdateTicker.attach(&motorUpdate, UPDATE_RATE);

3. motorUpdateTicker.detach();

Use #define ROBOT_HAS_AUTO to select

(2) Bypass initpath() in main
~~~
#ifdef ROBOT_HAS_AUTO
    pc.printf("Now in main(), before initPath()");
    initPath();
#else
    autoMode = false;
#endif
~~~
### pass_slave.cpp - New file to replace slaveBoard.h

Eliminate the intermediate serial transmission

the new class is not serial anymore, cancel the inheritance
