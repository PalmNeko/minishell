/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 20:38:50 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 21:09:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HELPER_H
# define PARSE_HELPER_H

# include "parse_helper_type.h"
# include "syntax_analyze_type.h"

int	ms_parse_ebnf_repeat_method(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_parse_func *parsers);
int	ms_parse_ebnf_option(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_parse_func *parsers);
int	ms_parse_ebnf_one_method(
		t_token **tokens,
		int pos,
		t_list **syntax_lst,
		t_parse_func *parsers);
int	ms_lst_append_node(t_list **lst, t_syntax_node *node);

#endif
