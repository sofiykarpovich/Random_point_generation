cmake_minimum_required(VERSION 3.10) #Version_cmake
project(Points_ LANGUAGES CXX) #Name_project_and_language

set(CMAKE_CXX_STANDARD 20) #Intalling_version_language
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")


#Installing_variable
set(SOURCES
    src/basic_creation.cpp
    src/shift_to.cpp
    src/cmdline.cpp
    src/csv_formatter.cpp
    src/json_formatter.cpp
    src/main.cpp
) 


#Installing_variable
set(HEADERS
    include/creating_a_cluster.h
    include/cmdline.h
    include/formatter.h
    include/formatter_factory.h
    include/csv_formatter.h
    include/json_formatter.h
) 


add_executable(cluster ${SOURCES})

install(TARGETS cluster DESTINATION bin)
install(FILES ${HEADERS} DESTINATION include/cluster)


message(STATUS "Исполняемый файл: cluster")
message(STATUS "Тип сборки: ${CMAKE_BUILD_TYPE}")
