cmake_minimum_required(VERSION 3.12)

project(cross-the-road-game)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

if (APPLE) 
    set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.0")
elseif (WIN32)
    # Đặt đường dẫn đến thư mục cài đặt của SFML trên Windows
    set(SFML_DIR "C:/SFML-2.6.0")
endif()

find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

add_executable(game ${SOURCES})

target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-audio)

target_include_directories(game PRIVATE ${SFML_INCLUDE_DIR})
