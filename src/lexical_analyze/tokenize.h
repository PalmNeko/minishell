#ifndef MS_TOKENIZE_H
# define MS_TOKENIZE_H

# include "lexer_type.h"
# include <stddef.h>

t_token	*ms_tokenize_double_quote(const char *input, int pos);
t_token	*ms_tokenize_single_quote(const char *input, int pos);
t_token	*ms_tokenize_pipe(const char *input, int pos);
t_token	*ms_tokenize_redirection(const char *input, int pos);
t_token	*ms_tokenize_list(const char *input, int pos);
t_token	*ms_tokenize_variable(const char *input, int pos);
t_token	*ms_tokenize_word(const char *input, int pos);
t_token	*ms_tokenize_blank(const char *input, int pos);
t_token	*ms_tokenize_newline(const char *input, int pos);
t_token	*ms_tokenize_left_parenthesis(const char *input, int pos);
t_token	*ms_tokenize_right_parenthesis(const char *input, int pos);
t_token	*ms_tokenize_equals(const char *input, int pos);

#endif