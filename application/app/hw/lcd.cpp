//
// Created by kareem on 4/13/24.
//

#include "lcd.h"

//std::string PATH2 = "mock/lcd16x2/lcd";
std::string PATH2 = "/sys/class/lcd_16x2/lcd";
Lcd::Lcd(int num)  : lcd_num(num) {};


ERR_STATUS Lcd::display_text(const std::string& message) {
    ERR_STATUS err = GOOD;
    std::string path = PATH2 +  "/lcdtxt";
    std::ofstream file(path);
    if (file.is_open()) {
        file << message;
    } else {
        std::cout << "Failed to open " << path << std::endl;
        return NO_FILE;
    }
    return err;
}

ERR_STATUS Lcd::change_position(const std::string& message) {

    ERR_STATUS err = GOOD;

    if (message.size() != 2 || !isdigit(message[0]) || !isdigit(message[1]) || message[0] > '2' || message[1] > '5' || message[1] < '1' || message[0] < '0') {
        std::cout << "Invalid postion " << std::endl;
        return FAIL;
    }

    std::string path = PATH2 + "/lcdpxy";
    std::ofstream file(path);
    if (file.is_open()) {
        file << message;
    } else {
        std::cout << "Failed to open " << path << std::endl;
        return NO_FILE;
    }
    return err;
}


ERR_STATUS Lcd::send_command(const std::string& message) {


    ERR_STATUS err = GOOD;
    std::string path = PATH2 + "/lcdcmd";
    std::ofstream file(path);
    if (file.is_open()) {
        file << message;
    } else {
        std::cout << "Failed to open " << path << std::endl;
        return NO_FILE;
    }
    return err;
}

ERR_STATUS Lcd::clear_display() {
    ERR_STATUS err = GOOD;
    std::string path = PATH2 + "/lcdcmd";
    std::ofstream file(path);
    if (file.is_open()) {
        file << "0x01";
    } else {
        std::cout << "Failed to open " << path << std::endl;
        return NO_FILE;
    }
    return err;
}

