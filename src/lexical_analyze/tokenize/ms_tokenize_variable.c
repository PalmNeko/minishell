#include "lexer.h"
#include "libft.h"

t_token	*ms_tokenize_variable(const char *input, int pos)
{
	int	i;

	i = 0;
	if (input[pos] == '$' && (ft_includes(input[pos + 1], LETTER_CHARS)
			|| input[pos + 1] == '?'))
	{
		i++;
		if (ft_strchr(LETTER_CHARS, input[pos + 1]) || input[pos + 1] == '?')
			i++;
		while (ft_includes(input[pos + i], LETTER_CHARS)
			|| ft_includes(input[pos + i], DIGIT_CHARS))
			i++;
		return (ms_create_token(TK_VARIABLE, input + pos, pos, pos + i));
	}
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}
