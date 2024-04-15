#include <iostream>
#include "connection/connection.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Client& client = Client::get_instance("broker.emqx.io", "client_id");
    client.connect();
    client.subscribe("tmp6570-control");

    while (1);



    return 0;
}
