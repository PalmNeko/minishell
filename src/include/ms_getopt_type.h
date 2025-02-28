/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getopt_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:57:13 by tookuyam          #+#    #+#             */
/*   Updated: 2025/01/31 15:58:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_GETOPT_TYPE_H
# define MS_GETOPT_TYPE_H

# include <stdbool.h>

/**
 * @brief The private optioning structure.
 * @param is_parsed If true, the option is parsed.
 * @param optpos The position of the next option.
 */
typedef struct s_internal_opting
{
	bool	is_parsed;
	int		optpos;
}	t_internal_opting;

/**
 * @brief The optioning structure.
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param optstring The option string.
 * @param is_skip_double_hyphen If true, skip the double hyphen.
 * @param is_valid If true, the read character is valid.
 * @param is_valid_optstatement If true, the read string is valid.
 * @param optind The index of the next argument.
 * @param optopt The read character.
 * @param internal The internal structure.
 */
typedef struct s_opting
{
	int					argc;
	char				**argv;
	char				*optstring;
	bool				is_skip_double_hyphen;
	bool				is_valid;
	bool				is_valid_optstatement;
	int					optind;
	int					nowind;
	int					optopt;
	t_internal_opting	internal;
}	t_opting;

#endif
