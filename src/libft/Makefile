# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 17:19:34 by tookuyam          #+#    #+#              #
#    Updated: 2024/11/26 16:30:37 by tookuyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS += -Wall -Wextra -Werror -I .
CFLAGS += -MP -MMD -Wno-unused-value
SRCS = \
	ft_abs.c \
	ft_add_l.c \
	ft_addr2uint32_t.c \
	ft_array_to_lst.c \
	ft_atoi.c \
	ft_bsearch.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_clamp.c \
	ft_errinfo.c \
	ft_free_iter.c \
	ft_getenv.c \
	ft_ifl.c \
	ft_includes.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_isupper.c \
	ft_itoa.c \
	ft_ltoa_inplace.c \
	ft_lst_to_array.c \
	ft_lstat.c \
	ft_lstdel_content.c \
	ft_lstfirst.c \
	ft_lstinit_itr.c \
	ft_lstnewcircular.c \
	ft_lstpop.c \
	ft_lstpush.c \
	ft_lsttocircular.c \
	ft_max.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_memswap.c \
	ft_min.c \
	ft_mkostemp.c \
	ft_mul_l.c \
	ft_nop.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_realloc.c \
	ft_replace_last_newline.c \
	ft_replace_random_alpha.c \
	ft_selection_sort.c \
	ft_set_errno.c \
	ft_split.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strdup.c \
	ft_strincludes.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strleftalign.c \
	ft_strlen.c \
	ft_strmatch.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strndup.c \
	ft_strnlen.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strrepeat.c \
	ft_strrev.c \
	ft_strrightalign.c \
	ft_strtol.c \
	ft_strtolower.c \
	ft_strtoupper.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_swap_chr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_ultoa_base_str.c \
	ft_utoa.c \
	ft_utoa_base.c \
	ft_voidnop.c \
	ft_write_aligned_left.c \
	ft_write_aligned_right.c \
	ft_xorshift_u32.c \
	get_next_line.c

# ftprintf
SRCS += \
	ft_printf.c \
	ft_dprintf.c \
	ft_vdprintf.c \
	fp_modules/fp_add_0x.c \
	fp_modules/fp_add_sign.c \
	fp_modules/fp_convert_int2str.c \
	fp_modules/fp_convert_ptr2str.c \
	fp_modules/fp_convert_uchr2str.c \
	fp_modules/fp_convert_uint2str.c \
	fp_modules/fp_cut_string.c \
	fp_modules/fp_destroy_t_cs.c \
	fp_modules/fp_generate_cs.c \
	fp_modules/fp_gen_chrstr.c \
	fp_modules/fp_gen_intstr.c \
	fp_modules/fp_gen_ptrstr.c \
	fp_modules/fp_gen_str.c \
	fp_modules/fp_gen_uintstr.c \
	fp_modules/fp_get_cs_len.c \
	fp_modules/fp_get_sign_type.c \
	fp_modules/fp_new_t_cs.c \
	fp_modules/fp_pad_for_num.c \
	fp_modules/fp_print_aligned_left.c \
	fp_modules/fp_print_aligned_right.c \
	fp_modules/fp_rewrite_special_behavior.c \
	fp_modules/fp_to_upper.c \
	fp_modules/fp_vdprint_cs.c

BONUS = \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
DEPENDS = $(SRCS:.c=.d)
BONUS_RULE = bonus
BONUS_OBJS = $(BONUS:.c=.o)
BONUS_DEPENDS = $(BONUS:.c=.d)
RELINK_GURAD_FLIES = $(BONUS_RULE)
CLEAN_FILES = $(OBJS) $(BONUS_OBJS) $(RELINK_GURAD_FLIES) $(DEPENDS) $(BONUS_DEPENDS)

all: $(NAME) $(BONUS_RULE)

-include $(DEPENDS)
-include $(BONUS_DEPENDS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

$(BONUS_RULE): $(BONUS_OBJS)
	ar rcs $(NAME) $?
	echo date > $(BONUS_RULE)

clean:
	$(RM) $(CLEAN_FILES)

fclean: clean
	$(RM) $(NAME)

show:
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LDLIBS		: $(LDLIBS)\n"
	@printf "SRCS		:\n	$(SRCS)\n"
	@printf "OBJS		:\n	$(OBJS)\n"
	@printf "BONUS		:\n	$(BONUS)\n"

re: fclean all

debug: CFLAGS  += -g -O0
debug: re

.PHONY: all clean fclean re
