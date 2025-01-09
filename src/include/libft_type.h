/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:03:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/11/28 15:03:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPE_H
# define LIBFT_TYPE_H

# include <stddef.h>
# include <stdbool.h>

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

#endif
