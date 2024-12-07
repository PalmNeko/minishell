#include "libft.h"
#include "tokenize.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	tk_is_identify(const char c);

t_token	*ms_tokenize_identify(const char *input, int pos)
{
	int		start_pos;
	int		end_pos;
	t_token	*token;
	char	*token_str;

	start_pos = pos;
	end_pos = pos;
	while (tk_is_identify(input[end_pos]))
		end_pos++;
	if (end_pos - start_pos < 1)
		return (ms_create_token(TK_DECLINED, "", pos, pos));
	token_str = malloc(end_pos - start_pos + 1);
	if (!token_str)
		return (NULL);
	ft_strlcpy(token_str, input + start_pos, (end_pos - start_pos) + 1);
	token = ms_create_token(TK_IDENTIFY, token_str, start_pos, end_pos);
	free(token_str);
	if (!token)
		return (NULL);
	return (token);
}

static bool	tk_is_identify(const char c)
{
	return (ft_isalpha(c) || c == '_');
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