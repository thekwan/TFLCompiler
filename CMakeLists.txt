cmake_minimum_required(VERSION 3.10)

project(NNCompiler)

add_subdirectory(3rd_party/flatbuffers)
add_subdirectory(3rd_party/gtest)

include_directories("src/schema")

file(GLOB_RECURSE SRC_FILES "src/*.cc")

add_executable(${PROJECT_NAME}.exe ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}.exe gtest_main flatbuffers)
