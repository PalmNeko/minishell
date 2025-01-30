/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:38:39 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/30 20:06:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "setup.h"
#include <readline/readline.h>
#include <unistd.h>
#include <stdio.h>

char	*ms_readline(const char *prompt)
{
	if (ms_is_interactive())
		return (readline(prompt));
	else
		return (readline(NULL));
}
