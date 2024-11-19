#include "lexical_sample.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

t_token *lx_create_token(
			t_token_type type, const char *token)
{
	t_token *new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->type = type;
	new_token->token = strdup(token);
	if (new_token->token == NULL)
		return (lx_destroy_token(new_token), NULL);
	new_token->start_pos = 0;
	new_token->end_pos = 0;
	new_token->opt = NULL;
	new_token->free_opt = NULL;
	new_token->print_opt = NULL;
	return (new_token);
}

t_token *lx_generate_token(t_token_type type, const char *str, int start, int end)
{
	char 	*token_str;
	t_token *token;

	token_str = substring(str, start, end - start);
	if (token_str == NULL)
		return (NULL);
	token = lx_create_token(type, token_str);
	free(token_str);
	if (token == NULL)
		return (free(token_str), NULL);
	token->start_pos = start;
	token->end_pos = end;
	return (token);
}

t_token *lx_generate_declined(const char *str, int pos)
{
	return (lx_generate_token(TK_DECLINED, str, pos, pos + 1));
}

void lx_destroy_token(t_token *token)
{
	if (token == NULL)
		return ;
	if (token->free_opt != NULL)
		token->free_opt(token->opt);
	free(token->token);
	free(token);
}

int lx_print_token(t_token *token)
{
	printf("t_token {\n");
	printf("\ttype: %s\n", get_token_str(token->type));
	printf("\tpos: %d\n", token->start_pos);
	printf("\tlen: %d\n", token->end_pos - token->start_pos);
	printf("\ttoken: %s\n", token->token);
	if (token->print_opt != NULL)
	{
		printf("\topt: ");
		token->print_opt(token->opt);
		printf("\n");
	}
	printf("}\n");
	return (0);
}

char *get_token_str(t_token_type type)
{

	const t_token_type types[] = {
		TK_DECLINED,
		TK_WORD,
		TK_DELIMITER,
		TK_NUMBER};
	const char *names[] = {
		"TK_DECLINED",
		"TK_WORD",
		"TK_DELIMITER",
		"TK_NUMBER"};
	const size_t	size = sizeof(types) / sizeof(types[0]);
	size_t no;

	no = 0;
	while (no < size)
	{
		if (types[no] == type)
			return ((char *)names[no]);
		no++;
	}
	return (NULL);
}
