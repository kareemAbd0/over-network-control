//
// Created by kareem on 4/13/24.
//



#include "mycallback.h"


void mycallback::connected(const std::string &cause) {
    std::cout << "Connected! " << cause << std::endl;
}

void mycallback::connection_lost(const std::string &cause) {
    std::cout << "Connection lost! " << cause << std::endl;
}

void mycallback::delivery_complete(mqtt::delivery_token_ptr token) {
    if (!token) {
        std::cout << "Delivery failed" << std::endl;
        exit(1);
    }
    std::cout << "Delivery complete token: " << token->get_message_id() << std::endl;
}

void mycallback::message_arrived(mqtt::const_message_ptr msg) {
    std::cout << "Message arrived: " <<  std::endl;
    std::cout << "Topic: " << msg->get_topic() << std::endl;
    std::cout << "Payload: " << msg->to_string() << std::endl;
    std::cout << "Message size: " << msg->get_payload().size() << std::endl;
    if (msg->to_string().empty()) {
        std::cout << "Payload is empty" << std::endl;
    }else {
        latest_message = msg->to_string();
    }
}





