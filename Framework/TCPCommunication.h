#pragma once

#include "Communication.h"

/**
 * @class TCPCommunication Class
 * 
 * @brief Class to send information via TCP
 * 
 * @details TCP performs a handshake with recipient
 * before sending data. Also can only send one to 
 * one.
 */
class TCPCommunication: public Communication{
    public:
        TCPCommunication();
        virtual ~TCPCommunication();
        
        bool Send(const unsigned char* message) override;
        bool Receive(unsigned char* message) override;

    private:
        int m_socket;
};