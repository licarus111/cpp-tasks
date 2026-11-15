cmake_minimum_required(VERSION 4.3)
project(PhysCat)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

add_executable(PhysCat main.cpp
        Inventory.cpp
        Inventory.hpp
        Transport.cpp
        Transport.hpp
        Things.cpp
        Things.hpp
        ServiceCenter.cpp
        ServiceCenter.hpp
        Registry.hpp
        Errors.hpp)
