#include "CaptureFd.hpp"
#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include "libms.h"
};

// 標準エラー出力にフォーマットに沿った出力を行うこと。
TEST(ms_perror_shell, basic)
{
	CaptureFd	capFd;
	std::string	error_output;

	capFd.capture(2);
	ms_perror_shell("yeeeas");
	error_output = capFd.read();
	capFd.unCapture();
	EXPECT_EQ("minishell: yeeeas\n", error_output);
}
