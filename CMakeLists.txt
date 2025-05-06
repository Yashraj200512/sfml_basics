cmake_minimum_required(VERSION 3.16)
project(tut1 VERSION 0.1.0 LANGUAGES CXX)

# Require C++17 (SFML 3+ needs at least C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Set the SFML directory
set(SFML_DIR "C:/Users/Dell/Desktop/SFML_VCPKG/vcpkg/installed/x64-windows/share/sfml")
# Locate SFML 3.0; list only the modules you actually use
find_package(SFML 3.0 REQUIRED COMPONENTS System Window Graphics)
    # audio
    # network

add_executable(game main.cpp)

# Link against the SFML imported targets
target_link_libraries(game PRIVATE SFML::System  SFML::Window SFML::Graphics)
