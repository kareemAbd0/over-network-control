//
// Created by kareem on 4/13/24.
//

#ifndef APPLICATION_MYCALLBACK_H
#define APPLICATION_MYCALLBACK_H

#include <string>
#include <mqtt/async_client.h>
class mycallback: public virtual mqtt::callback{

    public:

    std::string latest_message;

    private:


        void connected(const std::string& cause) override;
        void connection_lost(const std::string& cause) override;
        void delivery_complete(mqtt::delivery_token_ptr token) override;
        void message_arrived(mqtt::const_message_ptr msg) override;




};





#endif //APPLICATION_MYCALLBACK_H
