//
// Created by kareem on 4/13/24.
//

#ifndef APPLICATION_LCD_H
#define APPLICATION_LCD_H
#include <string>
#include <fstream>
#include <iostream>
#include "../err.h"


// static const std::string PATH = "/sys/class/lcd16x2/lcd ";
std::string PATH = "/mock/lcd16x2/lcd";

class Lcd {

private:
    int lcd_num;
public:
    Lcd(int num);

    //init is done in the kernel module
    ERR_STATUS display_text(const std::string& message);
    ERR_STATUS change_postion(const std::string& message);
    ERR_STATUS send_command(const std::string& message);
    ERR_STATUS clear_display();



};


#endif //APPLICATION_LCD_H
