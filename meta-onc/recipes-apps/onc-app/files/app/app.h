//
// Created by kareem on 4/13/24.
//

#ifndef APPLICATION_APP_H
#define APPLICATION_APP_H
#include "../connection/connection.h"
#include "../hw/lcd.h"
#include "../hw/led.h"
#include <string>



class App{

private:
    App();
    Client& client;
    Led led1;
    Led led2;
    Led led3;
    Led led4;
    Led led5;

public:
    static App& get_instance();
    void init();
    void run();
};


#endif //APPLICATION_APP_H
