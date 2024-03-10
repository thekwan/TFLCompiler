#include <iostream>

#include "gtest/gtest.h"
#include "schema_v3a_generated.h"

#include "core.h"

int main(int argc, char* argv[]) {
    Core core("test.tflite");

    std::cout << "hello world!" << std::endl;

    return 0;
}
