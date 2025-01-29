#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include <string>

extern "C" {
    #include "execution.h"
	#include "libms.h"
	#include "lexer.h"
	#include "syntax_analyze.h"
	#include "semantic_analyze.h"
};

TEST(Execute, ms_execution)
{
	std::string input = "echo HOME";
	std::string expected_output = getenv("HOME") + std::string("\n");
	
	testing::internal::CaptureStdout();
	int ret = ms_execution(input.c_str());
	ASSERT_EQ(ret, 0);
	ASSERT_STREQ(testing::internal::GetCapturedStdout().c_str(), expected_output.c_str());
}