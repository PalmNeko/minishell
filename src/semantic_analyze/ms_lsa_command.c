/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lsa_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:13:33 by rnakatan          #+#    #+#             */
/*   Updated: 2025/02/01 09:59:02 by rnakatan         ###   ########.fr       */
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

static t_list *g_lsts[3] = {NULL, NULL, NULL};


static int ms_lsa_command_internal(t_syntax_node *command_node);
static int ms_lsa_command_assignment(t_syntax_node *assignment_node);
static int  ms_lsa_command_simple_command(t_syntax_node *node);
static int _ms_lsa_command_simple_command(t_syntax_node *node);
static int _ms_lsa_command(t_list **lst, t_syntax_node *command_attr_node, void *(*func)(t_syntax_node *));
static t_lsa_command	*ms_lsa_command_set(t_lsa_command *lsa_command);
static t_syntax_node *ms_lsa_command_convert_word_list(t_syntax_node *node);
static t_lsa_command	*ms_create_lsa_command(void);

t_lsa_command	*ms_lsa_command(t_syntax_node *command_node)
{
	t_lsa_command		*lsa_command;

	if(ms_lsa_command_internal(command_node) == -1)
		return (NULL);
	lsa_command = ms_create_lsa_command();
	if (lsa_command == NULL)
		return (NULL);
	lsa_command = ms_lsa_command_set(lsa_command);
	if (lsa_command == NULL)
	{
		ms_lsa_command_destroy(lsa_command);
		return (NULL);
	}
	return (lsa_command);
}

static int ms_lsa_command_internal(t_syntax_node *command_node)
{
	size_t i;
	t_syntax_node *child_node;
	
	i = 0;
	if(command_node->children[0]->type == SY_ASSIGNMENT_COMMAND)
	{
		if(ms_lsa_command_assignment(command_node->children[0]) == -1)
			return (-1);
		i++;
	}
	while (command_node->children[i] != NULL)
	{
		child_node = command_node->children[i];
		if(child_node->type == SY_SIMPLE_COMMAND)
		{
			if(ms_lsa_command_simple_command(child_node) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

static int _ms_lsa_command(t_list **lst, t_syntax_node *command_attr_node, void *(*func)(t_syntax_node *))
{
	void *temp;

	temp = func(command_attr_node);
	if (temp == NULL)
	{
		ft_lstclear(lst, ms_noop_del);
		return (-1);
	}
	ms_lstappend_tail(lst, temp, NULL);
	if (*lst == NULL)
		return (-1);
	return (0);
}

static t_lsa_command *ms_lsa_command_set(t_lsa_command *lsa_command)
{
	if (g_lsts[LSA_CMD_ARGS])
	{
		lsa_command->args = ms_lst_to_ntp(&g_lsts[LSA_CMD_ARGS], ms_identify, ms_noop_del);
		if (lsa_command->args == NULL)
			return (NULL);
	}
	if (g_lsts[LSA_CMD_ASSIGNMENTS])
	{
		lsa_command->assignments = ms_lst_to_ntp(&g_lsts[LSA_CMD_ASSIGNMENTS], ms_identify, ms_noop_del);
		if (lsa_command->assignments == NULL)
			return (NULL);
	}
	if (g_lsts[LSA_CMD_REDIRECTS])
	{
		lsa_command->redirects = ms_lst_to_ntp(&g_lsts[LSA_CMD_REDIRECTS], ms_identify, ms_noop_del);
		if (lsa_command->redirects == NULL)
			return (NULL);
	}
	return (lsa_command);
}

static int ms_lsa_command_assignment(t_syntax_node *assignment_node)
{
	t_syntax_node *child_node;
	size_t i;

	i = 0;
	while (assignment_node->children[i] != NULL)
	{
		child_node = assignment_node->children[i];
		if (child_node->type == SY_ASSIGNMENT_WORD)
		{
			if (_ms_lsa_command(&g_lsts[LSA_CMD_ASSIGNMENTS], child_node, (void *)ms_lsa_assignment) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
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

static int ms_lsa_command_simple_command(t_syntax_node *node)
{
	t_syntax_node *child_node;
	size_t i;
	int res;

	i = 0;
	while (node->children[i] != NULL)
	{
		child_node = node->children[i];
		if (child_node->type == SY_WORD_LIST)
			res = _ms_lsa_command(&g_lsts[LSA_CMD_ARGS], child_node, (void *)ms_lsa_word_list);
		else if (child_node->type == SY_REDIRECTION_WORD)
			res = _ms_lsa_command(&g_lsts[LSA_CMD_REDIRECTS], child_node, (void *)ms_lsa_redirection);
		else if(child_node->type == SY_ASSIGNMENT_WORD)
			res = _ms_lsa_command_simple_command(child_node);
		if (res == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int _ms_lsa_command_simple_command(t_syntax_node *node)
{
	t_syntax_node *child_node;
	size_t i;

	i = 0;
	while (node->children[i] != NULL)
	{
		child_node = node->children[i];
		if(child_node->type == SY_EQUALS)
		{
			child_node = ms_lsa_command_convert_word_list(child_node);
			if (child_node == NULL)
				return (-1);
		}
		if(_ms_lsa_command(g_lsts, child_node, (void *)ms_lsa_word_list) == -1)
			return (-1);
		i++;
	}
	return (0);
}

static t_syntax_node *ms_lsa_command_convert_word_list(t_syntax_node *node)
{
	t_syntax_node *new_node;

	new_node = ms_syntax_node_create(SY_WORD_LIST);
	if (new_node == NULL)
		return (NULL);
	new_node->start_pos = node->start_pos;
	new_node->end_pos = node->end_pos;
	new_node->children = (t_syntax_node **)malloc(sizeof(t_syntax_node *) * 2);
	if (new_node->children == NULL)
		return (NULL);
	new_node->children[0] = node;
	new_node->children[1] = NULL;
	node = new_node;
	return (node);
}
