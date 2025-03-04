/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:15:08 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 19:15:09 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "lexer_config.h"
# include "lexer_type.h"

t_token	**ms_lexical_analyze(const char *input);

// Tokenize functions
t_token	*ms_create_token(t_token_type type, const char *token, int start_pos,
			int end_pos);
t_token	*ms_copy_token(t_token *token);
void	ms_lexical_analyze_destroy_token(t_token *token);
void	ms_lexical_analyze_destroy_token_wrapper(void *token);
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
