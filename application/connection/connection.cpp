//
// Created by kareem on 4/13/24.
//


#include "connection.h"


Client::Client(const std::string &address, const std::string &client_id) : cli(address, client_id),
    QOS(1),
    connOpts(mqtt::connect_options_builder().clean_session().will(mqtt::message("will", "client disconnected", 1, true)).keep_alive_interval(std::chrono::seconds(60)).finalize()){
    cli.set_callback(cb);

}


Client& Client::get_instance(const std::string &server_address, const std::string &client_id) {
    static Client instance(server_address, client_id);
    return instance;
}



CONNECTION_STATUS Client::connect() {
    try {
        cli.connect(connOpts)->wait();
    } catch (const mqtt::exception& e) {
        return CONNECTION_STATUS::FAILURE;
    }
    return CONNECTION_STATUS::SUCCESS;
}


CONNECTION_STATUS Client::subscribe( const std::string& topic) {
    try {
        cli.subscribe(topic, QOS)->wait();
    } catch (const mqtt::exception& e) {
        return CONNECTION_STATUS::FAILURE;
    }
    return CONNECTION_STATUS::SUCCESS;
}


CONNECTION_STATUS Client::publish(const std::string& topic, const std::string& payload) {
    try {
        cli.publish(topic, payload, QOS, false)->wait();
    } catch (const mqtt::exception& e) {
        return CONNECTION_STATUS::FAILURE;
    }
    return CONNECTION_STATUS::SUCCESS;
}

void Client::set_qos(int QOS) {
    this->QOS = QOS;
}

int Client::get_qos() const {
    return QOS;
}


std::pair<std::string, std::string> Client::get_server_and_clientID(int argc, char* argv[]){
    std::string SERVER_ADDRESS;
    std::string CLIENT_ID;
    switch (argc) {
        case 1:
            SERVER_ADDRESS = "broker.emqx.io";
            CLIENT_ID = "rpi_01";
            break;
        case 2:
            SERVER_ADDRESS = argv[1];
            CLIENT_ID = "rpi_01";
            break;
        case 3:
            SERVER_ADDRESS = argv[1];
            CLIENT_ID = argv[2];
            break;
        default:
            std::cout << "too many arguments provided" << std::endl;
            std::cout << "usage: harmony_rpi <server address> <client id>" << std::endl;
            exit(1);
    }
    std::cout << "server address is " << SERVER_ADDRESS << std::endl;
    std::cout << "client id is " << CLIENT_ID << std::endl;
    return {SERVER_ADDRESS, CLIENT_ID};
}






CONNECTION_STATUS Client::disconnect() {
    try {
        cli.disconnect()->wait();
    } catch (const mqtt::exception& e) {
        return CONNECTION_STATUS::FAILURE;
    }
    return CONNECTION_STATUS::SUCCESS;
}


void Client::get_new_message() {
    std::cout << this->cb.latest_message << std::endl;
}



void Client::set_connOpts(const mqtt::connect_options &connOpts) {
    this->connOpts = connOpts;
}


const mqtt::connect_options &Client::get_connOpts() const {
    return connOpts;
}


Client::~Client() {
    disconnect();
}








