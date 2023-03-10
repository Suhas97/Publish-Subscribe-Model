#include "subscribe.hpp"
#include <iostream>

// Implementation of Subscriber constructor
Subscriber::Subscriber(std::string t) {
    topic = t;
}

// Implementation of Subscriber::readMessage()
void Subscriber::readMessage(Message message) {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();  // get current time
    time_t time_c = std::chrono::system_clock::to_time_t(now); // convert time_point to time_t
    time_t time_x = std::chrono::system_clock::to_time_t(message.timestamp);
    std::cout << "Message received for topic: " << topic << " at " << ctime(&time_c) << ": The contents of the message are: " << message.content << ": Published at:" << ctime(&time_x) << std::endl;
}


// Implementation of Subscriber::subscribe()
void Subscriber::subscribe(Publisher& p) {
    p.subscribers.push_back(*this);
    messages = p.messages;
}