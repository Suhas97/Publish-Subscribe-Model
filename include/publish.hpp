#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "userdefined.hpp"

//Forward declaration of Subscriber Class
class Subscriber;

/**
 * @brief The Publisher class publishes messages to subscribers.
 */
class Publisher {
public:
    /**
     * @brief publish publishes a new message to the subscribers of the given topic.
     * @param topic The topic of the message.
     * @param message The content of the message.
     */
    void publish(std::string topic, std::string message);

    std::vector<Message> messages; ///< A list of all published messages.
    std::vector<Subscriber> subscribers; ///< A list of all subscribers.

private:
    /**
     * @brief notifySubscribers notifies all subscribers that have subscribed to a particular topic.
     * @param message The message to notify the subscribers of.
     */
    void notifySubscribers(Message message);
};

#endif /* PUBLISHER_H */
