# Create a library target called "CommunicationLib"
add_library(CommunicationLib STATIC
    TCPCommunication.cpp
    UDPCommunication.cpp
)