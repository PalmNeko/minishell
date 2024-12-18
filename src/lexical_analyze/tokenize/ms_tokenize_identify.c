
#include "lexer.h"
#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

t_token	*ms_tokenize_identify(const char *input, int pos)
{
	int	i;

	i = 0;
	if (input[pos] && ft_strchr(LETTER_CHARS, input[pos]))
	{
		i++;
		while (input[pos + i] && (ft_strchr(LETTER_CHARS, input[pos + i])
				|| ft_strchr(DIGIT_CHARS, input[pos + i])))
			i++;
		return (ms_create_token(TK_IDENTIFY, input + pos, pos, pos + i));
	}
	return (ms_create_token(TK_DECLINED, "", pos, pos));
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_token *token;

// 	token = ms_tokenize_identify("_test", 0);
// 	printf("token->type: %d\n", token->type);
// 	printf("token->token: %s\n", token->token);
// 	printf("token->start_pos: %d\n", token->start_pos);
// 	if (token->type != TK_IDENTIFY)
// 		return (1);
// 	if (token->start_pos != 0)
// 		return (1);
// 	if (token->end_pos != 3)
// 		return (1);
// 	return (0);
// }