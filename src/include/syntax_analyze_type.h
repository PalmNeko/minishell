#ifndef SYNATX_ANALYZE_TYPE_H
# define SYNATX_ANALYZE_TYPE_H

#include "lexer.h"

typedef enum e_syntax_type
{
	SY_DECLINED,
	SY_IDENTIFY,
	SY_WORD,
	SY_BLANK,
	SY_NEWLINE,
	SY_VARIABLE,
	SY_LIST_TOKEN,
	SY_PIPE,
	SY_EQUALS,
	SY_SINGLE_QUOTE,
	SY_DOUBLE_QUOTE,
	SY_REDIRECTION,
	SY_LEFT_PARENTHESIS,
	SY_RIGHT_PARENTHESIS,
	SY_ALL,

	SY_DOUBLE_QUOTE_WORD,
	SY_SINGLE_QUOTE_WORD,
	SY_WORD_LIST,
	SY_ASSIGNMENT_WORD,
	SY_REDIRECTION_WORD,
	SY_SIMPLE_COMMAND,
	SY_PIPELINE,
	SY_LIST,
	SY_COMPOUND_LIST,
	SY_USER_INPUT,
	SY_INSTRUCTION,
}						t_syntax_type;

typedef struct s_syntax_node	t_syntax_node;

typedef struct s_syntax_node
{
	t_syntax_type		type;
	t_token				*token;
	t_syntax_node		**children;
	int start_pos;
	int end_pos;
}						t_syntax_node;

#endif // SYNATX_ANALYZE_TYPE_H