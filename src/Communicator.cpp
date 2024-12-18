#include "AutographAPI/Communicator.h"
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

Communicator::Communicator() : serialPort(-1), isConnected(false) {}

Communicator::~Communicator() {
    disconnect();
}

bool Communicator::connect(const std::string& portName) {
    serialPort = open(portName.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (serialPort < 0) {
        std::cerr << "Failed to open port: " << portName << std::endl;
        return false;
    }
    isConnected = true;
    return true;
}

void Communicator::disconnect() {
    if (isConnected) {
        close(serialPort);
        isConnected = false;
    }
}

bool Communicator::writeData(const std::vector<uint8_t>& data) {
    if (!isConnected || serialPort < 0) return false;
    ssize_t written = write(serialPort, data.data(), data.size());
    return written == static_cast<ssize_t>(data.size());
}
