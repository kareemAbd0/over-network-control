//
// Created by kareem on 4/13/24.
//

#include "app.h"

App& App::get_instance() {
    static App instance;
    return instance;
}



App::App() : client(Client::get_instance("broker.emqx.io", "app455")),
    led1(1),
    led2(2),
    led3(3),
    led4(4),
    led5(5),
    lcd1(1){}


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

    std::string old_message = " ";
    while(true) {

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::string message = client.get_new_message();

        std::cout << "Message: " << message << std::endl;
        if (message == old_message) {
            continue;
        }

        if (isdigit(message[0])) {
            temp_run(message);
        } else if (message[0] == 'o') {
            garage_run(message);
        } else std::cout << "Invalid message" << std::endl;


        old_message = message;

    }
}



void App::temp_run(const std::string& message) {
    lcd1.clear_display();
    lcd1.send_command("0x01");
    lcd1.display_text("AC temp: " + message + "C");

    int message_num = std::stoi(message);

    int num_leds_on = message_num / 6;

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

}

void App::garage_run(const std::string& message) {
    lcd1.clear_display();
    lcd1.send_command("0x01");
    lcd1.display_text("Garage: "+ message);

    led1.turn_off();
    led2.turn_off();
    led3.turn_off();
    led4.turn_off();
    led5.turn_off();

    if (message == "on"){
        //blink led5 for 3 seconds
        for (int i = 0; i < 6; i++) {
            led5.turn_on();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            led5.turn_off();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        led1.turn_on();
    }
    else if (message == "off"){
        //blink led1 for 3 seconds
        for (int i = 0; i < 6; i++) {
            led1.turn_on();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            led1.turn_off();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        led5.turn_on();
    }
    else {
        std::cout << "Invalid message" << std::endl;
    }
}

