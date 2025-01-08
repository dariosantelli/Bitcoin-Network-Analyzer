cmake_minimum_required(VERSION 3.28)

set(PROJECT_NAME BitcoinNetworkAnalyzer)

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)

# Compiler warnings
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -pedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
endif()

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
)

set(HEADERS
    src/MainWindow.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Enable modern CMake features
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Widgets
)

option(ENABLE_SANITIZERS "Enable sanitizers for debugging" OFF)
if (ENABLE_SANITIZERS)
    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address -fsanitize=thread -fsanitize=undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address -fsanitize=thread -fsanitize=undefined)
endif()
