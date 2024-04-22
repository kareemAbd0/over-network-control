// Led.h

#ifndef APPLICATION_LED_H
#define APPLICATION_LED_H

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

#endif //APPLICATION_LED_H
