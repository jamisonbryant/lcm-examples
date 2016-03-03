# Set CMake metadata
cmake_minimum_required(VERSION 3.2)
project(BotThisWay)

# Set compiled files output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set executables to be built
add_executable(receiver src/lcm_example/receiver.cpp)
add_executable(sender src/lcm_example/sender.cpp)

# Add etc/cmake to CMake module path
# This is where we keep .cmake files for LCM and other non-standard-CMake libraries
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/etc/cmake")

# Find and load LCM (see etc/cmake/FindLCM.cmake)
find_package(LCM REQUIRED)
if (LCM_FOUND)
    include_directories(${LCM_INCLUDE_DIR})
    target_link_libraries(receiver ${LCM_LIBRARY_OPTIMIZED})
    target_link_libraries(sender ${LCM_LIBRARY_OPTIMIZED})
    set(LIBS ${LIBS} ${LCM_LIBRARY_OPTIMIZED})
endif(LCM_FOUND)

# Set source files to be compiled
set(SOURCE_FILES
    src/lcm_example/example/example_t.hpp
    src/lcm_example/receiver.cpp
    src/lcm_example/sender.cpp)