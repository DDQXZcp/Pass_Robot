#include "mbed.h"
#include "hfCore.h"
#include "airCore.h"

class SlaveBoard {
    private:
        
    public:
        void homing();
        void readyPosition();
        void fire();
        void estop();
        void vesc();
        void charge();
        void grasp();
        void openC();
        void pick();
        void aim();
        void upG();
        void downG();
        void toggleHG();
        void toggleVG();
        void toggleVS();
        void toggleHS();
};
