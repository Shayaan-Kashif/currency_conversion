cmake_minimum_required(VERSION 3.10)
project(currency_conversion)

set(CMAKE_CXX_STANDARD 14)

# Include directory for header files
include_directories(include)

# Add library
add_library(currency_conversion src/currency_conversion.cpp)

# Example executable
add_executable(currency_conversion_example main.cpp)

# Link the library with the executable
target_link_libraries(currency_conversion_example currency_conversion)
