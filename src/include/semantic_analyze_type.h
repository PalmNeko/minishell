/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic_analyze_type.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:12:28 by nyts              #+#    #+#             */
/*   Updated: 2025/03/08 19:33:38 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTIC_ANALYZE_TYPE_H
# define SEMANTIC_ANALYZE_TYPE_H

# include "libft_type.h"
# include "syntax_analyze_type.h"

typedef t_list				t_lsa_list_lst;

typedef enum e_lsa_list_type
{
	LSA_LIST_ALWAYS,
	LSA_LIST_AND,
	LSA_LIST_OR,
}							t_lsa_list_type;

typedef enum e_lsa_redirection_type
{
	LSA_RD_INPUT,
	LSA_RD_OUTPUT,
	LSA_RD_APPEND,
	LSA_RD_HEREDOC,
}							t_lsa_redirection_type;

typedef enum e_lsa_command_type
{
	LSA_CMD_ARGS,
	LSA_CMD_ASSIGNMENTS,
	LSA_CMD_REDIRECTS,
}							t_lsa_command_type;

typedef struct s_lsa_word_list
{
	t_syntax_node			*word_list;
}							t_lsa_word_list;

typedef t_syntax_node		t_syntax_node_word_list;

typedef struct s_lsa_assignment
{
	t_lsa_word_list			*name;
	t_lsa_word_list			*value;
}							t_lsa_assignment;

typedef struct s_lsa_redirection
{
	t_lsa_redirection_type	type;
	t_lsa_word_list			*filename;
	t_lsa_word_list			*delimiter;
	t_syntax_node			**heredoc_input;
	bool					is_expansion;
}							t_lsa_redirection;

typedef struct s_lsa_command
{
	t_lsa_word_list			**args;
	t_lsa_assignment		**assignments;
	t_lsa_redirection		**redirects;
}							t_lsa_command;

typedef struct s_lsa_pipeline
{
	t_lsa_command			**commands;
}							t_lsa_pipeline;

typedef struct s_lsa_list	t_lsa_list;
typedef struct s_lsa_list
{
	t_lsa_list_type			type;
	t_lsa_pipeline			*pipeline;
	t_lsa_list				**compound_list;
}							t_lsa_list;

typedef struct s_lsa
{
	t_lsa_list				**lists;
}							t_lsa;

typedef void				*(*t_lsa_command_func)(t_syntax_node *node);
typedef void				(*t_lsa_destroy_func)(void *node);

#endif
