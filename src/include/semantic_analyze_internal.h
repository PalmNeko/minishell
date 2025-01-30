#ifndef SEMANTIC_ANALYZE_INTERNAL_H
# define SEMANTIC_ANALYZE_INTERNAL_H

#include "semantic_analyze_type.h"

void ms_lsa_list_destroy(t_lsa_list *list);
void ms_lsa_pipeline_destroy(t_lsa_pipeline *pipeline);
void ms_lsa_redirection_destroy(t_lsa_redirection *redirection);
void ms_lsa_command_destroy(t_lsa_command *command);
void ms_lsa_wordlist_destroy(t_lsa_word_list *wordlist);
void ms_lsa_assignment_destroy(t_lsa_assignment *assignment);

#endif