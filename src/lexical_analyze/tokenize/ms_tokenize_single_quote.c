#include "lexer.h"

t_token	*ms_tokenize_single_quote(const char *input, int pos)
{
	t_token	*token;

	if (*input == '\'')
		token = ms_create_token(TK_SINGLE_QUOTE, "'", pos, pos + 1);
	else
		token = ms_create_token(TK_DECLINED, "", pos, pos);
	return (token);
}
