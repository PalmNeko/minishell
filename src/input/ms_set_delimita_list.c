/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_delimita_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:07:06 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/11 00:07:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "input.h"
#include <stdlib.h>

char	*ms_dup_until_sep(char *input, const char *sep_set);
void	ms_exclude_quote(char *input);
char	*ms_dup_delimita(char *input);
void	ms_skip_set(char **input, const char *set);
void	ms_skip_surround_quote(char **input);
void	ms_skip_until_heredoc(char **input);
void	ms_skip_delimita(char **input);
int		ms_append_delim(t_heredoc *heredoc, char *input);

int	ms_set_delimita_list(t_heredoc *heredoc, char *input)
{
	size_t	heredoc_sign_length;

	heredoc_sign_length = ft_strlen("<<");
	while (*input != '\0')
	{
		ms_skip_until_heredoc(&input);
		if (*input == '\0')
			break ;
		input += heredoc_sign_length;
		if (ms_append_delim(heredoc, input) != 0)
			return (-1);
	}
	return (0);
}

int	ms_append_delim(t_heredoc *heredoc, char *input)
{
	t_list	*new_lst;
	char	*delimita;

	ms_skip_set(&input, " \t\n");
	delimita = ms_dup_delimita(input);
	if (delimita == NULL)
		return (-1);
	if (delimita[0] == '\0')
		return (free(delimita), 0);
	new_lst = ft_lstnew(delimita);
	if (new_lst == NULL)
	{
		free(delimita);
		return (-1);
	}
	ft_lstadd_back(&heredoc->delimita_list, new_lst);
	heredoc->delimita_count++;
	return (0);
}

void	ms_skip_delimita(char **input)
{
	ms_skip_set(input, " \t\n");
	while (!ft_includes(**input, " \t\n"))
		(*input)++;
	ms_skip_set(input, " \t\n");
}

void	ms_skip_until_heredoc(char **input)
{
	while (**input != '\0')
	{
		if (ft_includes (**input, "'\""))
		{
			ms_skip_surround_quote(input);
			continue ;
		}
		if (ft_strncmp(*input, "<<", 2) == 0)
			return ;
		(*input)++;
	}
}

void	ms_skip_surround_quote(char **input)
{
	char	quote_txt[2];
	char	*ptr;

	ptr = *input;
	if (!ft_includes(*ptr, "'\""))
		return ;
	quote_txt[1] = '\0';
	quote_txt[0] = *ptr;
	ptr++;
	while (*ptr != '\0' && ! ft_includes(*ptr, quote_txt))
		ptr++;
	if (*ptr == '\0')
		return ;
	ptr++;
	*input = ptr;
}

void	ms_skip_set(char **input, const char *set)
{
	while (ft_includes(**input, (char *)set))
		(*input)++;
}

char	*ms_dup_delimita(char *input)
{
	char	*dup;
	char	*end;

	end = input;
	while (*end != '\0')
	{
		if (ft_includes(*end, "\"'"))
			ms_skip_surround_quote(&end);
		if (ft_includes(*end, " \t\n<&|()"))
			break ;
		if (*end == '\0')
			break ;
		end++;
	}
	dup = ft_strndup(input, end - input);
	if (dup == NULL)
		return (NULL);
	ms_exclude_quote(dup);
	return (dup);
}

void	ms_exclude_quote(char *input)
{
	size_t	set_pos;
	size_t	pivot;
	char	quote_txt;

	set_pos = 0;
	pivot = 0;
	quote_txt = '\0';
	while (input[pivot] != '\0')
	{
		if (quote_txt != '\0' && input[pivot] == quote_txt)
		{
			quote_txt = '\0';
			pivot++;
			continue ;
		}
		else if (quote_txt == '\0' && ft_includes(input[pivot], "'\""))
		{
			quote_txt = input[pivot];
			pivot++;
			continue ;
		}
		input[set_pos] = input[pivot];
		set_pos++;
		pivot++;
	}
	input[set_pos] = '\0';
}

char	*ms_dup_until_sep(char *input, const char *sep_set)
{
	size_t	len;

	len = 0;
	while (input[len] != '\0' && !ft_includes(input[len], (char *)sep_set))
		len++;
	return (ft_strndup(input, len));
}
