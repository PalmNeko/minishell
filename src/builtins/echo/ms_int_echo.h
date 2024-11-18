#ifndef MS_INT_ECHO_H
# define MS_INT_ECHO_H

# include <stddef.h>
# include <stdbool.h>

bool	ms_has_opt(char *const argv[], const char *opt);
char	*ms_join_ntp(char *const ntp[], const char *pad);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
