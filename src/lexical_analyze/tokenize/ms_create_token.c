#include "lexer.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_token	*ms_create_token(t_token_type type, const char *token, int start_pos,
		int end_pos)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->type = type;
	new_token->token = ft_strdup(token);
	if (new_token->token == NULL)
		return (ms_lexical_analyze_destroy_token(new_token), NULL);
	new_token->start_pos = start_pos;
	new_token->end_pos = end_pos;
	return (new_token);
}
