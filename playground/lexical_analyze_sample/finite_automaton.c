#include "lexical_sample.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

t_token *lx_automaton_delimiter(const char *str, int pos)
{
	int start = pos;

	while (memchr("\n\t ", str[pos], 3) != NULL)
		pos++;
	if (start == pos)
		return (lx_generate_declined(str, start));
	return (lx_generate_token(TK_DELIMITER, str, start, pos));
}

t_token *lx_automaton_word(const char *str, int pos)
{
	int 	start = pos;

	while (! lx_is_meta(str + pos) && str[pos] != '\0')
		(pos)++;
	if (start == pos)
		return (lx_generate_declined(str, start));
	return (lx_generate_token(TK_WORD, str, start, pos));
}

t_token *lx_automaton_number(const char *str, int pos)
{
	int 	start = pos;
	int 	value = 0;
	int 	*value_ptr;
	int 	num;
	t_token *token;

	while (isdigit(str[pos]) && str[pos] != '\0')
	{
		num = str[pos] - '0';
		if (value > (INT_MAX - num) / 10)
			return (lx_generate_declined(str, start));
		value *= 10;
		value += num;
		pos++;
	}
	if (start == pos)
		return (lx_generate_declined(str, start));
	value_ptr = (int *)malloc(sizeof(int));
	if (value_ptr == NULL)
		return (NULL);
	*value_ptr = value;
	token = lx_generate_token(TK_NUMBER, str, start, pos);
	token->opt = value_ptr;
	token->free_opt = free;
	token->print_opt = (void (*)(void *))lx_print_number_token;
	return (token);
}
