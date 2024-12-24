#include "lexer.h"

t_token	*ms_tokenize_equal(const char *input, int pos)
{
	t_token	*token;

	input += pos;
	if (*input == '=')
		token = ms_create_token(TK_EQUALS, "=", pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
