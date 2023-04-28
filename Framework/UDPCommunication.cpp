#include "UDPCommunication.h"
#include <iostream>
#include <cstring>
#include <unistd.h>

/**
 * @brief Construct a new UDPCommunication::UDPCommunication object 
 */
UDPCommunication::UDPCommunication(){
    m_socket = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_addr.sin_port = htons(12345);

    bind(m_socket, (struct sockaddr*)&m_addr, sizeof(m_addr));
}

/**
 * @brief Destroy the UDPCommunication::UDPCommunication object 
 */
UDPCommunication::~UDPCommunication(){
    close(m_socket);
}

/**
 * @brief Send message via UDP
 * 
 * @param message 
 * @return true 
 * @return false 
 */
bool UDPCommunication::Send(const unsigned char* message){
    const unsigned char* msg = message;

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    dest_addr.sin_port = htons(12346);

    // if (sendto(m_socket, msg, strlen(msg), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) < 0) {
    //     std::cerr << "UDP sendto error" << std::endl;
    //     return false;
    // }

    return true;
}

/**
 * @brief Receive message via UDP
 * 
 * @param message 
 * @return true 
 * @return false 
 */
bool UDPCommunication::Receive(unsigned char* message){
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    struct sockaddr_in src_addr;
    socklen_t src_addr_len = sizeof(src_addr);

    int n = recvfrom(m_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&src_addr, &src_addr_len);
    if (n < 0) {
        std::cerr << "UDP recvfrom error" << std::endl;
        return false;
    }

    return true;
}