cmake_minimum_required(VERSION 3.10)

project(FileHeaderViewer VERSION 1.0)

set(CMAKE_CXX_COMPILER /usr/local/Cellar/llvm/19.1.1/bin/clang++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(FileHeaderViewer
    src/main.cpp
    src/file_header_viewer.cpp
    src/file_reader.cpp
)

target_include_directories(FileHeaderViewer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
