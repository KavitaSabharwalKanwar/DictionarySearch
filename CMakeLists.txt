cmake_minimum_required(VERSION 3.11.3)

# set(CMAKE_CXX_STANDARD 17)
project(DictionarySearch)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(DictionarySearch ${project_SRCS})