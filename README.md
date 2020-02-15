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

Ensure that automode is always false

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

Use #ifdef and #endif to pack up the things
