/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_config.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyts <nyts@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:14:55 by nyts              #+#    #+#             */
/*   Updated: 2025/03/04 19:14:56 by nyts             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_CONFIG_H
# define LEXER_CONFIG_H

# define TYPE 0
# define CATEGORY 1
# define LETTER_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"
# define DIGIT_CHARS "0123456789"
# define IDENTIFY_CHARS LETTER_CHARS DIGIT_CHARS
# define VARIABLE_INITIAL_CHARS LETTER_CHARS "?"
# define META_CHARS "<> \n\t=|&()"
# define QUOTE_CHARS "\"\'"
# define NOT_WORD_CHARS META_CHARS QUOTE_CHARS
# define REDIRECTION_CHARS "<>"
# define BLANK_CHARS " \t"
# define LIST_CHARS "&|"

#endif