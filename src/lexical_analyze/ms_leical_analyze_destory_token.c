#include "lexer.h"
#include "lexer_config.h"
#include "lexer_type.h"
#include <stdlib.h>

void	ms_lexical_analyze_destroy_token(t_token *token)
{
	if (token == NULL)
		return ;
	if (token->token != NULL)
		free(token->token);
	free(token);
}