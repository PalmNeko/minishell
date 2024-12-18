#include "lexer.h"
#include <stdlib.h>

void	ms_lexical_analyze_destroy_token(t_token *token)
{
	if (token)
	{
		free((void *)token->token);
		free(token);
	}
}