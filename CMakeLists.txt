cmake_minimum_required(VERSION 4.2)
project(badappleChallengeInConsole)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/tyk12/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(badappleChallengeInConsole main.cpp)

set_target_properties(badappleChallengeInConsole PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(badappleChallengeInConsole
    PRIVATE
        fmt::fmt
        spdlog::spdlog
        ${OpenCV_LIBS}
)