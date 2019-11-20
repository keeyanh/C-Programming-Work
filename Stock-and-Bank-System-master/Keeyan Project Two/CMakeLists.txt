cmake_minimum_required(VERSION 3.8)
project(Keeyan_Project_Two)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Account.cpp Account.h StockAccount.cpp StockAccount.h BankAccount.cpp BankAccount.h)
add_executable(Keeyan_Project_Two ${SOURCE_FILES})