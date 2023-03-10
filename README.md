# Publish-Subscribe System
A simple publish-subscribe system implementation using C++

## Design Decisions
The implementation uses two classes, Publisher and Subscriber, to realize the publish-subscribe pattern. The Publisher class maintains a vector of Message structs, where each Message struct contains a topic, content, and timestamp. The Subscriber class subscribes to the Publisher by providing the topic it is interested in. Whenever a new message is published on that topic, the Subscriber receives the message.

The Subscriber class has a subscribe method that takes a reference to the Publisher object as an argument. The subscribe method registers the Subscriber object with the Publisher object, so that it can receive messages on the topic it is interested in.

The implementation uses a simple message struct defined in userdefined.hpp.

## File Structure
```
|-- include/
|   |-- publish.hpp
|   |-- subscribe.hpp
|   |-- userdefined.hpp
|-- src/
|   |-- publish.cpp
|   |-- subscribe.cpp
|-- main.cpp
|-- Makefile
|-- README.md
```

## Code Structure
The code is organized into several files:

* userdefined.hpp: Contains the definition of the message struct used by the Publisher and Subscriber classes.
* publish.hpp: Contains the declaration of the Publisher class.
* publish.cpp: Contains the implementation of the Publisher class.
* subscribe.hpp: Contains the declaration of the Subscriber class.
* subscribe.cpp: Contains the implementation of the Subscriber class.
* main.cpp: Contains the main function that creates a Publisher object and two Subscriber objects and tests the system.


## How to Run
The code can be compiled using the provided Makefile by running the command `make`. This will create an executable file named publish-subscribe.

To run the program, execute the following command:
`./publish-subscribe`

This will run the main function and test the publish-subscribe system. The program will create a Publisher object and two Subscriber objects, and will publish four messages on two different topics. The output of the program will show which messages were received by which subscribers.


## Public Interfaces

The public interfaces of the Publisher and Subscriber classes are documented in their respective header files, publish.hpp and subscribe.hpp.

The Publisher class has the following public interface:
```
class Publisher {
public:
    void publish(std::string topic, std::string content);
    void addMessage(std::string topic, std::string content);
    void notify();
    std::vector<Message> getMessages();
};
```

The Subscriber class has the following public interface:
```
class Subscriber {
public:
    Subscriber(std::string topic);
    void subscribe(Publisher& pub);
    void receive(Message msg);
};
```

##Console Output
![output](https://drive.google.com/file/d/1Oyj8ssD6Y71tB7aMCj2zAYEw1Wk8kcSH/view?usp=sharing)