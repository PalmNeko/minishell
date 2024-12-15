#ifndef MS_TOKENIZE_TEST_TYPES_H
# define MS_TOKENIZE_TEST_TYPES_H

# include <cstddef>
# include <functional>
# include "lexer_type.h"

struct				Tokenize_TestCase
{
	const char		*input;
	const int		pos;
	const t_token	*expect;
	const char		*description;
};

void				ms_tokenize_test_runner(const std::function<t_token *(const char *,
							int)> &ms_tokenize_func,
						const Tokenize_TestCase *test_cases, size_t size);

#endif