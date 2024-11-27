/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:49:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/15 08:50:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_free_args
{
	void	(*free_func)();
	void	*arg;
}	t_free_args;

typedef struct s_iter
{
	void	*current;
	void	*end;
	void	*start;
	void	*(*next)(struct s_iter *itr);
	bool	(*has_next)(struct s_iter * itr);
	size_t	index;
}	t_iter;

/**
 * @param key search keywoad pointer
 * @param base search array (must sorted)
 * @param nmemb base array count
 * @param size one element size of "base" param
 * @param compar compare function.
 * must return left < right then negative, left > right then positive or
 * left == right then 0(zero).
*/
typedef struct s_bsearch_arg {
	const void	*key;
	const void	*base;
	size_t		nmemb;
	size_t		size;
	int			(*compar)(const void *, const void *);
}	t_bsearch_arg;

bool		ft_includes(char c, char *sets);
bool		ft_replace_last_newline(char *str);
bool		ft_strmatch(char *pattern, char *text);
bool		ft_strincludes(char *texts, char *sets);
char		**ft_split(char const *s, char c);
char		*ft_get_errinfo(void);
char		*ft_getenv(const char *name);
char		*ft_itoa(int n);
char		*ft_ltoa_inplace(long value, char *buffer, int radix);
char		*ft_replace_random_alpha(
				char *str, int cnt, uint32_t seed, uint32_t no);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strleftalign(const char *s1, size_t width);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrepeat(char *str, unsigned int times);
char		*ft_strrightalign(const char *s1, size_t width);
char		*ft_strtolower(char *str);
char		*ft_strtoupper(char *str);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_ultoa_base_str(unsigned long n, const char *base_str);
char		*ft_utoa(unsigned int n);
char		*ft_utoa_base_str(unsigned int n, const char *base_str);
int			ft_abs(int i);
int			ft_atoi(const char *str);
int			ft_clamp(int min, int val, int max);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isspace(char c);
int			ft_isupper(int c);
int			ft_lstsize(t_list *lst);
int			ft_max(int a, int b);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_min(int a, int b);
int			ft_mkostemp(char *template, int flags);
int			ft_nop(void);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
long		ft_add_l(long value, long add_value);
long		ft_ifl(bool condition, long iftrue, long iffalse);
long		ft_mul_l(long value, long mul_value);
long		ft_strtol(const char *str, char **endptr, int base);
size_t		ft_putstr_fd(const char *s, int fd);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t maxlen);
ssize_t		ft_putchar_fd(char c, int fd);
ssize_t		ft_write_aligned_left(
				int fd, const void *buf, size_t n, size_t width);
ssize_t		ft_write_aligned_right(
				int fd, const void *buf, size_t n, size_t width);
t_list		*ft_array_to_lst(void **array, size_t size);
t_list		*ft_lstat(t_list *list, int no);
t_list		*ft_lstfirst(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstnewcircular(void *content);
t_list		*ft_lstpop(t_list **lst);
uint32_t	ft_xorshift_u32(uint32_t seed, uint32_t x);
uint32_t	ft_addr2uint32_t(void *addr);
void		**ft_lst_to_array(t_list *lst, size_t *ret_size);
void		*ft_bsearch(t_bsearch_arg *arg);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_realloc(void *ptr, size_t old_size, size_t size);
void		ft_bzero(void *s, size_t n);
void		ft_clear_errinfo(void);
void		ft_free_iter(t_free_args *free_args, size_t size);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdel_content(
				t_list **root, void *content, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstinit_itr(t_list *lst, t_iter *itr);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstpush(t_list **lst, t_list *content);
void		ft_lsttocircular(t_list *lst);
void		ft_memswap(void *value1, void *value2, size_t size);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_selection_sort(
				void *base,
				size_t num,
				size_t size,
				int (*f_cmp)(const void *n1, const void *n2));
void		ft_set_errinfo(char *einfo);
void		ft_set_errno(int eno);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_strrev(char *str);
void		ft_swap_chr(char *a, char *b);
void		ft_voidnop(void);

#endif
