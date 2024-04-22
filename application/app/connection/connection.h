//
// Created by kareem on 4/13/24.
//

#ifndef APPLICATION_CONNECTION_H
#define APPLICATION_CONNECTION_H



#include <mqtt/async_client.h>
#include <memory>
#include <unordered_map>
#include <string>
#include "mycallback.h"

enum class CONNECTION_STATUS {SUCCESS, FAILURE};

/**
 * @brief Represents an MQTT client with simplified configuration, functionality and default values for the rpi project.
 */
class Client {
public:

    /**
     * @brief Gets the singleton instance of the MQTT client.
     * @return The singleton instance of the MQTT client.
     */
    static Client& get_instance(const std::string& server_address, const std::string& client_id);

    /**
     * @brief Destructor for the MQTT client. Disconnects the client.
     */
    ~Client();

    /**
     * @brief Establishes a connection to the MQTT broker.
     * @return Status of the connection attempt.
     */
    CONNECTION_STATUS connect();

    /**
     * @brief Subscribes to MQTT topics.
     * @return Status of the subscription attempt.
     */
    CONNECTION_STATUS subscribe(const std::string& topic);

    /**
     * @brief Publishes a message to the MQTT topic.
     * @param payload The message to be published.
     * @return Status of the publishing attempt.
     */
    CONNECTION_STATUS publish(const std::string& topic ,const std::string& payload);

    /**
     * @brief Disconnects the client from the MQTT broker.
     * @return Status of the disconnection attempt.
     */
    CONNECTION_STATUS disconnect();



    /**
     * @brief Sets the MQTT connection options.
     * @param connOpts The MQTT connection options.
     */
    void set_connOpts(const mqtt::connect_options &connOpts);

    /**
     * @brief Gets the current MQTT connection options.
     * @return The MQTT connection options.
     */
    const mqtt::connect_options &get_connOpts() const;


    /**
     * @brief Sets the Quality of Service (QoS) level.
     * @param QOS The Quality of Service level.
     */
    void set_qos(int QOS);

    /**
     * @brief Gets the server address and client id from the command line arguments, is is static because it is used before the client is created.
     * @param argc The number of command line arguments.
     * @param argv The command line arguments.
     * @return The server address and client id.
     */
    static std::pair<std::string, std::string> get_server_and_clientID(int argc, char* argv[]);

    /**
     * @brief Gets the current Quality of Service (QoS) level.
     * @return The Quality of Service level.
     */
    int get_qos() const;

    /**
     */
    std::string get_new_message();

private:

    /**
     * @brief Constructor for the MQTT client, sets some default values.
     * @param server_address The address of the MQTT server.
     * @param client_id The unique identifier for this client.
     */
    Client(const std::string& server_address, const std::string& client_id);

    mycallback cb; ///< Callback handler for MQTT events.
    mqtt::async_client cli; ///< The underlying Paho MQTT client.
    int QOS; ///< Quality of Service level.



    mqtt::connect_options connOpts; ///< MQTT connection options.
};







#endif //APPLICATION_CONNECTION_H
