#include "lexical_sample.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lx_is_meta(const char *str)
{
	return (
		0
		|| strncmp(str, "|", 1) == 0
		|| strncmp(str, "<", 1) == 0
		|| strncmp(str, ">", 1) == 0
		|| strncmp(str, "<<", 2) == 0
		|| strncmp(str, "<<-", 3) == 0
		|| strncmp(str, ">>", 2) == 0
		|| strncmp(str, "&&", 2) == 0
		|| strncmp(str, "||", 2) == 0
		|| strncmp(str, " ", 1) == 0
		|| strncmp(str, "=", 1) == 0
		|| 0);
}

char *substring(const char *str, int start, size_t len)
{
	return (strndup(&str[start], len));
}

int lx_get_priority(t_token_type type)
{
	if (type == TK_DECLINED)
		return (-1);
	else if (type == TK_WORD)
		return (0);
	else if (type == TK_DELIMITER
		|| type == TK_NUMBER)
		return (1);
	return (-2);
}

/**
 * check higher priority
 * left > right -> 1
 * left < right -> -1
 * left == right
 */
int lx_priority_cmp(t_token *left, t_token *right)
{
	int left_len;
	int right_len;

	if (left == NULL && right == NULL)
		return (0);
	else if (right == NULL)
		return (1);
	else if (left == NULL)
		return (-1);
	if (lx_get_priority(left->type) > lx_get_priority(right->type))
		return (1);
	else if (lx_get_priority(left->type) < lx_get_priority(right->type))
		return (-1);
	left_len = left->end_pos - left->start_pos;
	right_len = right->end_pos - right->start_pos;
	if (left_len > right_len)
		return (1);
	else if (left_len < right_len)
		return (-1);
	return (0);
}
