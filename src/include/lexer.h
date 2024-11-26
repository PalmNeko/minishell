#ifndef LEXER_H
# define LEXER_H

# include "lexer_config.h"
# include "lexer_type.h"

t_token	*ms_create_token(t_token_type type, const char *token, int start_pos,
			int end_pos);
void	ms_lexical_analyze_destroy_token(t_token *token);
#endif