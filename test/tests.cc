#include "gtest/gtest.h"
#include "spdlog/spdlog.h"

#include "core.h"

TEST(BASIC, OpenModelFile) {
    Core core("utest1.tflite");

    EXPECT_TRUE(core.isOpened());
}
