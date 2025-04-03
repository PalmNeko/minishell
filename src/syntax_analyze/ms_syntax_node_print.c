/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax_node_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:52:26 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/03 08:40:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "syntax_analyze.h"
#include <stdio.h>

static void	**g_list[] = {
	(void *[]){
	(t_syntax_type[]){SY_DECLINED},
	"SY_DECLINED",
	"\x1b[32;4m"},
	(void *[]){
	(t_syntax_type[]){SY_IDENTIFY},
	"SY_IDENTIFY",
	"\x1b[33;4m"},
	(void *[]){
	(t_syntax_type[]){SY_WORD},
	"SY_WORD",
	"\x1b[34;4m"},
	(void *[]){
	(t_syntax_type[]){SY_BLANK},
	"SY_BLANK",
	"\x1b[35;4m"},
	(void *[]){
	(t_syntax_type[]){SY_NEWLINE},
	"SY_NEWLINE",
	"\x1b[36;4m"},
	(void *[]){
	(t_syntax_type[]){SY_VARIABLE},
	"SY_VARIABLE",
	"\x1b[37;4m"},
	(void *[]){
	(t_syntax_type[]){SY_LIST_TOKEN},
	"SY_LIST_TOKEN",
	"\x1b[91;4m"},
	(void *[]){
	(t_syntax_type[]){SY_PIPE},
	"SY_PIPE",
	"\x1b[92;4m"},
	(void *[]){
	(t_syntax_type[]){SY_EQUALS},
	"SY_EQUALS",
	"\x1b[93;4m"},
	(void *[]){
	(t_syntax_type[]){SY_SINGLE_QUOTE},
	"SY_SINGLE_QUOTE",
	"\x1b[94;4m"},
	(void *[]){
	(t_syntax_type[]){SY_DOUBLE_QUOTE},
	"SY_DOUBLE_QUOTE",
	"\x1b[95;4m"},
	(void *[]){
	(t_syntax_type[]){SY_REDIRECTION},
	"SY_REDIRECTION",
	"\x1b[96;4m"},
	(void *[]){
	(t_syntax_type[]){SY_LEFT_PARENTHESIS},
	"SY_LEFT_PARENTHESIS",
	"\x1b[97;4m"},
	(void *[]){
	(t_syntax_type[]){SY_RIGHT_PARENTHESIS},
	"SY_RIGHT_PARENTHESIS",
	"\x1b[31;4m"},
	(void *[]){
	(t_syntax_type[]){SY_NULL_WORD},
	"SY_NULL_WORD",
	"\x1b[31;4m"},
	(void *[]){
	(t_syntax_type[]){SY_ALL},
	"SY_ALL",
	"\x1b[32;4m"},
	(void *[]){
	(t_syntax_type[]){SY_DOUBLE_QUOTED_WORD},
	"SY_DOUBLE_QUOTED_WORD",
	"\x1b[33m"},
	(void *[]){
	(t_syntax_type[]){SY_SINGLE_QUOTED_WORD},
	"SY_SINGLE_QUOTED_WORD",
	"\x1b[34m"},
	(void *[]){
	(t_syntax_type[]){SY_WORD_LIST},
	"SY_WORD_LIST",
	"\x1b[35m"},
	(void *[]){
	(t_syntax_type[]){SY_ASSIGNMENT_WORD},
	"SY_ASSIGNMENT_WORD",
	"\x1b[36m"},
	(void *[]){
	(t_syntax_type[]){SY_REDIRECTION_WORD},
	"SY_REDIRECTION_WORD",
	"\x1b[37m"},
	(void *[]){
	(t_syntax_type[]){SY_SIMPLE_COMMAND},
	"SY_SIMPLE_COMMAND",
	"\x1b[91m"},
	(void *[]){
	(t_syntax_type[]){SY_ASSIGNMENT_COMMAND},
	"SY_ASSIGNMENT_COMMAND",
	"\x1b[92m"},
	(void *[]){
	(t_syntax_type[]){SY_COMMAND},
	"SY_COMMAND",
	"\x1b[93m"},
	(void *[]){
	(t_syntax_type[]){SY_PIPELINE},
	"SY_PIPELINE",
	"\x1b[94m"},
	(void *[]){
	(t_syntax_type[]){SY_LIST},
	"SY_LIST",
	"\x1b[95m"},
	(void *[]){
	(t_syntax_type[]){SY_COMPOUND_LIST},
	"SY_COMPOUND_LIST",
	"\x1b[96m"},
	(void *[]){
	(t_syntax_type[]){SY_USER_INPUT},
	"SY_USER_INPUT",
	"\x1b[97m"},
	(void *[]){
	(t_syntax_type[]){SY_INSTRUCTION},
	"SY_INSTRUCTION",
	"\x1b[31m"},
	NULL
};

static void	ms_print_indent(int depth);
static char	*ms_syntax_node_type_to_string(t_syntax_type type);
static char	*ms_syntax_node_type_to_color(t_syntax_type type);
static void	ms_print_token(const char *token);

void	ms_syntax_node_print(t_syntax_node *node)
{
	static int	depth = 0;
	size_t		i;

	if (node == NULL)
		return ;
	ms_print_indent(depth);
	printf("%s%s\x1b[0m", ms_syntax_node_type_to_color(node->type),
		ms_syntax_node_type_to_string(node->type));
	if (node->token != NULL)
	{
		printf(" -> '");
		ms_print_token(node->token->token);
		printf("`");
	}
	printf("\n");
	if (node->children == NULL)
		return ;
	i = 0;
	while (node->children[i] != NULL)
	{
		depth++;
		ms_syntax_node_print(node->children[i]);
		depth--;
		i++;
	}
}

static void	ms_print_indent(int depth)
{
	printf("%*s", depth * 2, "");
}

static void	ms_print_token(const char *token)
{
	while (*token != '\0')
	{
		if (*token == '\n')
			printf("\\n");
		else if (*token == '\t')
			printf("\\t");
		else if (*token == '\r')
			printf("\\r");
		else if (*token == '\v')
			printf("\\v");
		else if (*token == '\f')
			printf("\\f");
		else if (*token == '\b')
			printf("\\b");
		else if (*token == '\a')
			printf("\\a");
		else if (*token == '\0')
			printf("\\0");
		else
			printf("%c", *token);
		token++;
	}
}

static char	*ms_syntax_node_type_to_string(t_syntax_type type)
{
	size_t	i;

	i = 0;
	while (g_list[i] != NULL)
	{
		if (((t_syntax_type *)g_list[i][0])[0] == type)
			return ((char *)g_list[i][1]);
		i++;
	}
	return ("UNKNOWN_TYPE");
}

static char	*ms_syntax_node_type_to_color(t_syntax_type type)
{
	size_t	i;

	i = 0;
	while (g_list[i] != NULL)
	{
		if (((t_syntax_type *)g_list[i][0])[0] == type)
			return ((char *)g_list[i][2]);
		i++;
	}
	return ("\x1b[0m");
}
