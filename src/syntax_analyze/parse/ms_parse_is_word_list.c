#include "lexer.h"

int ms_parse_is_word_list(t_token_type type)
{
	return((type == TK_WORD || type == TK_SINGLE_QUOTE || type == TK_DOUBLE_QUOTE || type == TK_VARIABLE || type == TK_IDENTIFY));
}
