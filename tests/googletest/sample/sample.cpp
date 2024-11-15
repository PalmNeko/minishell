#include <gtest/gtest.h>

extern "C" {
    #include "sample.h"
}

TEST(TestCaseName, TestName){
    EXPECT_EQ(0, ms_test());
}
