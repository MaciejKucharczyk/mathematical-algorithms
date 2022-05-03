cmake_minimum_required(VERSION 3.22)
project(oiak_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(oiak_project project/main.cpp project/Menu/Menu.cpp project/Menu/Menu.h project/algorithms/RPN.cpp project/algorithms/RPN.h project/algorithms/GCD.cpp project/algorithms/GCD.h project/algorithms/Fibonacci.cpp project/algorithms/Fibonacci.h project/algorithms/SystemConversion.cpp project/algorithms/SystemConversion.h project/AutomaticTests.cpp project/AutomaticTests.h project/Menu/AutoTestMenu.cpp project/Menu/AutoTestMenu.h project/other/Timer.cpp project/other/Timer.h project/Menu/SystemConversionMenu.cpp project/Menu/SystemConversionMenu.h)
