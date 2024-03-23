#include "gtest/gtest.h"
#include "spdlog/spdlog.h"

#include "tcore.h"

TEST(BASIC, OpenModelFile) {
    TCore tcore("mnist.tflite");
    tcore.display_info();

    EXPECT_TRUE(tcore.isOpened());
}
