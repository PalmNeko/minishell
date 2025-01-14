#ifndef SYNATX_ANALYZE_TYPE_H
# define SYNATX_ANALYZE_TYPE_H

#include "lexer.h"
#include "libft.h"

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

	SY_DOUBLE_QUOTED_WORD,
	SY_SINGLE_QUOTED_WORD,
	SY_WORD_LIST,
	SY_ASSIGNMENT_WORD,
	SY_REDIRECTION_WORD,
	SY_SIMPLE_COMMAND,
	SY_ASSIGNMENT_COMMAND,
	SY_COMMAND,
	SY_PIPELINE,
	SY_LIST,
	SY_COMPOUND_LIST,
	SY_USER_INPUT,
	SY_INSTRUCTION,
}						t_syntax_type;

typedef t_list t_syntax_node_list;

typedef struct s_syntax_node
{
	t_syntax_type		type;
	t_token				*token;
	struct s_syntax_node		**children;
	int start_pos;
	int end_pos;
}						t_syntax_node;

// typedef struct s_syntax_node	t_syntax_node;
typedef t_syntax_node *(*t_parse_func)(t_token **tokens, int pos);

#endif // SYNATX_ANALYZE_TYPE_H