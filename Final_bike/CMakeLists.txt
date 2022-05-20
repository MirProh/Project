cmake_minimum_required(VERSION 3.20)
project(Final_bike)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
if (SFML_FOUND)
    message(FOUND)
    add_executable(Final_bike Final_bike/main.cpp Final_bike/main.h Final_bike/bike.cpp Final_bike/bike.h Final_bike/Vector.cpp Final_bike/Vector.h Final_bike/bike1.png Final_bike/Wheel.png)
    target_link_libraries(Final_bike sfml-system sfml-window sfml-graphics sfml-audio)
endif(SFML_FOUND)