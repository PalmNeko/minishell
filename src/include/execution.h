#ifndef EXECUTION_H
#define EXECUTION_H

#include "semantic_analyze_type.h"
#include "execution_type.h"

int ms_isbuiltin(char *command);
int ms_execution(const char *input);
int ms_execute_from_lsa(t_lsa *lsa);
int ms_execute_lists(t_lsa_list **lists);
int ms_execute_list(t_lsa_list *list);
int ms_execute_pipeline(t_lsa_pipeline *pipeline);
int ms_execute_command(char **args);
int ms_simple_command_execution(t_lsa_command *lsa_command);
char **ms_expand_commands(t_lsa_word_list **args);
char **ms_expansion(t_lsa_word_list *lsa_word_list);

#endif