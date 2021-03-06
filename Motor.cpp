#include "Motor.h"

Serial pc(PA_2, PA_3, 115200);

Motor::Motor(){
    init();
}

void Motor::init() {
    //////Maxon motor
    CANOpen_SETUP(1000000, 0.1);
    wait(1.0);
    STOP_SYNC();
    pc.printf("Going to CLEAR_FAULT");
    SDO_CW(1, CLEAR_FAULT);
    SDO_CW(2, CLEAR_FAULT);
    SDO_CW(3, CLEAR_FAULT);
    SDO_CW(4, CLEAR_FAULT);
    pc.printf("FAULT CLEARED.");
    SET_NMT(RESET_COMMU);
    wait(0.01);

    //while(!PDO_INIT());

    SDO_CW(1, SHUT_DOWN);
    SDO_CW(2, SHUT_DOWN);
    SDO_CW(3, SHUT_DOWN);
    SDO_CW(4, SHUT_DOWN);
    SET_NMT(SET_OP);
    wait(0.01);

    //**********CONFIGURATION DONE! READY FOR MOTION**********

    START_SYNC(0.05);
    //TEST P-VELOCITY MODE

    SET_OP_MODE(1, PVM);
    SET_OP_MODE(2, PVM);
    SET_OP_MODE(3, PVM);
    SET_OP_MODE(4, PVM);

    // 
    // Be careful with the value of the velocity. If the velocity is higher then below, the driver will stop working
    //
    SET_MAX_P_VELOCITY(1, 8700);
    SET_MAX_P_VELOCITY(2, 8700);
    SET_MAX_P_VELOCITY(3, 8700);
    SET_MAX_P_VELOCITY(4, 8700);

    SET_P_ACCELERATION(1, 30000);
    SET_P_ACCELERATION(2, 30000);
    SET_P_ACCELERATION(3, 30000);
    SET_P_ACCELERATION(4, 30000);

    SET_P_DECELERATION(1, 30000);
    SET_P_DECELERATION(2, 30000);
    SET_P_DECELERATION(3, 30000);
    SET_P_DECELERATION(4, 30000);

    SET_QUICK_STOP_DECELERATION(1, 10000);
    SET_QUICK_STOP_DECELERATION(2, 10000);
    SET_QUICK_STOP_DECELERATION(3, 10000);
    SET_QUICK_STOP_DECELERATION(4, 10000);

    SET_MOTION_PROFILE_TYPE(1, SIN);
    SET_MOTION_PROFILE_TYPE(2, SIN);
    SET_MOTION_PROFILE_TYPE(3, SIN);
    SET_MOTION_PROFILE_TYPE(4, SIN);
    //              **********WARNING: HERE THE VALUE FROM CURRENT MODE IS ALSO EFFECTIVE! RESET THEM TO DEFAULT IF YOU DON'T WANT A CURRENT LIMIT!!!**********
    SET_CONTINOUS_CURRENT_LIMIT(1, 10000);
    SET_CONTINOUS_CURRENT_LIMIT(2, 10000);
    SET_CONTINOUS_CURRENT_LIMIT(3, 10000);
    SET_CONTINOUS_CURRENT_LIMIT(4, 10000);

    SET_MAX_CURRENT_MODE_SPEED(1, 25000);
    SET_MAX_CURRENT_MODE_SPEED(2, 25000);
    SET_MAX_CURRENT_MODE_SPEED(3, 25000);
    SET_MAX_CURRENT_MODE_SPEED(4, 25000);

    SET_THERMAL_TIME_CONSTANT_WINDING(1, 40);
    SET_THERMAL_TIME_CONSTANT_WINDING(2, 40);
    SET_THERMAL_TIME_CONSTANT_WINDING(3, 40);
    SET_THERMAL_TIME_CONSTANT_WINDING(4, 40);

    //////////////////////////////////////////////////////////////////

    SDO_CW(1, SHUT_DOWN);
    SDO_CW(2, SHUT_DOWN);
    SDO_CW(3, SHUT_DOWN);
    SDO_CW(4, SHUT_DOWN);

    SDO_CW(1, SWITCH_ON_ENABLE_OP);
    SDO_CW(2, SWITCH_ON_ENABLE_OP);
    SDO_CW(3, SWITCH_ON_ENABLE_OP);
    SDO_CW(4, SWITCH_ON_ENABLE_OP);
    pc.printf("SDO Complete");
    //wait(2);    
}

void Motor::update(int motor1, int motor2, int motor3, int motor4) {
    /*
    SET_TARGET_VELOCITY(1, motor1*-1);
    SET_TARGET_VELOCITY(2, motor2);
    SET_TARGET_VELOCITY(3, motor3*-1);
    SET_TARGET_VELOCITY(4, motor4);
    */
    SET_TARGET_VELOCITY(1, motor1);
    SET_TARGET_VELOCITY(2, motor2 * -1);
    SET_TARGET_VELOCITY(3, motor3);
    SET_TARGET_VELOCITY(4, motor4 * -1);

    wait(0.002);
    RPDO1_EXE(1, SWITCH_ON_ENABLE_OP);
    RPDO1_EXE(2, SWITCH_ON_ENABLE_OP);
    RPDO1_EXE(3, SWITCH_ON_ENABLE_OP);
    RPDO1_EXE(4, SWITCH_ON_ENABLE_OP);
    wait(0.002);
}

void Motor::manual(){
    SET_P_ACCELERATION(1, 99999);
    SET_P_ACCELERATION(2, 99999);
    SET_P_ACCELERATION(3, 99999);
    SET_P_ACCELERATION(4, 99999);

    SET_P_DECELERATION(1, 99999);
    SET_P_DECELERATION(2, 99999);
    SET_P_DECELERATION(3, 99999);
    SET_P_DECELERATION(4, 99999);

    SET_QUICK_STOP_DECELERATION(1, 99999);
    SET_QUICK_STOP_DECELERATION(2, 99999);
    SET_QUICK_STOP_DECELERATION(3, 99999);
    SET_QUICK_STOP_DECELERATION(4, 99999);
}

int Motor::getMaxPVelocity()
{
    return maxPVelocity;
}




