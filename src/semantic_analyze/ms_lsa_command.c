/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:33 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/02 19:26:19 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "semantic_analyze.h"
#include "semantic_analyze_internal.h"
#include "syntax_analyze.h"
#include <stddef.h>
#include <stdlib.h>

// /* t_lsa_command構造体
//  *
//  * args:        引数のリスト
//  * assignments: 代入のリスト
//  * redirects:   リダイレクトのリスト
//  *
//  * 例:
//  *   echo hello > file
//  *   args:        ["echo", "hello"]
//  *   assignments: []
//  *   redirects:   ["> file"]
//  *
//  *   PATH=$PATH:/usr/bin ls -l
//  *   args:        ["ls", "-l"]
//  *   assignments: ["PATH=$PATH:/usr/bin"]
//
typedef void				*(*t_lsa_command_func)(t_syntax_node *node);
typedef void				(*t_lsa_destroy_func)(void *node);

static t_list				*g_lsts[3] = {NULL, NULL, NULL};
static t_lsa_command_func	g_lsa_command_funcs[3] = {(void *)ms_lsa_word_list,
		(void *)ms_lsa_assignment, (void *)ms_lsa_redirection};
static t_lsa_destroy_func	g_lsa_destroy_funcs[3] = {(void *)ms_lsa_wordlist_destroy,
		(void *)ms_lsa_assignment_destroy, (void *)ms_lsa_redirection_destroy};

static int					ms_lsa_command_internal(t_syntax_node *command_node);
static int					_ms_lsa_command_internal(t_syntax_node *command_attr_node);
static int					ms_lsa_command_set(t_lsa_command *lsa_command);
static t_lsa_command		*ms_create_lsa_command(void);

t_lsa_command	*ms_lsa_command(t_syntax_node *command_node)
{
	t_lsa_command	*lsa_command;
	int				i;

	i = 0;
	while (command_node->children[i] != NULL)
	{
		if (ms_lsa_command_internal(command_node->children[i]) == -1)
			return (NULL);
		i++;
	}
	lsa_command = ms_create_lsa_command();
	if (lsa_command == NULL || ms_lsa_command_set(lsa_command) == -1)
		return (NULL);
	return (lsa_command);
}

static int	ms_lsa_command_internal(t_syntax_node *command_node)
{
	t_syntax_node	*child_node;
	int				i;

	i = 0;
	if (command_node->type == SY_ASSIGNMENT_COMMAND)
	{
		while (command_node->children[i] != NULL)
		{
			child_node = command_node->children[i];
			if (_ms_lsa_command_internal(child_node) == -1)
				return (-1);
			i++;
		}
	}
	else
	{
		while (command_node->children[i] != NULL)
		{
			child_node = command_node->children[i];
			if (_ms_lsa_command_internal(child_node) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

static int	_ms_lsa_command_internal(t_syntax_node *command_attr_node)
{
	void				*temp;
	t_lsa_command_type	type;

	temp = NULL;
	if (command_attr_node->type == SY_ASSIGNMENT_WORD)
		type = LSA_CMD_ASSIGNMENTS;
	else if (command_attr_node->type == SY_WORD_LIST)
		type = LSA_CMD_ARGS;
	else if (command_attr_node->type == SY_REDIRECTION_WORD)
		type = LSA_CMD_REDIRECTS;
	temp = g_lsa_command_funcs[type](command_attr_node);
	if (temp == NULL)
	{
		ft_lstclear(&g_lsts[type], g_lsa_destroy_funcs[type]);
		return (-1);
	}
	ms_lstappend_tail(&g_lsts[type], temp, g_lsa_destroy_funcs[type]);
	if (g_lsts[type] == NULL)
		return (-1);
	return (0);
}

static int	ms_lsa_command_set(t_lsa_command *lsa_command)
{
	int	ret;

	ret = 0;
	if (g_lsts[LSA_CMD_ARGS])
	{
		lsa_command->args = ms_lst_to_ntp(&g_lsts[LSA_CMD_ARGS], ms_identify,
				ms_noop_del);
		if (lsa_command->args == NULL)
			ret = -1;
	}
	if (g_lsts[LSA_CMD_ASSIGNMENTS])
	{
		lsa_command->assignments = ms_lst_to_ntp(&g_lsts[LSA_CMD_ASSIGNMENTS],
				ms_identify, ms_noop_del);
		if (lsa_command->assignments == NULL)
			ret = -1;
	}
	if (g_lsts[LSA_CMD_REDIRECTS])
	{
		lsa_command->redirects = ms_lst_to_ntp(&g_lsts[LSA_CMD_REDIRECTS],
				ms_identify, ms_noop_del);
		if (lsa_command->redirects == NULL)
			ret = -1;
	}
	if (ret == -1)
		ms_lsa_command_destroy(lsa_command);
	return (ret);
}

static t_lsa_command	*ms_create_lsa_command(void)
{
	t_lsa_command	*lsa_command;

	lsa_command = (t_lsa_command *)malloc(sizeof(t_lsa_command));
	if (lsa_command == NULL)
		return (NULL);
	lsa_command->args = NULL;
	lsa_command->assignments = NULL;
	lsa_command->redirects = NULL;
	return (lsa_command);
}
