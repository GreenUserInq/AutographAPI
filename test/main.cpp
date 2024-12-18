#include "AutographAPI/Communicator.h"
#include <iostream>
#include <vector>

int main() {
    // Укажите путь к последовательному порту
    std::string portName = "/dev/ttyUSB0"; // Для Linux. Для Windows это может быть "COM3", например.
    int baudRate = 9600; // Скорость соединения

    // Создание объекта Communicator
    Communicator comm(portName, baudRate);

    // Попытка подключения
    if (!comm.connect()) {
        std::cerr << "Ошибка: не удалось подключиться к устройству на порту " << portName << std::endl;
        return -1;
    }

    std::cout << "Подключение установлено на порту " << portName << std::endl;

    // Пример команды (например, удаление процесса с номером 1)
    std::vector<uint8_t> command = { 0x07, 0xF8, 0x01 };
    if (!comm.writeData(command)) {
        std::cerr << "Ошибка: не удалось отправить данные" << std::endl;
        comm.disconnect();
        return -1;
    }

    std::cout << "Команда отправлена успешно!" << std::endl;

    // Чтение ответа
    std::vector<uint8_t> response;
    if (comm.readData(response)) {
        std::cout << "Получен ответ от устройства: ";
        for (auto byte : response) {
            std::cout << std::hex << static_cast<int>(byte) << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cerr << "Ошибка: не удалось получить ответ от устройства" << std::endl;
    }

    // Закрытие соединения
    comm.disconnect();
    std::cout << "Соединение закрыто" << std::endl;

    return 0;
}
