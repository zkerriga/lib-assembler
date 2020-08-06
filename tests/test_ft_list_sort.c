/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:28:04 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/06 18:47:41 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*
void	swap(t_list *lst1, t_list *lst2)
{
	void	*swp;

	swp = lst1->data;
	lst1->data = lst2->data;
	lst2->data = swp;
}

void bubbleSort(t_list **begin_list, int (*cmp)())
{
	t_list	*i_list;
	t_list	*j_list;

	i_list = *begin_list;
	while (i_list->next != NULL)
	{
		j_list = *begin_list;
		while (j_list->next != NULL)
		{
			if (cmp(j_list->data, j_list->next->data) > 0)
			{
				swap(j_list, j_list->next);
			}
			j_list = j_list->next;
		}
		i_list = i_list->next;
	}
}
*/

static int		compare(void *data_ref, void *data)
{
	//printf("-- %c :: %c --", *(char *)data_ref, *(char *)data);
	//printf("> %2d\n", data_ref - data);
	return (data_ref - data);
}

static int		compare_rev(void *data_ref, void *data)
{
	return (data - data_ref);
}

void	test_ft_list_sort(void)
{
	t_list	*lst = NULL;
	char	*str = "12345";
	t_list	*cur = NULL;

	ft_list_push_front(&lst, str + 0);	
	ft_list_push_front(&lst, str + 1);	
	ft_list_push_front(&lst, str + 4);	
	ft_list_push_front(&lst, str + 3);	
	ft_list_push_front(&lst, str + 2);
	cur = lst;
	while (cur)
	{
		printf("-> %s\n", cur->data);
		cur = cur->next;
	}
	printf(" --- \n");
	ft_list_swap(lst, lst->next);
	cur = lst;
	while (cur)
	{
		printf("-> %s\n", cur->data);
		cur = cur->next;
	}
	printf(" --- \n");
	//bubbleSort(&lst, compare);
	ft_list_sort(&lst, compare);
	cur = lst;
	while (cur)
	{
		printf("-> %s\n", cur->data);
		cur = cur->next;
	}
	printf(" --- \n");
	ft_list_sort(&lst, compare_rev);
	cur = lst;
	while (cur)
	{
		printf("-> %s\n", cur->data);
		cur = cur->next;
	}
	printf("\n\e[33m[?] SUCCESS: ft_list_sort\e[0m\n\n");
}

