cmake_minimum_required(VERSION 3.12)

project(cross-the-road-game)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/main.cpp")

if (APPLE) 
    set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.0")
elseif (WIN32)
    # Đặt đường dẫn đến thư mục cài đặt của SFML trên Windows
    set(SFML_DIR "ĐƯỜNG_DẪN_ĐẾN_THƯ_MỤC_SFML")
endif()

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(game ${SOURCES})

target_link_libraries(game sfml-graphics sfml-window sfml-system)

target_include_directories(game PRIVATE ${SFML_INCLUDE_DIR})

