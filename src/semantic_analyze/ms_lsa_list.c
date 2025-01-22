#include "semantic_analyze.h"
#include <stdlib.h>

static t_lsa_list *ms_create_lsa_list(void);

/* Notice
 * 実装通りにしたが、関数名と挙動が一致してないからかしっくりこない
*/

t_lsa_list *ms_lsa_list(t_syntax_node *list_node)
{
	t_lsa_list *lsa_list;
	t_lsa_list **compound_list;
	t_lsa_pipeline *lsa_pipeline;
	
	lsa_list = ms_create_lsa_list();
	if(lsa_list == NULL)
		return (NULL);
	if(list_node->type == SY_PIPELINE)
	{
		lsa_pipeline = ms_lsa_pipeline(list_node);
		if(lsa_pipeline == NULL)
			return (NULL);
		lsa_list->pipeline = lsa_pipeline;
	}else if(list_node->type == SY_COMPOUND_LIST){
		compound_list = ms_lsa_lists(list_node->children[1]);
		if(compound_list == NULL)
			return (NULL);
		lsa_list->compound_list = compound_list;
	}
	return (lsa_list);
}

static t_lsa_list *ms_create_lsa_list(void)
{
	t_lsa_list *lsa_list;

	lsa_list = malloc(sizeof(t_lsa_list));
	if (lsa_list == NULL)
		return (NULL);
	lsa_list->type = LSA_LIST_ALWAYS;
	lsa_list->pipeline = NULL;
	lsa_list->compound_list = NULL;
	return (lsa_list);
}

// static t_lsa_list **ms_lsa_compound_list(t_syntax_node *compound_list_node)
// {
// 	t_lsa_list **lsa_list;
// 	t_syntax_node *child;
// 	t_syntax_node_list *child_lst;
// 	int i;

// 	child_lst = compound_list_node->children;
// 	lsa_list = malloc(sizeof(t_lsa_list *) * (ms_lstsize(child_lst) + 1));
// 	if (lsa_list == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (child_lst)
// 	{
// 		child = child_lst->node;
// 		if (child->type == SY_LIST)
// 			lsa_list[i] = ms_lsa_list(child);
// 		else
// 			lsa_list[i] = ms_lsa_list(child->children[1]);
// 		if (lsa_list[i] == NULL)
// 			return (NULL);
// 		child_lst = child_lst->next;
// 		i++;
// 	}
// 	lsa_list[i] = NULL;
// 	return (lsa_list);
// }