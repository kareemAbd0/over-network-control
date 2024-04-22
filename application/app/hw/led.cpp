//
// Created by kareem on 4/13/24.
//


#include "led.h"

const std::string PATH1 = "/sys/class/gpio-led";
//const std::string PATH1 = "mock/gpio-led";

Led::Led(int num)  : led_num(num) {};


ERR_STATUS Led::init() {
 //with error checking
    ERR_STATUS err = GOOD;
    std::string path = PATH1 + "/led" + std::to_string(led_num) + "/direction";
    std::ofstream file(path);
    if (file.is_open()) {
        file << "out";
    } else {
        std::cout << "Failed to open " << path << std::endl;
        return NO_FILE ;
    }
    return err;
}


ERR_STATUS Led::turn_on() {
    ERR_STATUS err = GOOD;
    std::string path = PATH1 + "/led" + std::to_string(led_num) + "/value";
    std::ofstream file(path);
    if (file.is_open()) {
        file << "1";
    } else {
        std::cout << "Failed to open " << path << std::endl;
        return NO_FILE;
    }
    return err;
}

ERR_STATUS Led::turn_off() {
    ERR_STATUS err = GOOD;
    std::string path = PATH1 + "/led" + std::to_string(led_num) + "/value";
    std::ofstream file(path);
    if (file.is_open()) {
        file << "0";
    } else {
        std::cout << "Failed to open " << path << std::endl;
        return NO_FILE;
    }
    return err;
}


