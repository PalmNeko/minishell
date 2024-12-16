#ifndef LEXER_H
# define LEXER_H

# include "lexer_config.h"
# include "lexer_type.h"

t_token	*ms_create_token(t_token_type type, const char *token, int start_pos,
			int end_pos);
void	ms_lexical_analyze_destroy_token(t_token *token);

t_token	*ms_tokenize_identify(const char *input, int pos);
t_token	*ms_tokenize_right_parenthesis(const char *input, int pos);
t_token	*ms_tokenize_left_parenthesis(const char *input, int pos);
t_token	*ms_tokenize_newline(const char *input, int pos);
t_token	*ms_tokenize_equal(const char *input, int pos);
t_token	*ms_tokenize_double_quote(const char *input, int pos);
t_token	*ms_tokenize_single_quote(const char *input, int pos);
t_token	*ms_tokenize_redirection(const char *input, int pos);
t_token	*ms_tokenize_blank(const char *input, int pos);
t_token	*ms_tokenize_pipe(const char *input, int pos);

#endif