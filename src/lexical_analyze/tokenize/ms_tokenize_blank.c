#include "lexer.h"
#include "libft.h"
#include <stdlib.h>

t_token	*ms_tokenize_blank(const char *input, int pos)
{
	int		start_pos;
	int		end_pos;
	t_token	*token;
	char	*token_str;

	start_pos = pos;
	end_pos = pos;
	while (ft_includes(input[end_pos], BLANK_CHARS))
		end_pos++;
	if (end_pos - start_pos > 0)
	{
		token_str = malloc(end_pos - start_pos + 1);
		if (!token_str)
			return (NULL);
		ft_strlcpy(token_str, input + start_pos, (end_pos - start_pos) + 1);
		token = ms_create_token(TK_BLANK, token_str, start_pos, end_pos);
		free(token_str);
		if (!token)
			return (NULL);
		return (token);
	}
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}
