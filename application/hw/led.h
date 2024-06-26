// Led.h
#include "../err.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>



class Led {

private:

    int led_num;

public:
    Led(int num);
    ERR_STATUS init();
    ERR_STATUS turn_on();
    ERR_STATUS turn_off();
};
