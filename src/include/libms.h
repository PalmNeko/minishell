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
# include "libms_type.h"
# include <stddef.h>

/** string.h */
char			*ms_strpbrk(const char *s, const char *accept);

/** unistd.h */
char			*ms_get_current_dir_name(void);

/**
 * libms
 */
char			*ms_join_ntp(const char *ntp[], const char *pad);
char			**ms_dup_ntp(const char *ntp[]);
char			**ms_dup_ntp2(const char *const ntp[]);
char			**ms_dup_ntp3(char *ntp[]);
char			**ms_dup_ntp4(char *const ntp[]);
void			ms_destroy_ntp(char *ntp[]);
void			ms_destroy_ntp2(void **ntp, void (*fr)(void *));
void			*ms_lst_to_ntp(
					t_list **lst, void *(*cp)(void *), void (*fr)(void *));
size_t			ms_ntpsize(void **ntp);
int				ms_get_interactive_stat(void);
char			*ms_strdup_sep(const char *str, char sep);
char			*ms_path_join(const char *base, const char *path);
char			**ms_separate(const char *str, char sep);
bool			ms_is_dir(const char *path);
char			*ms_to_abs_path(const char *path);
char			*ms_normalize_path(const char *path);
char			*ms_get_full_path(const char *basedir, const char *path);
char			*ms_replace_joined_str(char **left, char *right);
char			*ms_tilde_expansion(const char *path);
int				ms_trim_end_newline(char *str);

void			*ms_identify(void *arg);
void			ms_noop_del(void *arg);

void			ms_lstappend_tail(
					t_list **lst, void *content, void (*fr)(void *));

void *ms_identify(void *arg);
void ms_noop_del(void *arg);

void ms_lstappend_tail(t_list **lst, void *content, void (*fr)(void *));

// environment variable
char			*ms_getenv(const char *name);
int				ms_setenv(const char *name, const char *value, int overwrite);
int				ms_unsetenv(const char *name);
int				ms_import_env(char *const envp[]);
char			**ms_export_env(void);
void			ms_clear_environ(void *unused);

int				ms_add_envattr(const char *name, t_ms_var_type attr);
int				ms_set_envattr(const char *name, t_ms_var_type attr);
int				ms_remove_envattr(const char *name, t_ms_var_type attr);
bool			ms_has_envattr(const char *name, t_ms_var_type attr);
t_ms_var_type	ms_get_envattr(const char *name);

// environment variable
char			**ms_get_pwd(void);

// errors
void			ms_perror_shell(const char *msg);
void			ms_perror_cmd(const char *name, const char *msg);
void			ms_perror_cmd2(
					const char *name, const char *type, const char *msg);

#endif
