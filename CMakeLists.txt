cmake_minimum_required(VERSION 3.10)
project(AutographAPI VERSION 1.0.0 LANGUAGES CXX)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление библиотеки (статической или динамической)
add_library(AutographAPI STATIC
    src/Communicator.cpp
)

# Указываем заголовочные файлы
target_include_directories(AutographAPI PUBLIC
    ${CMAKE_CURRENT_SOURCE_DI
)

# Создание установочных целей
install(TARGETS AutographAPI
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)
