#pragma once

#include "Communication.h"

/**
 * @class UDPCommunication Class
 * 
 * @brief Class to send information via UDP
 * 
 * @details UDP does not require a handshake with
 * the recipient and can broadcast, send to 
 * multiple people at once.
 */
class UDPCommunication: public Communication{
    public:
        UDPCommunication();
        virtual ~UDPCommunication();

        bool Send(const unsigned char* message) override;
        bool Receive(unsigned char* message) override;

    private:
        int m_socket;
        struct sockaddr_in m_addr;
};