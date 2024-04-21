//
// Created by kareem on 4/13/24.
//

#include "app.h"

App& App::get_instance() {
    static App instance;
    return instance;
}



App::App() : client(Client::get_instance("broker.emqx.io", "tmp6570-app")),
    led1(1),
    led2(2),
    led3(3),
    led4(4),
    led5(5) {}


void App::init(){

    if (client.connect() == CONNECTION_STATUS::FAILURE) {
        std::cout << "Failed to connect" << std::endl;
        exit(1);
    }


    client.subscribe("tmp6570-control");
    if (led1.init() == NO_FILE) {
        std::cout << "Failed to initialize led1" << std::endl;
        exit(1);
    }
    led2.init();
    led3.init();
    led4.init();
    led5.init();
}


void App::run(){

    while(true) {

        std::string message = client.get_new_message();

        std::cout << "Message: " << message << std::endl;

        int message_num = std::stoi(message);

        int num_leds_on = message_num / 10;

        led1.turn_off();
        led2.turn_off();
        led3.turn_off();
        led4.turn_off();
        led5.turn_off();

        switch (num_leds_on) {
            case 5:
                if (led5.turn_on() == NO_FILE) {
                    std::cout << "Failed to turn on led5" << std::endl;
                    exit(1);
                }
            case 4:
                led4.turn_on();
            case 3:
                led3.turn_on();
            case 2:
                led2.turn_on();
            case 1:
                led1.turn_on();
            default:
                break;

        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }
}

