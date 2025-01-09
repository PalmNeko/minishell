/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/28 17:59:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

# include <stdbool.h>

bool	ms_has_opt(char *const argv[], char opt, const char *valid_opts);
bool	ms_is_option(const char *arg);
bool	ms_validate_opts(const char *opts, const char *valid_opts);
void	ms_set_character_map(const char *str, bool map[256]);
char	*ms_get_first_invalid_opt(char *const argv[], const char *valid_opts);
char	**ms_get_argument_head(char *const argv[], const char *valid_opts);
char	*ms_set_opt_txt(char buf[3], char invalid_opt);
char	**ms_get_first_arg_ptr(char *const argv[], const char *valid_opt);
int		ms_check_opt(char *const argv[], const char *valid_opt);
bool	ms_is_cwd_check(char *const argv[]);

// variable
char	**ms_get_raw_cdwd(void);
char	*ms_get_cdwd(void);
void	ms_set_cdwd(const char *cdwd);

// cd
int		ms_error_handling_cd(
			const char *path, char *const argv[], char *const envp[]);
char	*ms_get_opt_lp(char *const argv[]);
bool	ms_is_unresolve_symlink(char *const argv[]);
bool	ms_is_resolve_symlink(char *const argv[]);
void	ms_perror_cd(const char *type);
void	ms_perror_cd_cwd(void);

#endif
