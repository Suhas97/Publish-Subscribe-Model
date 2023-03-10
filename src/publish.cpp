#include "publish.hpp"
#include "subscribe.hpp"

// Implementation of Publisher methods

void Publisher::publish(std::string topic, std::string message) {
    // Get the current time
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Create a new message with the given topic, content, and timestamp
    Message m;
    m.topic = topic;
    m.content = message;
    m.timestamp = now;

    // Add the message to the list of messages
    messages.push_back(m);

    // Notify subscribers about the new message
    notifySubscribers(m);
}

void Publisher::notifySubscribers(Message message) {
    // Loop through all subscribers and notify those subscribed to the same topic
    for (int i = 0; i < subscribers.size(); i++) {
        if (subscribers[i].topic == message.topic) {
            subscribers[i].readMessage(message);
        }
    }
}

