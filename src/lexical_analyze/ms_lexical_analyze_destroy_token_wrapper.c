#include "lexer.h"

void	ms_lexical_analyze_destroy_token_wrapper(void *token)
{
	ms_lexical_analyze_destroy_token((t_token *)token);
}