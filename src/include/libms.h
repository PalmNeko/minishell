/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libms.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:22:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/24 21:22:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMS_H
# define LIBMS_H

# include <stddef.h>

/**
 * libft
 */
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

/**
 * libms
 */
char	*ms_join_ntp(const char *ntp[], const char *pad);
char	**ms_dup_ntp(const char *ntp[]);
char	**ms_dup_ntp2(const char *const ntp[]);
void	ms_destroy_ntp(char *ntp[]);

#endif
