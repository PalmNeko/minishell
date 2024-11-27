/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_module.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:11:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/25 17:12:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FP_MODULE_H
# define FP_MODULE_H

# include <stdbool.h>
# include <stdarg.h>
# include "fp_module_types.h"

char	*fp_add_0x(bool be_add, int	*len, char *str);
char	*fp_add_sign(int type, int *len, char *str);
char	*fp_convert_int2str(int precision, int *len, int value);
char	*fp_convert_ptr2str(int precision, int *len, unsigned int value);
char	*fp_convert_uchr2str(int *size, unsigned char chr);
char	*fp_convert_uint2str(
			int precision, int *len, unsigned long value, int base);
char	*fp_cut_string(int length, int *size, char *str);
char	*fp_gen_chrstr(t_cs *cs, int *len, unsigned char uchr);
char	*fp_gen_intstr(t_cs *cs, int *len, int value);
char	*fp_gen_ptrstr(t_cs *cs, int *len, unsigned long value);
char	*fp_gen_str(t_cs *cs, int *len, char *str);
char	*fp_gen_uintstr(t_cs *cs, int *len, unsigned long value, int base);
char	*fp_pad_for_num(int zero_field_width, int *size, char *str);
char	*fp_to_upper(bool be_upper, int *len, char *str);
int		fp_get_cs_len(const char *format);
int		fp_get_sign_type(t_cs *cs);
int		fp_print_aligned_left(int fd, int field_width, int *len, char *str);
int		fp_print_aligned_right(int fd, int field_width, int *len, char *str);
int		fp_vdprint_cs(int fd, t_cs *cs, va_list args);
t_cs	*fp_generate_cs(const char *format);
t_cs	*fp_new_t_cs(void);
void	fp_destroy_t_cs(t_cs *ptr);
void	fp_rewrite_special_behavior(t_cs *cs);

#endif
