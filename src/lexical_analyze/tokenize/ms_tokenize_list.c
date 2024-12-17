#include "lexer.h"
#include "libft.h"

t_token	*ms_tokenize_list(const char *input, int pos)
{
	if (ft_strncmp(input + pos, "&&", 2) == 0)
		return (ms_create_token(TK_LIST, "&&", pos, pos + 2));
	if (ft_strncmp(input + pos, "||", 2) == 0)
		return (ms_create_token(TK_LIST, "||", pos, pos + 2));
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}
