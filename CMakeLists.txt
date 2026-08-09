cmake_minimum_required(VERSION 3.20)

project(
    Hikari
    VERSION 0.1.0
    DESCRIPTION "Educational web browser"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    Hikari
    app/main.cpp
    browser/Browser.cpp
    net/URL.cpp
)

target_include_directories(
    Hikari
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)