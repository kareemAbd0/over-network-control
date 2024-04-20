// Led.h
#include "../err.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

//const std::string PATH = "/sys/class/gpio-led";
const std::string PATH = "mock/gpio-led";


class Led {

private:

    int led_num;

public:
    Led(int num);
    ERR_STATUS init();
    ERR_STATUS turn_on();
    ERR_STATUS turn_off();
};
