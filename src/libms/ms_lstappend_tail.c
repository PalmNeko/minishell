#include <libft.h>

void ms_lstappend_tail(t_list **lst, void *contents , void (*fr)(void *))
{
	t_list *new;

	new = ft_lstnew(contents);
	if (new == NULL)
	{
		ft_lstclear(lst, fr);
		return ;
	}
	ft_lstadd_back(lst, new);
}