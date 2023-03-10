#ifndef USERDEFINED_H
#define USERDEFINED_H

#include <string>
#include <chrono>

/**
 * @brief The Message struct represents a message being sent through the pub/sub system.
 */
struct Message {
    std::string topic; ///< The topic of the message.
    std::string content; ///< The content of the message.
    std::chrono::system_clock::time_point timestamp; ///< The timestamp of when the message was created.
};

#endif /* USERDEFINED_H */
