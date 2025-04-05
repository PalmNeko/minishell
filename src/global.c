/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakatan <rnakatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:09:48 by rnakatan          #+#    #+#             */
/*   Updated: 2025/04/05 12:38:05 by rnakatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyze_config.h"

const char	g_identify_chars[] = LETTER_CHARS DIGIT_CHARS;
const char	g_variable_initial_chars[] = LETTER_CHARS "?";
