#include "AutographAPI/Communicator.h"
#include <iostream>
#include <vector>

int main() {
    // ������� ���� � ����������������� �����
    std::string portName = "/dev/ttyUSB0"; // ��� Linux. ��� Windows ��� ����� ���� "COM3", ��������.
    int baudRate = 9600; // �������� ����������

    // �������� ������� Communicator
    Communicator comm(portName, baudRate);

    // ������� �����������
    if (!comm.connect()) {
        std::cerr << "������: �� ������� ������������ � ���������� �� ����� " << portName << std::endl;
        return -1;
    }

    std::cout << "����������� ����������� �� ����� " << portName << std::endl;

    // ������ ������� (��������, �������� �������� � ������� 1)
    std::vector<uint8_t> command = { 0x07, 0xF8, 0x01 };
    if (!comm.writeData(command)) {
        std::cerr << "������: �� ������� ��������� ������" << std::endl;
        comm.disconnect();
        return -1;
    }

    std::cout << "������� ���������� �������!" << std::endl;

    // ������ ������
    std::vector<uint8_t> response;
    if (comm.readData(response)) {
        std::cout << "������� ����� �� ����������: ";
        for (auto byte : response) {
            std::cout << std::hex << static_cast<int>(byte) << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cerr << "������: �� ������� �������� ����� �� ����������" << std::endl;
    }

    // �������� ����������
    comm.disconnect();
    std::cout << "���������� �������" << std::endl;

    return 0;
}
