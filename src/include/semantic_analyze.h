#ifndef SEMANTIC_ANALYZE_H
#define SEMANTIC_ANALYZE_H

#include "syntax_analyze_type.h"
#include "semantic_analyze_type.h"

t_lsa *semantic_analyze(t_syntax_node *node);

t_lsa_command *ms_lsa_command(t_syntax_node *command_node);
t_lsa_assignment *ms_lsa_assignment(const t_syntax_node *assignment_word_node);
t_lsa_word_list *ms_lsa_word_list(t_syntax_node *wordlist_node);
t_lsa_redirection *ms_lsa_redirection(const t_syntax_node *redirection_node);
t_lsa_pipeline *ms_lsa_pipeline(t_syntax_node *pipeline_node);
t_lsa_list *ms_lsa_list(t_syntax_node *list_node);
t_lsa_list **ms_lsa_lists(t_syntax_node *lists_node);

#endif