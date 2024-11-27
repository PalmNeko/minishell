/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:22:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/24 21:22:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMS_H
# define LIBMS_H

# include <stddef.h>

/**
 * libms
 */
char	*ms_join_ntp(const char *ntp[], const char *pad);
char	**ms_dup_ntp(const char *ntp[]);
char	**ms_dup_ntp2(const char *const ntp[]);
void	ms_destroy_ntp(char *ntp[]);

// environment variable
char	*ms_getenv(const char *name);
int		ms_setenv(const char *name, const char *value, int overwrite);
int		ms_unsetenv(const char *name);
int		ms_import_env(char *const envp[]);
char	**ms_export_env(void);

#endif
