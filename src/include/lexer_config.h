#ifndef LEXER_CONFIG_H
# define LEXER_CONFIG_H

# include "lexer_type.h"

# define TYPE 0
# define CATEGORY 1
# define LETTER_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"
# define DIGIT_CHARS "0123456789"
# define META_CHARS "<> \n\t=|()\"\'"
# define REDIRECTION_CHARS "<>"
# define BLANK_CHARS " \t"
# define LIST_CHARS "&|"

#endif