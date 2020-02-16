/******IMPORTANT NOTICE***************/
/********ACTION ENCODER.CPP HAS A WHILE LOOP, WHICH PREVENT THE CODE FROM EXECUTING**/
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

#define ROBOT_HAS_AUTO

//VESC vesc;
//Serial ps4PC(USBTX,USBRX,115200); //This is for PS4 input debug.
//DigitalOut myled(LED1);
extern Serial pc;

void initPath()
{
    //
    // Code generated by G Shadow Robot Master (Red)
    //
    //Red
/*    maxPointCount = 13;
    points[0] = (pointInfo){.targetPos.x = 0, .targetPos.y = 0, .targetPos.w = 0, .tolerance.x = 0.05, .tolerance.y = 0.05, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[1] = (pointInfo){.targetPos.x = 0.734, .targetPos.y = 1, .targetPos.w = 0, .tolerance.x = 0.25, .tolerance.y = 0.25, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[2] = (pointInfo){.targetPos.x = 0.834, .targetPos.y = 1.55, .targetPos.w = 0, .tolerance.x = 0.25, .tolerance.y = 0.25, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[3] = (pointInfo){.targetPos.x = 2.184, .targetPos.y = 1.55, .targetPos.w = 0, .tolerance.x = 0.25, .tolerance.y = 0.25, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 0.1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[4] = (pointInfo){.targetPos.x = 2.384, .targetPos.y = 0.3, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[5] = (pointInfo){.targetPos.x = 3.65, .targetPos.y = 0.3, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[6] = (pointInfo){.targetPos.x = 3.784, .targetPos.y = 1.5, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.05, .maxSpeed.x = 2.5, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[7] = (pointInfo){.targetPos.x = 5.384, .targetPos.y = 1.5, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 0.1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[8] = (pointInfo){.targetPos.x = 5.584, .targetPos.y = 0.89, .targetPos.w = 0, .tolerance.x = 0.02, .tolerance.y = 0.02, .tolerance.w = 0.05, .maxSpeed.x = 1, .maxSpeed.y = 2.5, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[9] = (pointInfo){.targetPos.x = 8.3, .targetPos.y = 0.89, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 2.5, .maxSpeed.y = 1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[10] = (pointInfo){.targetPos.x = 8.25, .targetPos.y = 3.2, .targetPos.w = -80, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 1, .maxSpeed.y = 2, .maxSpeed.w = 1, .pidOn = true, .command = toggleVG};
    points[11] = (pointInfo){.targetPos.x = 8.1, .targetPos.y = 4.2, .targetPos.w = -90, .tolerance.x = 0.05, .tolerance.y = 0.05, .tolerance.w = 0.1, .maxSpeed.x = 2, .maxSpeed.y = 2, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[12] = (pointInfo){.targetPos.x = 7.9, .targetPos.y = 6, .targetPos.w = -90, .tolerance.x = 0.05, .tolerance.y = 0.05, .tolerance.w = 0.1, .maxSpeed.x = 0.5, .maxSpeed.y = 0.5, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
*/    
    //Blue
    /*
    maxPointCount = 13;
    points[0] = (pointInfo){.targetPos.x = 0, .targetPos.y = 0, .targetPos.w = 0, .tolerance.x = 0.05, .tolerance.y = 0.05, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[1] = (pointInfo){.targetPos.x = 0.734, .targetPos.y = -1, .targetPos.w = 0, .tolerance.x = 0.25, .tolerance.y = 0.25, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[2] = (pointInfo){.targetPos.x = 0.834, .targetPos.y = -1.55, .targetPos.w = 0, .tolerance.x = 0.25, .tolerance.y = 0.25, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[3] = (pointInfo){.targetPos.x = 2.1, .targetPos.y = -1.55, .targetPos.w = 0, .tolerance.x = 0.25, .tolerance.y = 0.25, .tolerance.w = 0.1, .maxSpeed.x = 2.5, .maxSpeed.y = 0.1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[4] = (pointInfo){.targetPos.x = 2.1, .targetPos.y = -0.25, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 2.5, .maxSpeed.y = 2.5, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[5] = (pointInfo){.targetPos.x = 3.6, .targetPos.y = -0.25, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[6] = (pointInfo){.targetPos.x = 3.6, .targetPos.y = -1.5, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.05, .maxSpeed.x = 2.5, .maxSpeed.y = 3, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[7] = (pointInfo){.targetPos.x = 5.384, .targetPos.y = -1.5, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 3, .maxSpeed.y = 0.1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[8] = (pointInfo){.targetPos.x = 5.584, .targetPos.y = -0.89, .targetPos.w = 0, .tolerance.x = 0.02, .tolerance.y = 0.02, .tolerance.w = 0.05, .maxSpeed.x = 1, .maxSpeed.y = 2.5, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[9] = (pointInfo){.targetPos.x = 8.3, .targetPos.y = -0.89, .targetPos.w = 0, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 2.5, .maxSpeed.y = 1, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[10] = (pointInfo){.targetPos.x = 8.25, .targetPos.y = -3.3, .targetPos.w = -80, .tolerance.x = 0.2, .tolerance.y = 0.2, .tolerance.w = 0.1, .maxSpeed.x = 1, .maxSpeed.y = 2, .maxSpeed.w = 1, .pidOn = true, .command = toggleVG};
    points[11] = (pointInfo){.targetPos.x = 8.05, .targetPos.y = -4.2, .targetPos.w = -90, .tolerance.x = 0.05, .tolerance.y = 0.05, .tolerance.w = 0.1, .maxSpeed.x = 2, .maxSpeed.y = 2, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    points[12] = (pointInfo){.targetPos.x = 7.9, .targetPos.y = -6, .targetPos.w = -90, .tolerance.x = 0.05, .tolerance.y = 0.05, .tolerance.w = 0.1, .maxSpeed.x = 0.5, .maxSpeed.y = 0.5, .maxSpeed.w = 1, .pidOn = true, .command = noAction};
    */
}
void inverse(float vx, float vy, float w)
{
    /*
    motor1 = int((1 / wheelR) * (vx - vy - (lx + ly) * w) * radian_to_rpm_convert);
    motor2 = int((1 / wheelR) * (vx + vy + (lx + ly) * w) * radian_to_rpm_convert);
    motor3 = int((1 / wheelR) * (vx + vy - (lx + ly) * w) * radian_to_rpm_convert);
    motor4 = int((1 / wheelR) * (vx - vy + (lx + ly) * w) * radian_to_rpm_convert);
    */
    
    int maxPVelocity = motor.getMaxPVelocity();
    motor1 = constrain(    int((1 / wheelR) * (vx - vy - (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity );
    motor2 = constrain(    int((1 / wheelR) * (vx + vy + (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity );
    motor3 = constrain(    int((1 / wheelR) * (vx + vy - (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity );
    motor4 = constrain(    int((1 / wheelR) * (vx - vy + (lx + ly) * w) * radian_to_rpm_convert) , -maxPVelocity, maxPVelocity );
}

void motorUpdate()
{
    
    motor.update(motor1, motor2, motor3, motor4);
    // PS4 function
    checkFlatLoop();
}

void odomUpdate()
{
    if(targetPoint == maxPointCount)
        return;
        
    // Go to next point
    if (((fabs(targetPos.x - curPos.x)) < tolerance.x) && ((fabs(targetPos.y - curPos.y)) < tolerance.y) && ((fabs(targetPos.w - curPos.w)) < tolerance.w))
    {
        switch(command)
        {
            case noAction:
                break;
            case homing:
                slave.homing();
                break;
            case readyPosition:
                slave.readyPosition();
                break;
            case fire:
                slave.fire();
                break;
            case VESC:
                slave.vesc();
                break;
            case toggleVG:
                slave.toggleVG();
                break;
        }
        
        
        targetPoint = ++targetPoint;

        tolerance.x = points[targetPoint].tolerance.x;
        tolerance.y = points[targetPoint].tolerance.x;
        tolerance.w = points[targetPoint].tolerance.x;

        targetPos.x = points[targetPoint].targetPos.x;              //+    startup_offset_x_encoder;
        targetPos.y = points[targetPoint].targetPos.y;              //+    startup_offset_y_encoder;
        targetPos.w = points[targetPoint].targetPos.w * DEG_TO_RAD; //-    startup_offset_w_encoder;

        pidOn = points[targetPoint].pidOn;
        command = points[targetPoint].command;

        maxSpeed.x = points[targetPoint].maxSpeed.x;
        maxSpeed.y = points[targetPoint].maxSpeed.y;
        maxSpeed.w = points[targetPoint].maxSpeed.w;

        inverse(0, 0, 0);
        return;
    }

    struct position error = {.x = targetPos.x - curPos.x, .y = targetPos.y - curPos.y, .w = targetPos.w - curPos.w};
    if (pidOn)
    {
        localVelocity.x = (fabs(error.x) > tolerance.x) ? constrain((PID_P.x * (error.x) + PID_D.x * (error.x - lastError.x)), -maxSpeed.x, maxSpeed.x) : 0;
        localVelocity.y = (fabs(error.y) > tolerance.y) ? constrain((PID_P.y * (error.y) + PID_D.y * (error.y - lastError.y)), -maxSpeed.y, maxSpeed.y) : 0;
        localVelocity.w = (fabs(error.w) > tolerance.w) ? constrain((PID_P.w * (error.w) + PID_D.w * (error.w - lastError.w)), -maxSpeed.w, maxSpeed.w) : 0;
        
    }
    else
    {
        localVelocity.x = (fabs(error.x) > tolerance.x) ? constrain((copysign(maxSpeed.x, (error.x))), -maxSpeed.x, maxSpeed.x) : 0;
        localVelocity.y = (fabs(error.y) > tolerance.y) ? constrain((copysign(maxSpeed.y, (error.y))), -maxSpeed.y, maxSpeed.y) : 0;
        localVelocity.w = (fabs(error.w) > tolerance.w) ? constrain((copysign(maxSpeed.w, (error.w))), -maxSpeed.w, maxSpeed.w) : 0;
    }
    lastError.x = error.x;
    lastError.y = error.y;
    lastError.w = error.w;

    globalVelocity.x = localVelocity.x * cos(-curPos.w) - localVelocity.y * sin(-curPos.w);
    globalVelocity.y = localVelocity.x * sin(-curPos.w) + localVelocity.y * cos(-curPos.w); //local to global transformation   (angle only)

    inverse(globalVelocity.x, globalVelocity.y, localVelocity.w);
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
    // if the button blocked for 500 ms or the button press for first time
    /*
    if(buttonBlock.read_ms() >= blockTime || firstPress)
    {
        firstPress = false;
        // Stop the timer
        buttonBlock.stop();
        // Send messege to slave
        slave.vesc();
        //Debug
        pc.printf("VESC");
        pc.printf("the timer now is :%d \n",buttonBlock.read_ms());
        // Restart the timer
        buttonBlock.reset();
        buttonBlock.start();
    }
    */
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

        pidOn = true;
        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
#ifdef ROBOT_HAS_AUTO
        autoMode = true;
        motorUpdateTicker.attach(&motorUpdate, UPDATE_RATE);
#endif
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

        pidOn = true;
        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
#ifdef ROBOT_HAS_AUTO        
        autoMode = false;
        motorUpdateTicker.detach();
#endif
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

        pidOn = true;
        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
 #ifdef ROBOT_HAS_AUTO       
        autoMode = false;
        motorUpdateTicker.detach();
#endif
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

        pidOn = true;
        command = noAction;

        maxSpeed.x = 1.5;
        maxSpeed.y = 1.5;
        maxSpeed.w = 1.5;
#ifdef ROBOT_HAS_AUTO        
        autoMode = true;
        motorUpdateTicker.attach(&motorUpdate, UPDATE_RATE);
#endif
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

// Debug class
char buffer[64];
int accessPoint = 0;

/*
void debugCommand()
{
    fgets(buffer, 64, stdin);
    switch(buffer[0])
    {
        // PID
        // PID_P x
        case 'a':
            PID_P.x = atof(&buffer[2]);
            break;
            
        // PID_P y
        case 'b':
            PID_P.y = atof(&buffer[2]);
            break;
            
        // PID_P w
        case 'c':
            PID_P.w = atof(&buffer[2]);
            break;
            
        // PID_D x
        case 'd':
            PID_I.x = atof(&buffer[2]);
            break;
            
        // PID_D y
        case 'e':
            PID_I.y = atof(&buffer[2]);
            break;
    
        // PID_D w
        case 'f':
            PID_I.w = atof(&buffer[2]);
            break;
        
        // PID_I x
        case 'g':
            PID_D.x = atof(&buffer[2]);
            break;
        
        // PID_I y
        case 'h':
            PID_D.y = atof(&buffer[2]);
            break;
    
        // PID_I w
        case 'i':
            PID_D.w = atof(&buffer[2]);
            break;
            
        // Print PID
        case 'j':
            pc.printPID(PID_P, PID_I, PID_D);
            break;
        
        // Get path
        case 'p':
            pc.printPath(points, maxPointCount);
            break;
            
        // reset
        case 'r':
            targetPoint = 0;
            tolerance.x = points[targetPoint].tolerance.x;
            tolerance.y = points[targetPoint].tolerance.y;
            tolerance.w = points[targetPoint].tolerance.w;
            targetPos.x = points[targetPoint].targetPos.x;              //+    startup_offset_x_encoder;
            targetPos.y = points[targetPoint].targetPos.y;              //+    startup_offset_y_encoder;
            targetPos.w = points[targetPoint].targetPos.w * DEG_TO_RAD; //-    startup_offset_w_encoder;
            pidOn = points[targetPoint].pidOn;
            maxSpeed.x = points[targetPoint].maxSpeed.x;
            maxSpeed.y = points[targetPoint].maxSpeed.y;
            maxSpeed.w = points[targetPoint].maxSpeed.w;
            break;
            
        // set Path
        // Current point
        case 'A':
            accessPoint = atoi(&buffer[2]);
            maxPointCount = accessPoint + 1;
            break;
        
        // targetPos.x
        case 'B':
            points[accessPoint].targetPos.x = atof(&buffer[2]);
            break;
            
        // targetPos.y
        case 'C':
            points[accessPoint].targetPos.y = atof(&buffer[2]);
            break;
            
        // targetPos.w
        case 'D':
            points[accessPoint].targetPos.w = atof(&buffer[2]);
            break;
            
        // tolerance.x
        case 'E':
            points[accessPoint].tolerance.x = atof(&buffer[2]);
            break;
            
        // tolerance.x
        case 'F':
            points[accessPoint].tolerance.y = atof(&buffer[2]);
            break;
            
        // tolerance.x
        case 'G':
            points[accessPoint].tolerance.w = atof(&buffer[2]);
            break;
            
        // maxSpeed.x
        case 'H':
            points[accessPoint].maxSpeed.x = atof(&buffer[2]);
            break;
            
        // maxSpeed.x
        case 'I':
            points[accessPoint].maxSpeed.y = atof(&buffer[2]);
            break;
            
        // maxSpeed.x
        case 'J':
            points[accessPoint].maxSpeed.w = atof(&buffer[2]);
            break;
            
        // pidOn
        case 'K':
            int pid = atoi(&buffer[2]);
            if(pid == 1)
                points[accessPoint].pidOn = true;
            else
                points[accessPoint].pidOn = false;
            break;
    }
}
*/

int main()
{
    //myled = 1;
    //diu.printf("1");
#ifdef ROBOT_HAS_AUTO
    pc.printf("Now in main(), before initPath()");
    initPath();
#else
    autoMode = false;
#endif
    //diu.printf("2");
    // Manual mode
    PS4_SERIAL_INIT();
    
    // Interrupt
    motorUpdateTicker.attach(&motorUpdate, UPDATE_RATE);
    //pc.attach(&debugCommand, Serial::RxIrq);
    //pc.printf("Main");
    
    if(autoMode == false)
        motor.manual();
        
    // Block until the USER_BUTTON is pressed to start he auto mode
    while(1)
    {
        if (startAuto == 0) { // Button is pressed
            break;
        }
        if(action.curPosIsAvailable())
        {
            curPos = action.getCurPos();
            //pc.printLocation(targetPoint, curPos, globalVelocity);
            //Check if curPos.w is drifting
            if (fabs(curPos.w) > 0.05)
            {
                led = !led;
            }
        }
    }
    
    while (1)
    {
        if (autoMode)
        {
            //diu.printf("In autoMode");
            if(action.curPosIsAvailable())
            {
                curPos = action.getCurPos();
                //pc.printLocation(targetPoint, curPos, globalVelocity);
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
