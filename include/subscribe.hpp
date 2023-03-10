#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>
#include <chrono>
#include <vector>
#include "userdefined.hpp"
#include "publish.hpp"

/**
 * @brief The Subscriber class receives messages published by the Publisher.
 */
class Subscriber {
public:
    /**
     * @brief Subscriber constructor initializes a Subscriber object with the given topic.
     * @param t The topic the Subscriber wants to subscribe to.
     */
    Subscriber(std::string t);

    /**
     * @brief readMessage prints the message content of the message it receives along with its timestamp.
     * @param message The message the Subscriber receives.
     */
    void readMessage(Message message);

    /**
     * @brief subscribe subscribes to the Publisher with the given topic.
     * @param p The Publisher to subscribe to.
     */
    void subscribe(Publisher& p);

    std::vector<Message> messages; ///< A list of all messages the Subscriber has received.
    std::string topic; ///< The topic the Subscriber is subscribed to.
};

#endif /* SUBSCRIBER_H */
