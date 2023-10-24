cmake_minimum_required(VERSION 3.22.1)

project(ChukutoInventory VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH "bin")

file(GLOB clases CONFIGURE_DEPENDS
src/clases/*.cpp
)

add_compile_definitions(PLATFORM=${CMAKE_SYSTEM_NAME})

add_executable(ChukutoInventory src/main.cpp ${clases})

if(UNIX)
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries(ChukutoInventory ${CURSES_LIBRARIES})
endif(UNIX)