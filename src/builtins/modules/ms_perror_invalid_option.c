/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror_invalid_option.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 06:15:50 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/11 07:37:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libms.h"

/**
 * format: "minishell: %s: -%c: invalid option\n", cmd, opt
 */
void	ms_perror_invalid_option(const char *cmd, char opt)
{
	char	opt_txt[3];

	ft_strlcpy(opt_txt, "-@", 3);
	opt_txt[1] = opt;
	ms_perror_cmd2(cmd, opt_txt, "invalid option");
}
