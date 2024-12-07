#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <vector>

extern "C"
{
	#include "lexer_type.h"
};

struct TokenTestCase {
    t_token_type    type;
    const char      *token;
    int             start_pos;
    int             end_pos;
    const char      *description;
};


#endif // TEST_UTILS_HPP