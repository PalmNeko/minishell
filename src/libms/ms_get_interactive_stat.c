/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_interactive_stat.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:39:40 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/02 08:42:38 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
/**
 * TODO: 仮の関数として作ってます。０を返したらインタラクティブ。
 */
int	ms_get_interactive_stat(void)
{
	return (!(isatty(STDIN_FILENO) && isatty(STDERR_FILENO)));
}
