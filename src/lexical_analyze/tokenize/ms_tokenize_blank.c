#include "lexer.h"
#include "libft.h"
#include <stdlib.h>

t_token	*ms_tokenize_blank(const char *input, int pos)
{
	int	i;

	i = 0;
	if (input[pos] && ft_strchr(BLANK_CHARS, input[pos]))
	{
		while (input[pos + i] && ft_strchr(BLANK_CHARS, input[pos + i]))
			i++;
		return (ms_create_token(TK_BLANK, input + pos, pos, pos + i));
	}
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}
