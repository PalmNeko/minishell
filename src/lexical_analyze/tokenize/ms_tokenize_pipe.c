#include "lexer.h"

t_token	*ms_tokenize_pipe(const char *input, int pos)
{
	if (*input == '|')
		return (ms_create_token(TK_PIPE, "|", pos, pos + 1));
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}
