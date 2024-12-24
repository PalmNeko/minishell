#ifndef LEXER_TYPE_H
# define LEXER_TYPE_H

typedef enum e_token_type
{
	TK_DECLINED,          // 拒否 (対象のオートマトンでは解析できなかった)
	TK_WORD,              // ワード
	TK_IDENTIFY,          // 識別子
	TK_RIGHT_PARENTHESIS, // ')'
	TK_LEFT_PARENTHESIS,  // '('
	TK_NEWLINE,           // 改行文字 '\n'
	TK_EQUALS,            // '='
	TK_BLANK,             // 空白文字 '\t '
	TK_LIST,              // && ||
	TK_PIPE,              // '|'
	TK_DOUBLE_QUOTE,      // "
	TK_SINGLE_QUOTE,      // '
	TK_REDIRECTION,       // < << > >>
	TK_VARIABLE,          // 変数
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	const char			*token;
	int					start_pos;
	int					end_pos;
}						t_token;

typedef struct s_list	t_token_list;

#endif