#include "lexer.h"
#include "libft.h"
#include <stdlib.h>

static t_token	*get_token(const char *input, int pos);
static int		compare_priority(t_token *temp_token, t_token *token);
/*
--懸念事項--
tokenizeが不十分かもしれない
42戻ってきたらしっかり見直そうね
libft.hのlst系がテストに引っかかっていたので思い出してね
*/

t_token	**ms_lexical_analyze(const char *input)
{
	t_token_list	*lst;
	t_token_list	*new_lst;
	t_token			**tokens;
	t_token			*token;
	size_t			size;
	t_token_list	*temp;
	size_t			pos;

	lst = NULL;
	pos = 0;
	while (input[pos])
	{
		token = get_token(input, pos);
		if (!token)
			return (NULL);
		new_lst = ft_lstnew(token);
		if (!new_lst)
			return (NULL);
		ft_lstadd_back(&lst, new_lst);
		pos += (token->end_pos - token->start_pos);
	}
	size = ft_lstsize(lst);
	tokens = (t_token **)malloc(sizeof(t_token *) * (size + 1));
	if (!tokens)
		return (NULL);
	size = 0;
	while (lst)
	{
		temp = lst;
		tokens[size] = lst->content;
		lst = lst->next;
		free(temp);
		size++;
	}
	tokens[size] = NULL;
	return (tokens);
}

static t_token	*get_token(const char *input, int pos)
{
	t_token	*token;
	t_token	*temp_token;
	size_t	i;

	t_token *(*ms_tokenize_func_list[13])(const char *,
			int) = {ms_tokenize_word, ms_tokenize_identify,
		ms_tokenize_right_parenthesis, ms_tokenize_left_parenthesis,
		ms_tokenize_newline, ms_tokenize_equal, ms_tokenize_double_quote,
		ms_tokenize_single_quote, ms_tokenize_redirection, ms_tokenize_blank,
		ms_tokenize_pipe, ms_tokenize_list, ms_tokenize_variable};
	i = 0;
	token = NULL;
	temp_token = NULL;
	while (i < 13)
	{
		temp_token = ms_tokenize_func_list[i](input, pos);
		if (compare_priority(temp_token, token))
		{
			if (token)
				ms_lexical_analyze_destroy_token(token);
			token = temp_token;
		}
		else
			ms_lexical_analyze_destroy_token(temp_token);
		i++;
	}
	return (token);
}

static int	compare_priority(t_token *temp_token, t_token *token)
{
	size_t	temp_token_len;
	size_t	token_len;

	if (temp_token && !token)
		return (1);
	temp_token_len = temp_token->end_pos - temp_token->start_pos;
	token_len = token->end_pos - token->start_pos;
	if ((temp_token->type > 2 && token->type > 2) || (temp_token->type <= 2
			&& token->type <= 2))
	{
		if (temp_token_len >= token_len)
			return (1);
		else
			return (0);
	}
	if (temp_token->type > token->type)
		return (1);
	return (0);
}
