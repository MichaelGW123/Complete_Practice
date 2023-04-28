#pragma once

#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Defs/specific.h"

/**
 * @class Communication
 * 
 * @brief Base Communication class to be inherited by TCP and UDP
 * 
 * @details The methods are all virtual. They are overriden when
 * inherited by UDP and TCP communication.
 */
class Communication {
public:
    Communication() = default;
    virtual ~Communication() = default;

    virtual bool Send(const unsigned char* message) = 0;
    virtual bool Receive(unsigned char* message) = 0;
};