#ifndef AUTOGRAPHAPI_COMMUNICATOR_H
#define AUTOGRAPHAPI_COMMUNICATOR_H

#include <vector>
#include <cstdint>
#include <string>

class Communicator {
public:
    Communicator();
    ~Communicator();

    bool connect(const std::string& portName);
    void disconnect();
    bool writeData(const std::vector<uint8_t>& data);

private:
    int serialPort;      // Дескриптор порта
    bool isConnected;    // Флаг подключения
};

#endif // AUTOGRAPHAPI_COMMUNICATOR_H
