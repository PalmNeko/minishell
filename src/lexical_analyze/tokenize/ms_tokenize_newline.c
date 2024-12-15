#include "lexer.h"

t_token	*ms_tokenize_newline(const char *input, int pos)
{
	t_token	*token;

	if (*input == '\n')
		token = ms_create_token(TK_NEWLINE, "\n", pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
