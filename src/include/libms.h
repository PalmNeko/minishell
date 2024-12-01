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

# include "libft_type.h"
# include <stddef.h>

/** string.h */
char	*ms_strpbrk(const char *s, const char *accept);

/** unistd.h */
char	*ms_get_current_dir_name(void);

/**
 * libms
 */
char	*ms_join_ntp(const char *ntp[], const char *pad);
char	**ms_dup_ntp(const char *ntp[]);
char	**ms_dup_ntp2(const char *const ntp[]);
char	**ms_dup_ntp3(char *ntp[]);
char	**ms_dup_ntp4(char *const ntp[]);
void	ms_destroy_ntp(char *ntp[]);
void	ms_destroy_ntp2(void **ntp, void (*fr)(void *));
void	*ms_lst_to_ntp(t_list **lst, void *(*cp)(void *), void (*fr)(void *));
size_t	ms_ntpsize(void **ntp);
int		ms_get_interactive_stat(void);

// environment variable
char	*ms_getenv(const char *name);
int		ms_setenv(const char *name, const char *value, int overwrite);
int		ms_unsetenv(const char *name);
int		ms_import_env(char *const envp[]);
char	**ms_export_env(void);
void	ms_clear_environ(void *unused);

// errors
void	ms_perror_shell(const char *msg);
void	ms_perror_cmd(const char *name, const char *msg);
void	ms_perror_cmd2(const char *name, const char *type, const char *msg);

#endif
