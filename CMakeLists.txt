cmake_minimum_required(VERSION 3.10)
project(Point_ LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

set(SOURCES
    src/Source.cpp
    src/shift_to.cpp
)

set(HEADERS
    include/point.h
)

add_executable(Point_ ${SOURCES})

install(TARGETS Point_ DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include/Point_)

message(STATUS "Конфигурация завершена")
message(STATUS "Исполняемый файл: RandomPointGeneration")
message(STATUS "Тип сборки: ${CMAKE_BUILD_TYPE}")