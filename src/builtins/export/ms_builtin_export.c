/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:04:30 by tookuyam          #+#    #+#             */
/*   Updated: 2024/12/25 20:04:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export_internal.h"

/**
 * TODO: 値が代入されていないが、exportされている環境変数を表示する。
 * TODO: 代入できるようにする。
 * TODO: exportのみができるようにする。
 * TODO: 引数のエラーチェック
 * TODO: テストの作成
 */

int ms_error_handling_export(
		const char *path, char *const argv[], char *const envp[]);

int	ms_builtin_export(
		const char *path, char *const argv[], char *const envp[])
{
	int		status;

	status = ms_error_handling_export(path, argv, envp);
	if (status != 0)
		return (status);
	return (ms_export_print_command());
	return (0);
}

int ms_error_handling_export(
		const char *path, char *const argv[], char *const envp[])
{
	(void)path;
	(void)argv;
	(void)envp;
	return (0);
}
