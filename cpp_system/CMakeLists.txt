cmake_minimum_required(VERSION 3.10)
project(cpp_system)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # this will generate compile_commands.json file

#tell CMake where to look for *.hpp ,*.h files
include_directories(include/)
#create library "libfirst", this creates libfirst.a 
add_library(first src/first.cpp)

#add executable main, this creates main.o
add_executable(main src/main.cpp)

#tell the linker to bind these object files together and provide with the final executable
target_link_libraries(main first)
