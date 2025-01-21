#ifndef SEMANTIC_ANALYZE_TYPE_H
# define SEMANTIC_ANALYZE_TYPE_H

# include "libft_type.h"
# include "syntax_analyze_type.h"

typedef t_list				t_lsa_list_lst;

typedef enum e_lsa_list_type
{
	LSA_LIST_ALWAYS, // ;
	LSA_LIST_AND,    // &&
	LSA_LIST_OR,     // ||
}							t_lsa_list_type;

typedef enum e_lsa_redirection_type
{
	LSA_RD_INPUT,   // <
	LSA_RD_OUTPUT,  // >
	LSA_RD_APPEND,  // >>
	LSA_RD_HEREDOC, // <<
}							t_lsa_redirection_type;

typedef enum e_lsa_command_type
{
	LSA_CMD_ARGS,
	LSA_CMD_ASSIGNMENTS,
	LSA_CMD_REDIRECTS,
}							t_lsa_command_type;

typedef struct s_lsa_word_list
{
	t_syntax_node *word_list; // SY_WORD_LIST
}							t_lsa_word_list;

typedef t_syntax_node		t_syntax_node_word_list;

typedef struct s_lsa_assignment
{
	t_lsa_word_list *name;  // 変数名
	t_lsa_word_list *value; // 値
}							t_lsa_assignment;

typedef struct s_lsa_redirection
{
	t_lsa_redirection_type	type;
	t_lsa_word_list			*filename;
	t_lsa_word_list			*delimiter;
	t_syntax_node **heredoc_input; // ヒアドクの入力
	bool is_expansion;             // 変数展開するかどうか
}							t_lsa_redirection;

typedef struct s_lsa_command
{
	t_lsa_word_list			**args;
	t_lsa_assignment		**assignments;
	t_lsa_redirection		**redirects;
}							t_lsa_command;

typedef struct s_lsa_pipeline
{
	t_lsa_command			**commands;
}							t_lsa_pipeline;

typedef struct s_lsa_list	t_lsa_list;
typedef struct s_lsa_list
{
	t_lsa_list_type			type;
	// pipelineとcompound_listのどちらかにしか入らない。
	// 片方がNULLならもう片方はnon-NULL。
	t_lsa_pipeline *pipeline;   // パイプライン
	t_lsa_list **compound_list; // NULL終端の配列
}							t_lsa_list;

typedef struct s_lsa
{
	t_lsa_list				**lists;
}							t_lsa;

#endif