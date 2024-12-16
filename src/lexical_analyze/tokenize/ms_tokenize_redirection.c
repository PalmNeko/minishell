#include "lexer.h"

t_token	*ms_tokenize_redirection(const char *input, int pos)
{
	if (input[pos] == '<')
	{
		if (input[pos + 1] == '<')
			return (ms_create_token(TK_REDIRECTION, "<<", pos, pos + 2));
		return (ms_create_token(TK_REDIRECTION, "<", pos, pos + 1));
	}
	if (input[pos] == '>')
	{
		if (input[pos + 1] == '>')
			return (ms_create_token(TK_REDIRECTION, ">>", pos, pos + 2));
		return (ms_create_token(TK_REDIRECTION, ">", pos, pos + 1));
	}
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}
