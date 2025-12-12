cmake_minimum_required(VERSION 3.10)
project(Inventario_Electrónica)

include_directories(include)

set(CMAKE_CXX_STANDARD 17)
#set("/usr/lib/x86_64-linux-gnu/Qt6_DIR")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(SQLite3 REQUIRED)

add_executable(inventario
    main.cpp
    src/database.cpp
    src/inventory.cpp
    include/inventory.h
)

target_include_directories(inventario PRIVATE include)
target_link_libraries(inventario Qt5::Widgets sqlite3)