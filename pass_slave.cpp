#include "pass_slave.h"


//No need
//SlaveBoard::SlaveBoard(PinName tx, PinName rx) : Serial(tx, rx){}

airCore airt(true, PC_3,PC_2,PC_0,PA_4,PB_0,PC_5); //<- for STM32F446RE
//(toggleMove()[2pins], toggleC()[2pins], toggleGeorgeHold()[1pin], toggleGeorgeMove()[1pin])

hfCore hft(true,0.3,0.95,0.1);  //Fastest speed. use CAREFULLY. the Speed is between 0 to 0.95.
//hfCore hft(true,0.95,0.95,0.1);  //Craziest speed.

void SlaveBoard::homing()
{
    hft.homing(true); //Stop at -------|----- [HF]
}

void SlaveBoard::readyPosition()
{
    hft.ready(true); //Stop at -------|----- [HF]
}

void SlaveBoard::fire()
{
    hft.charge(true); //Stop at ------------| [HF]
}
/*
void SlaveBoard::estop()
{
    putc('E');
}
*/
void SlaveBoard::vesc()
{
    printf("VSC!!!\n");
    hft.vsc(0); // Pull the trigger [HF]
}

void SlaveBoard::charge()
{
    hft.charge(true); //Stop at ------------| [HF]
}
/*
void SlaveBoard::grasp()
{
    putc('A');    
}
void SlaveBoard::openC()
{
    putc('O');    
}
void SlaveBoard::pick()
{
    putc('U');    
}
void SlaveBoard::aim()
{
    putc('M');    
}
void SlaveBoard::upG()
{
    putc('P');    
}
void SlaveBoard::downG()
{
    putc('B');    
}
void SlaveBoard::toggleHG()
{
    putc('L');    
}
*/
void SlaveBoard::toggleVG()
{
    airt.toggleGeorgeMove(); // toggle george moveup and down [G] //PB_0    
}

void SlaveBoard::toggleHS()
{
    airt.toggleC(); //toggle openC and closeC. [S] //PA_4 close , PC_0 open
}

void SlaveBoard::toggleVS()
{
    airt.toggleMove(); //toggle move up and down. [S] //PC_2 up, PC_3 down
}
