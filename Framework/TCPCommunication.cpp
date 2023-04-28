#include "TCPCommunication.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

/**
 * @brief Construct a new TCPCommunication::TCPCommunication object 
 */
TCPCommunication::TCPCommunication(){
    m_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(12347);

    bind(m_socket, (struct sockaddr*)&addr, sizeof(addr));

    listen(m_socket, 5);
}

/**
 * @brief Destroy the TCPCommunication::TCPCommunication object 
 */
TCPCommunication::~TCPCommunication(){
    close(m_socket);
}

/**
 * @brief Send message via TCP
 * 
 * @param message 
 * @return true 
 * @return false 
 */
bool TCPCommunication::Send(const unsigned char* message) {
    const unsigned char* msg = message;

    int client_socket = accept(m_socket, nullptr, nullptr);
    if (client_socket < 0) {
        std::cerr << "TCP accept error" << std::endl;
        return false;
    }

    // if (send(client_socket, msg, strlen(msg), 0) < 0) {
    //     std::cerr << "TCP send error" << std::endl;
    //     return false;
    // }

    close(client_socket);

    return true;
}

/**
 * @brief Receive message via TCP
 * 
 * @param message 
 * @return true 
 * @return false 
 */
bool TCPCommunication::Receive(unsigned char* message) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    int client_socket = accept(m_socket, nullptr, nullptr);
    if (client_socket < 0) {
        std::cerr << "TCP accept error" << std::endl;
        return false;
    }

    int n = recv(client_socket, buffer, sizeof(buffer), 0);
    if (n < 0) {
        std::cerr << "TCP recv error" << std::endl;
        return false;
    }

    // message = std::string(buffer, n);

    close(client_socket);

    return true;
}