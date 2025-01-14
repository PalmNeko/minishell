/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:48:06 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/09 17:48:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "setup_type.h"
# include "input_type.h"

void	ms_input(t_minishell mnsh);
void	ms_init_heredoc(t_heredoc *heredoc);
void	ms_finalize_heredoc(t_heredoc *heredoc);
int		ms_set_delimita_list(t_heredoc *heredoc, char *input);
char	*ms_read_with_delimita(char *delimita);
char	*ms_append_with_newline(char **input, const char *input_line);
char	*ms_input_heredoc(t_minishell mnsh, char *input);

#endif
