/*************IMPORTANT NOTICE***************/
/********ACTION ENCODER.CPP HAS A WHILE LOOP, WHICH PREVENT THE CODE FROM EXECUTING*******/
//COMMENT THE FOLLOWING (IN ACTIONENCODER.CPP): (RAW SOURCE ON MY TEST5 PROGRAM)
/*
while (1)
    {
        if (readable())
        {
            char c = getc();
            if (translate(c))
            {
                calculatePos(aeReadPos.x, aeReadPos.y, aeReadPos.w, true); //global
                break;
            }
        }
    }
*/

#include "main.h"
#include <string>

//VESC vesc;
//Serial ps4PC(USBTX,USBRX,115200); //This is for PS4 input debug.
//DigitalOut myled(LED1);


void inverse(float vx, float vy, float w)
{ 
    int maxPVelocity = motor.getMaxPVelocity();
    motor1 = constrain(int((1 / wheelR) * (vx - vy - (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity);
    motor2 = constrain(int((1 / wheelR) * (vx + vy + (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity);
    motor3 = constrain(int((1 / wheelR) * (vx + vy - (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity);
    motor4 = constrain(int((1 / wheelR) * (vx - vy + (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity);
}

void motorUpdate()
{
    //motor.update(motor1, motor2, motor3, motor4);
    // PS4 function
    //checkFlatLoop();
}

void odomUpdate()
{
    // Run the function if timeout
    if(odomTimer.read_ms() >= int(odomTime) || firstRun)
    {
        firstRun = false;
        // Stop the timer
        odomTimer.stop();
        
        // Stop the robot if finished
        if(targetPoint >= maxPointCount - 1)
        {
            odomTimer.reset();
            motor.update(0, 0, 0, 0);
            return;
        }

        // find nearest point
        double lowestMagnitude = 99999.9;
        for(int i = targetPoint; i < maxPointCount; i++)
        {
            // find the error
            struct position error = {.x = points[i].targetPos.x - curPos.x, .y = points[i].targetPos.y - curPos.y, .w = 0};
            double magnitude = sqrt(error.x * error.x + error.y * error.y);
            // the nearest point found, set the target
            if(magnitude < lowestMagnitude)
            {
                lowestMagnitude = magnitude;
                if(i + 1 > maxPointCount)
                {
                    targetPoint = maxPointCount - 1;
                    break;
                }   
                else
                    targetPoint = i + 1;
            }
        }

        // find the magnitude
        struct position error = {.x = points[targetPoint].targetPos.x - curPos.x, .y = points[targetPoint].targetPos.y - curPos.y, .w = 0};
        // Find reaching time for next point
        odomTime = sqrt(error.x * error.x + error.y * error.y) / maximunSpeed * 1000.0;
        
        // Use maximun speed to run
        
        // find the speed of x & y
        double theta = atan(error.y/error.x);
        localVelocity.x = maximunSpeed * cos(theta);
        localVelocity.y = maximunSpeed * sin(theta);

        
        // convert to global
        globalVelocity.x = localVelocity.x * cos(-curPos.w) - localVelocity.y * sin(-curPos.w);
        globalVelocity.y = localVelocity.x * sin(-curPos.w) + localVelocity.y * cos(-curPos.w); //local to global transformation   (angle only)
        inverse(globalVelocity.x, globalVelocity.y, 0);
        motor.update(motor1, motor2, motor3, motor4);
    
        // Restart the timer
        odomTimer.reset();
        odomTimer.start();
    }
}

float map(float in, float inMin, float inMax, float outMin, float outMax)
{
    // check it's within the range
    if (inMin < inMax)
    {
        if (in <= inMin)
            return outMin;
        if (in >= inMax)
            return outMax;
    }
    else
    { // cope with input range being backwards.
        if (in >= inMin)
            return outMin;
        if (in <= inMax)
            return outMax;
    }
    // calculate how far into the range we are
    float scale = (in - inMin) / (inMax - inMin);
    // calculate the output.
    return outMin + scale * (outMax - outMin);
}

void high_func_LH()
{
    if (!autoMode)
    {
        if (((joy_range_mid - joy_range) < getLY()) and (getLY() < (joy_range_mid + joy_range)))
        {
            vt = 0;
        }
        else
        {
            //vt = map(getLY(),0,255,-1,1) * linear_speed ;
            float temp = map(getLY(), 0, 255, -1, 1);
            if (temp < 0)
            {
                vt = (temp * temp) * -1 * linear_speed;
            }
            else
            {
                vt = (temp * temp) * linear_speed;
            }
        }

        if (((joy_range_mid - joy_range) < getLX()) and (getLX() < (joy_range_mid + joy_range)))
        {
            vnt = 0;
        }
        else
        {
            //vnt = map(getLX(),0,255,-1,1) * linear_speed ;
            float temp = map(getLX(), 0, 255, -1, 1);
            if (temp < 0)
            {
                vnt = (temp * temp) * -1 * linear_speed;
            }
            else
            {
                vnt = (temp * temp) * linear_speed;
            }
        }
    }
}
void high_func_RH()
{
    if (!autoMode)
    {
        if (((joy_range_mid - joy_range) < getRX()) and (getRX() < (joy_range_mid + joy_range)))
        {
            wt = 0;
        }
        else
        {
            //wt = map(getRX(),0,255,-1,1) * angular_speed ;
            float temp = map(getRX(), 0, 255, -1, 1);
            if (temp < 0)
            {
                wt = (temp * temp) * -1 * angular_speed;
            }
            else
            {
                wt = (temp * temp) * angular_speed;
            }
        }
    }
}
void high_func_CommandChange() {}
void high_func_L2() {}
void high_func_R2() {}
void high_func_TRI() 
{
}
void high_func_CIR() {}
void high_func_CRO() {}
void high_func_SQU() {}
void high_func_UP() 
{   }
void high_func_RIGHT() {}
void high_func_DOWN() {}
void high_func_LEFT() {}
void high_func_L1()
{
    if (!autoMode)
    {
        targetPoint = 0;
        maxPointCount = 1;
                
        tolerance.x = 0.01;
        tolerance.y = 0.01;
        tolerance.w = 0.1;

        targetPos.x = 4.1;              //+    startup_offset_x_encoder;
        targetPos.y = -3;              //+    startup_offset_y_encoder;
        targetPos.w = -165 * DEG_TO_RAD; //-    startup_offset_w_encoder;

        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
        
        autoMode = true;
        motorUpdateTicker.attach(&motorUpdate, UPDATE_RATE);
    }
}
void high_func_L3() {}
void high_func_R1()
{
    if (autoMode)
    {
        targetPoint = 0;
        maxPointCount = 1;
                
        tolerance.x = 0.01;
        tolerance.y = 0.01;
        tolerance.w = 0.1;

        targetPos.x = 4.1;              //+    startup_offset_x_encoder;
        targetPos.y = -3;              //+    startup_offset_y_encoder;
        targetPos.w = -165 * DEG_TO_RAD; //-    startup_offset_w_encoder;

        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
        
        autoMode = false;
        motorUpdateTicker.detach();
        motor.manual(); //This changes the acceleration to 99999;
        inverse(0,0,0);
    }
}
void high_func_R3() {}
void high_func_SHARE() 
{
    
}
void high_func_OPTIONS() {}
void low_func_CommandChange() {}
void low_func_LH()
{
    if (!autoMode)
    {
        vt = 0;
        vnt = 0;
    }
}
void low_func_RH()
{
    if (!autoMode)
    {
        wt = 0;
    }
}
void low_func_L2() {}
void low_func_R2() {}
void low_func_TRI() {}
void low_func_CIR() {}
void low_func_CRO() {}
void low_func_SQU() {}
void low_func_UP() {}
void low_func_RIGHT() {}
void low_func_DOWN() {}
void low_func_LEFT() {}
void low_func_L1() {}
void low_func_L3() {}
void low_func_R1() {}
void low_func_R3() {}
void low_func_SHARE() {}
void low_func_OPTIONS() {}
void fall_func_CommandChange() {}
void fall_func_LH()
{
    if (!autoMode)
    {
        vt = 0;
        vnt = 0;
    }
}
void fall_func_RH()
{
    if (!autoMode)
    {
        wt = 0;
    }
}
void fall_func_L2() {}
void fall_func_R2() {}
void fall_func_TRI() {}
void fall_func_CIR() {}
void fall_func_CRO() {}
void fall_func_SQU() {}
void fall_func_UP() {}
void fall_func_RIGHT() {}
void fall_func_DOWN() {}
void fall_func_LEFT() {}
void fall_func_R1()
{
    if (autoMode)
    {
        targetPoint = 0;
        maxPointCount = 1;
                
        tolerance.x = 0.01;
        tolerance.y = 0.01;
        tolerance.w = 0.1;

        targetPos.x = 4.1;              //+    startup_offset_x_encoder;
        targetPos.y = -3;              //+    startup_offset_y_encoder;
        targetPos.w = -165 * DEG_TO_RAD; //-    startup_offset_w_encoder;
        
        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
        
        autoMode = false;
        motorUpdateTicker.detach();
    }
}
void fall_func_L3() {}
void fall_func_L1()
{
    if (!autoMode)
    {
        targetPoint = 0;
        maxPointCount = 1;
                
        tolerance.x = 0.01;
        tolerance.y = 0.01;
        tolerance.w = 0.1;

        targetPos.x = 4.1;              //+    startup_offset_x_encoder;
        targetPos.y = -3;              //+    startup_offset_y_encoder;
        targetPos.w = -165 * DEG_TO_RAD; //-    startup_offset_w_encoder;

        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
        
        autoMode = true;
        motorUpdateTicker.attach(&motorUpdate, UPDATE_RATE);
    }
}
void fall_func_R3() {}
void fall_func_SHARE() {}
void fall_func_OPTIONS() {}
void rise_func_CommandChange() {}
void rise_func_LH() {}
void rise_func_RH() {}
void rise_func_L2() {}
void rise_func_R2() {}
void rise_func_TRI() 
{
    // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.vesc();
        //slave.homing(); //<- For 3 pt
        //Debug
        //ps4PC.printf("VESC");
        //ps4PC.printf("the timer now is :%d \n",buttonBlock.read_ms());
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
        pc.printf("RISE TRI \n");
    }    
}
void rise_func_CIR() 
{
    // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.fire();
        //Debug
        //ps4PC.printf("the timer now is :%d \n",buttonBlock.read_ms());
        //ps4PC.printf("Fire");       
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
    } 
}
void rise_func_CRO()
{
    // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.charge();
        //Debug
        //ps4PC.printf("Stop");
        //ps4PC.printf("the timer now is :%d \n",buttonBlock.read_ms());
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
    }
    }
void rise_func_SQU() 
{
    // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.homing();
        //slave.readyPosition(); //<- For 3 pt
        //Debug
        //ps4PC.printf("Homing");
        //ps4PC.printf("the timer now is :%d \n",buttonBlock.read_ms());
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
    }    
}
void rise_func_UP() 
{
    // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.toggleVG();
        //Debug
        //ps4PC.printf("ToggleVG");
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
        pc.printf("RISE UP");
}    
    }
void rise_func_RIGHT() 
{
    // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        //slave.toggleHG();
        //slave.vesc();
        //Debug
        //ps4PC.printf("ToggleHG");
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
        pc.printf("RISE RIGHT");
    }       
}
void rise_func_DOWN() 
{
    // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.toggleVS();
        //Debug
        //ps4PC.printf("ToggleVS");
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
        pc.printf("RISE DOWN");
}    
    }
void rise_func_LEFT() 
{
            // if the button blocked for 500 ms or the button press for first time
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.toggleHS();
        //Debug
        //ps4PC.printf("toggleHS");
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
        pc.printf("RISE LEFT");
    } 
}
void rise_func_L1() {}
void rise_func_L3()
{
    if (!autoMode)
    {
        vt = 0;
        vnt = 0;
    }
}
void rise_func_R1() {}
void rise_func_R3()
{
    if (!autoMode)
    {
        wt = 0;
    }
}
void rise_func_SHARE() {}
void rise_func_OPTIONS() {}

int main()
{
    //myled = 1;
    //diu.printf("1");
    //diu.printf("2");
    // Manual mode
    //PS4_SERIAL_INIT();
    
    // Interrupt
    //motorUpdateTicker.attach(&motorUpdate, UPDATE_RATE);
    //pc.attach(&debugCommand, Serial::RxIrq);
    //pc.printf("Main");
    
    if(autoMode == false)
        motor.manual();
    
    while (1)
    {
        if (autoMode)
        {
            //diu.printf("In autoMode");
            if(action.curPosIsAvailable())
            {
                curPos = action.getCurPos();
                pc.printLocation(targetPoint, curPos, globalVelocity);
                odomUpdate();
            }
        }
        else
        {
            //diu.printf("In manual");
            inverse(-vt, -vnt, -wt);
            motorUpdate();
        }
    }
}

