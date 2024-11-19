#include "lexical_sample.h"
#include <stdlib.h>
#include <stdio.h>

t_token *lx_run_automaton(const char *str, int pos);

int lexical_analyze(char *str)
{
	t_token *token;
	int pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		token = lx_run_automaton(str, pos);
		if (token == NULL)
			return (1);
		if (token->type == TK_DECLINED)
		{
			printf("%s\n", str);
			printf("%*c%s\n", pos + 1, '^', " unexpected token");
			return (1);
		}
		else // 実際にはここでリストにトークンを追加する
			lx_print_token(token);
		pos = token->end_pos;
		lx_destroy_token(token);
	}
	return (0);
}

/**
 * オートマトンを実行し、優先度に応じてトークンを返す
 */
t_token *lx_run_automaton(const char *str, int pos)
{
	const lx_finite_automaton	automatons[] = {
		lx_automaton_delimiter, lx_automaton_number, lx_automaton_word, NULL};
	int 						no;
	t_token						*token;
	t_token						*result_token;

	no = 0;
	result_token = NULL;
	while (automatons[no] != NULL)
	{
		token = automatons[no](str, pos);
		if (token == NULL)
			return (NULL);
		if (lx_priority_cmp(token, result_token) > 0)
		{
			lx_destroy_token(result_token);
			result_token = token;
		}
		no++;
	}
	return (result_token);
}
