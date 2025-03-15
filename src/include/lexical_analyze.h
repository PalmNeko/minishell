/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyze.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:15:08 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 21:25:09 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZE_H
# define LEXICAL_ANALYZE_H

# include "lexical_analyze_type.h"
# include "lexical_analyze_config.h"

t_token	**ms_lexical_analyze(const char *input);

// Tokenize functions
t_token	*ms_create_token(t_token_type type, const char *token, int start_pos,
			int end_pos);

t_token	*ms_duplicate_token(t_token *token);

void	ms_destroy_token(t_token *token);
void	ms_destroy_token_wrapper(void *token);
t_token	*ms_tokenize_identify(const char *input, int pos);
t_token	*ms_tokenize_right_parenthesis(const char *input, int pos);
t_token	*ms_tokenize_left_parenthesis(const char *input, int pos);
t_token	*ms_tokenize_newline(const char *input, int pos);
t_token	*ms_tokenize_equal(const char *input, int pos);
t_token	*ms_tokenize_double_quote(const char *input, int pos);
t_token	*ms_tokenize_single_quote(const char *input, int pos);
t_token	*ms_tokenize_redirection(const char *input, int pos);
t_token	*ms_tokenize_blank(const char *input, int pos);
t_token	*ms_tokenize_pipe(const char *input, int pos);
t_token	*ms_tokenize_list(const char *input, int pos);
t_token	*ms_tokenize_variable(const char *input, int pos);
t_token	*ms_tokenize_word(const char *input, int pos);

#endif
