#include "lexer.h"
#include "libft.h"

t_token	*ms_tokenize_word(const char *input, int pos)
{
	int	i;

	i = 0;
	if (!ft_strchr(META_CHARS, input[pos]))
	{
		while (input[pos + i] && !ft_isspace(input[pos + i])
			&& !ft_strchr(META_CHARS, input[pos + i]) && !ft_strchr(QUOTE_CHARS,
				input[pos + i]))
			i++;
		return (ms_create_token(TK_WORD, input + pos, pos, pos + i));
	}
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}
