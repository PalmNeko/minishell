#include <gtest/gtest.h>

extern "C" {
    #include "libms.h"
	#include "libft.h"
	#include <stdlib.h>
};

// 追加できること。
TEST(ms_lst_to_ntp, can_add)
{
	char	**ntp;
	t_list	*lst;
	t_list	*new_list;

	lst = NULL;
	new_list = ft_lstnew((void *)ft_strdup("123"));
	ASSERT_NE(new_list, nullptr);
	ft_lstadd_back(&lst, new_list);
	ntp = (char **)(ms_lst_to_ntp(&lst, (void *(*)(void *))ft_strdup, free));
	if (ntp == nullptr) {
		ft_lstclear(&lst, (void (*)(void *))ft_voidnop);
		ASSERT_NE(ntp, nullptr);
	}
	EXPECT_STREQ(ntp[0], "123");
	EXPECT_STREQ(ntp[1], nullptr);
	ms_destroy_ntp(ntp);
}

// NULLまでは追加できること。
TEST(ms_lst_to_ntp, until_null)
{
	char	**ntp;
	t_list	*lst;
	t_list	*new_list;

	lst = NULL;
	new_list = ft_lstnew((void *)NULL);
	ASSERT_NE(new_list, nullptr);
	ft_lstadd_back(&lst, new_list);
	new_list = ft_lstnew((void *)ft_strdup("123"));
	ASSERT_NE(new_list, nullptr);
	ft_lstadd_back(&lst, new_list);
	ntp = (char **)(ms_lst_to_ntp(&lst, (void *(*)(void *))ft_strdup, free));
	if (ntp == nullptr) {
		ft_lstclear(&lst, (void (*)(void *))ft_voidnop);
		ASSERT_NE(ntp, nullptr);
	}
	EXPECT_STREQ(ntp[0], nullptr);
	ms_destroy_ntp(ntp);
}
