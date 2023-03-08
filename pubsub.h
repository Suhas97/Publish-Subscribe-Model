#ifndef PUBSUBLIB_H
#define PUBSUBLIB_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

// Forward declaration of Subscriber class
class Subscriber;

// Define the Message structure
struct Message {
    string topic;
    string content;
    chrono::system_clock::time_point timestamp; // timestamp field added
};

// Define the Publisher class
class Publisher {
public:
    void publish(string topic, string message);

    vector<Message> messages;
    vector<Subscriber> subscribers;

private:
    void notifySubscribers(Message message);
};

// Define the Subscriber class
class Subscriber {
public:
    string topic;

    Subscriber(string t) {
        topic = t;
    }

    void readMessage(Message message) {
        chrono::system_clock::time_point now = chrono::system_clock::now();  // get current time
        time_t time_c = chrono::system_clock::to_time_t(now); // convert time_point to time_t
        time_t time_x = chrono::system_clock::to_time_t(message.timestamp);
        cout << "Message received for topic " << topic << " at " << ctime(&time_c) << ": " << message.content << "," << ctime(&time_x) << endl;
    }

    void subscribe(Publisher& p) {
        p.subscribers.push_back(*this);
        messages = p.messages;
    }

    vector<Message> messages;
};

// Implementation of Publisher methods
void Publisher::publish(string topic, string message) {
    chrono::system_clock::time_point now = chrono::system_clock::now(); // get current time
    Message m;
    m.topic = topic;
    m.content = message;
    m.timestamp = now; // set timestamp field
    messages.push_back(m);
    notifySubscribers(m);
}

void Publisher::notifySubscribers(Message message) {
    for (int i = 0; i < subscribers.size(); i++) {
        if (subscribers[i].topic == message.topic) {
            subscribers[i].readMessage(message);
        }
    }
}

#endif /* PUBSUBLIB_H */
