#include <iostream>

#include "gtest/gtest.h"
#include "schema_v3a_generated.h"

#include "core.h"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
