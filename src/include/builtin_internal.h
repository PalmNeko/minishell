/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:20 by tookuyam          #+#    #+#             */
/*   Updated: 2025/02/03 06:30:04 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

# include <stdbool.h>

void	ms_set_character_map(const char *str, bool map[256]);
bool	ms_is_cwd_check(char *const argv[]);
void	ms_perror_invalid_option(const char *cmd, char opt);

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
