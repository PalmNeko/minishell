/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ms_destroy_token_wrapper.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:28:01 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 20:37:26 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze.h"

void	ms_destroy_token_wrapper(void *token)
{
	ms_destroy_token((t_token *)token);
}
