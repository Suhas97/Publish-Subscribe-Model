#include "publish.hpp"
#include "subscribe.hpp"

int main() {
    // Create a Publisher object
    Publisher p;

    // Create two Subscriber objects, one for each topic
    Subscriber s1("topic1");
    Subscriber s2("topic2");

    // Subscribe both subscribers to the publisher
    s1.subscribe(p);
    s2.subscribe(p);

    // Publish messages to both topics
    p.publish("topic1", "message1");
    p.publish("topic2", "message2");
    p.publish("topic1", "message3");
    p.publish("topic2", "message4");

    // Exit program
    return 0;
}
