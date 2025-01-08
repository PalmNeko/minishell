#ifndef SYNATX_ANALYZE_H
#define SYNATX_ANALYZE_H

#include "syntax_analyze_type.h"
#include "syntax_analyze_config.h"

t_syntax_node *ms_syntax_node_create(t_syntax_type type, int start_pos, int end_pos);
void ms_syntax_node_destroy(t_syntax_node *node);
t_syntax_node *ms_parse_decliend(t_token **tokens, int pos);

t_syntax_node *ms_parse_all(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_blank(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_identify(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_word(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_newline(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_variable(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_list_token(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_pipe(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_equal(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_single_quote(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_double_quote(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_redirection(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_left_parenthesis(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_right_parenthesis(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_double_quoted_word(t_token **tokens, int start_pos);
t_syntax_node *ms_parse_single_quoted_word(t_token **tokens, int start_pos);





#endif // SYNATX_ANALYZE_H