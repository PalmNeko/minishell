#include "semantic_analyze.h"
#include "libms.h"
#include <stdlib.h>
#include <stddef.h>


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

static t_lsa_command	*ms_create_lsa_command(void);

t_lsa_command	*ms_lsa_command(t_syntax_node *command_node)
{
	t_lsa_command *lsa_command;
	t_list *args_lst;
	t_list *assignments_lst;
	t_list *redirects_lst;
	size_t j;
	t_lsa_word_list *temp_word_list;
	t_lsa_redirection *temp_redirection;
	t_lsa_assignment *temp_assignment;
	
	args_lst = NULL;
	assignments_lst = NULL;
	redirects_lst = NULL;
	if(command_node->children[0]->type == SY_SIMPLE_COMMAND)
	{
		j = 0;
		while(command_node->children[0]->children[j] != NULL)
		{
			if(command_node->children[0]->children[j]->type == SY_WORD_LIST)
			{
				temp_word_list = ms_lsa_word_list(command_node->children[0]->children[j]);
				if(temp_word_list == NULL)
					return (NULL);
				ms_lstappend_tail(&args_lst, temp_word_list, NULL);
				if(args_lst == NULL)
					return (NULL);		
			}
			else if (command_node->children[0]->children[j]->type == SY_REDIRECTION_WORD)
			{
				temp_redirection = ms_lsa_redirection(command_node->children[0]->children[j]);
				if(temp_redirection == NULL)
					return (NULL);
				ms_lstappend_tail(&redirects_lst, temp_redirection, NULL);
				if(redirects_lst == NULL)
					return (NULL);		
			}
			j++;
		}
	}
	else if (command_node->children[0]->type == SY_ASSIGNMENT_COMMAND)
	{
		j = 0;
		while(command_node->children[0]->children[j] != NULL)
		{
			if(command_node->children[0]->children[j]->type == SY_ASSIGNMENT_WORD)
			{
				temp_assignment = ms_lsa_assignment(command_node->children[0]->children[j]);
				if(temp_assignment == NULL)
					return (NULL);
				ms_lstappend_tail(&assignments_lst, temp_assignment, NULL);
				if(assignments_lst == NULL)
					return (NULL);		
			}		
			j++;
		}		
	}
	lsa_command = ms_create_lsa_command();
	if (lsa_command == NULL)
		return (NULL);
	if(args_lst)
	{
		lsa_command->args = ms_lst_to_ntp(&args_lst, ms_identify, ms_noop_del);
		if (lsa_command->args == NULL)
			return (NULL);
	}
	if(assignments_lst)
	{
		lsa_command->assignments = ms_lst_to_ntp(&assignments_lst, ms_identify, ms_noop_del);
		if (lsa_command->assignments == NULL)
			return (NULL);
	}
	if(redirects_lst)
	{
		lsa_command->redirects = ms_lst_to_ntp(&redirects_lst, ms_identify, ms_noop_del);
		if (lsa_command->redirects == NULL)
			return (NULL);
	}
	return (lsa_command);
}

static t_lsa_command	*ms_create_lsa_command(void)
{
	t_lsa_command *lsa_command;
	
	lsa_command = (t_lsa_command *)malloc(sizeof(t_lsa_command));
	if (lsa_command == NULL)
		return (NULL);
	lsa_command->args = NULL;
	lsa_command->assignments = NULL;
	lsa_command->redirects = NULL;
	return (lsa_command);
}
