/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:56:55 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/15 19:56:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdbool.h>

int	ms_builtin_echo(
		const char *path, char *const argv[], char *const envp[]);
int	ms_builtin_pwd(
		const char *path, char *const argv[], char *const envp[]);
int	ms_builtin_unset(
		const char *path, char *const argv[], char *const envp[]);
int	ms_builtin_env(
		const char *path, char *const argv[], char *const envp[]);
int	ms_builtin_exit(
		const char *path, char *const argv[], char *const envp[]);
int	ms_builtin_cd(
		const char *path, char *const argv[], char *const envp[]);
int	ms_builtin_export(
		const char *path, char *const argv[], char *const envp[]);

#endif
