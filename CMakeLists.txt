cmake_minimum_required(VERSION 3.10)

project(TFLCompiler)

add_subdirectory(3rd_party/flatbuffers)
add_subdirectory(3rd_party/gtest)
add_subdirectory(3rd_party/spdlog)

include_directories(
    "src"
    "src/schema"
    "3rd_party/spdlog/include"
    )

file(GLOB_RECURSE SRC_FILES
    "src/*.cc"
    "test/*.cc"
    )

add_executable(${PROJECT_NAME}.exe ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}.exe gtest_main flatbuffers)
