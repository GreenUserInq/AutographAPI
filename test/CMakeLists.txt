cmake_minimum_required(VERSION 3.10)
project(AutographTest LANGUAGES CXX)

add_executable(AutographTest main.cpp)
target_link_libraries(AutographTest PRIVATE AutographAPI)
