#ifndef MS_TOKENIZE_H
# define MS_TOKENIZE_H

# include "lexer_config.h"
# include "lexer_type.h"
# include <stddef.h>

t_token	*ms_create_token(t_token_type type, const char *token, int start_pos,
			int end_pos);

#endif