
#ifndef LEXICAL_SAMPLE_H
# define LEXICAL_SAMPLE_H

# include <stddef.h>

typedef enum e_token_type {
	TK_DECLINED, // 拒否 (対象のオートマトンでは解析できなかった)
	TK_WORD, // ワード
	TK_DELIMITER, // 区切り文字 '\t\n '
	TK_NUMBER, // FD
}	t_token_type;

typedef struct s_token {
	t_token_type type;
	char	*token;
	int		end_pos; // 入力文字列に対する、トークン外の文字の開始位置
	int		start_pos; // 入力文字列に対する、トークンの開始位置
	void *opt; // メモリに割り当てられた任意の情報
	void (*free_opt)(void *); // optの解放
	void (*print_opt)(void *); // optの出力関数
}	t_token;

typedef t_token *(*lx_finite_automaton)(const char *str, int pos);

int lexical_analyze(char *str);

t_token *lx_automaton_delimiter(const char *str, int pos);
t_token *lx_automaton_word(const char *str, int pos);
t_token *lx_automaton_number(const char *str, int pos);
void	lx_print_number_token(int *value);

int 	lx_is_meta(const char *str);
char 	*substring(const char *str, int start, size_t len);
int		lx_priority_cmp(t_token *left, t_token *right);

t_token *lx_create_token(t_token_type type, const char *token);
t_token *lx_generate_token(t_token_type type, const char *str, int start, int end);
t_token *lx_generate_declined(const char *str, int start);
void 	lx_destroy_token(t_token *token);
int 	lx_print_token(t_token *token);
char	*get_token_str(t_token_type type);

#endif
