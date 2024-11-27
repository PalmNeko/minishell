/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_import_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:31:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/27 15:42:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * import environment variable. this function effect to ms_getenv and ms_setenv
 * functions.
 * this function overwrite environment variable.
 * every element format: name=[value]
 * @param envp import target environment variable.
 * @return
 * 0: if succeed.
 * -1: if occurs an error. and set errno.
 * @exception
 * 	ENOMEM: have no enough memory.
 *  EINVAL: envp is not correct format.
 */
int	ms_import_env(char *const envp[])
{
	(void)envp;
	return (0);
}
