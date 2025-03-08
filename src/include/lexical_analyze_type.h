/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyze_type.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:15:00 by nyts              #+#    #+#             */
/*   Updated: 2025/03/08 19:32:27 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZE_TYPE_H
# define LEXICAL_ANALYZE_TYPE_H

typedef enum e_token_type
{
	TK_DECLINED,
	TK_WORD,
	TK_IDENTIFY,
	TK_RIGHT_PARENTHESIS,
	TK_LEFT_PARENTHESIS,
	TK_NEWLINE,
	TK_EQUALS,
	TK_BLANK,
	TK_LIST,
	TK_PIPE,
	TK_DOUBLE_QUOTE,
	TK_SINGLE_QUOTE,
	TK_REDIRECTION,
	TK_VARIABLE,
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	const char			*token;
	int					start_pos;
	int					end_pos;
}						t_token;

typedef struct s_list	t_token_list;

typedef t_token			*(*t_tokenize_func)(const char *, int);

#endif