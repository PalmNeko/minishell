#include "lexer.h"
#include "libft.h"

int	ms_token_priority_cmp(t_token *left, t_token *right)
{
	return (left->type - right->type);
}