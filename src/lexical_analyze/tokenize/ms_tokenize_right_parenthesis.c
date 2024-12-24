#include "lexer.h"

t_token	*ms_tokenize_right_parenthesis(const char *input, int pos)
{
	t_token *token;

	if (input[pos] == ')')
		token = ms_create_token(TK_RIGHT_PARENTHESIS, ")", pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}