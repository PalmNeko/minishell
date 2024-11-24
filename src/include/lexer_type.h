#ifndef LEXER_H
# define LEXER_H

typedef enum e_token_type
{
	TK_DECLINED,          // 拒否 (対象のオートマトンでは解析できなかった)
	TK_IDENTIFY,          // 識別子
	TK_WORD,              // ワード
	TK_BLANK,             // 空白文字 '\t '
	TK_NEWLINE,           // 改行文字 '\n'
	TK_VARIABLE,          // 変数
	TK_PIPE,              // '|'
	TK_EQUALS,            // '='
	TK_SINGLE_QUOTE,      // '
	TK_DOUBLE_QUOTE,      // "
	TK_REDIRECTION,       // < << > >>
	TK_LEFT_PARENTHESIS,  // '('
	TK_RIGHT_PARENTHESIS, // ')'
	TK_LIST,              // && ||
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*token;
	int end_pos;   // 入力文字列に対する、トークン外の文字の開始位置
	int start_pos; // 入力文字列に対する、トークンの開始位置
}					t_token;

#endif