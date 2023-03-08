#include "pubsub.h"

int main() {
    Publisher p;
    Subscriber s1("topic1");
    Subscriber s2("topic2");

    s1.subscribe(p);
    s2.subscribe(p);

    p.publish("topic1", "message1");
    p.publish("topic2", "message2");

    p.publish("topic1", "message3");
    p.publish("topic2", "message4");

    return 0;
}
