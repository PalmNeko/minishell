/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_print_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:40:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/27 17:40:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libms.h"
#include "libms_internal.h"
#include "export_internal.h"
#include "libft.h"
#include <stdio.h>

static void	ms_sort_environs(char *const envp[]);
static void	ms_print_export_environs(char *const envp[]);
static int	ms_strptrcmp(const char **s1, const char **s2);

int	ms_export_print_command(void)
{
	char	**envptr;

	envptr = ms_export_environs();
	if (envptr == NULL)
		return (1);
	ms_sort_environs(envptr);
	ms_print_export_environs(envptr);
	ms_destroy_ntp(envptr);
	return (0);
}

static void	ms_sort_environs(char *const envp[])
{
	ft_selection_sort((void *)envp, ms_ntpsize((void **)envp), sizeof(char *),
		(int (*)(const void *, const void *))ms_strptrcmp);
}

static void	ms_print_export_environs(char *const envp[])
{
	char		**envitr;
	char		*envvalue;
	char		*envname;

	envitr = (char **)envp;
	while (*envitr != NULL)
	{
		envname = *envitr;
		envvalue = ms_getenv(envname);
		if (envvalue == NULL)
			printf("declare -x %s\n", envname);
		else
			printf("declare -x %s=\"%s\"\n", envname, envvalue);
		envitr++;
	}
	return ;
}

static int	ms_strptrcmp(const char **s1, const char **s2)
{
	return (ft_strcmp(*s1, *s2));
}
