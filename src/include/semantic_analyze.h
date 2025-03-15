/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semantic_analyze.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:13:45 by nyts              #+#    #+#             */
/*   Updated: 2025/03/15 18:18:55 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEMANTIC_ANALYZE_H
# define SEMANTIC_ANALYZE_H

# include "semantic_analyze_type.h"
# include "syntax_analyze_type.h"

t_lsa				*semantic_analyze(t_syntax_node *node);
void				ms_lsa_destroy(t_lsa *lsa);

t_lsa_command		*ms_lsa_command(t_syntax_node *command_node);
t_lsa_assignment	*ms_lsa_assignment(t_syntax_node *assignment_word_node);
t_lsa_word_list		*ms_lsa_word_list(t_syntax_node *wordlist_node);
t_lsa_redirection	*ms_lsa_redirection(t_syntax_node *redirection_node);
t_lsa_pipeline		*ms_lsa_pipeline(t_syntax_node *pipeline_node);
t_lsa_list			*ms_lsa_list(t_syntax_node *list_node);
t_lsa_list			**ms_lsa_lists(t_syntax_node *lists_node);

int					ms_set_readnodestream(t_syntax_node *node);
void				ms_unset_readnodestream(void);
t_syntax_node		*ms_read_node(void);
t_list				*ms_get_next_line_node(void);
char				*ms_word_list_to_delimiter_string(
						t_lsa_word_list *word_list);
int					ms_lsa_set_heredoc(t_lsa_redirection *lsa_redirection,
						t_syntax_node *delimiter_node);
bool				ms_compare_heredoc_input(const char *input,
						const char *delimiter);

#endif
