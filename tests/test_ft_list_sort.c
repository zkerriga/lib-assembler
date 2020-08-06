/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:28:04 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/06 15:43:54 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

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
/*
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
    	{
      		if ( num[j] > num[j + 1])
			{
				swap;
      		}
    	}
  	}
*/

static int		compare(void *data_ref, void *data)
{
	return (data_ref - data);
}

void	test_ft_list_sort(void)
{
	t_list	*lst = NULL;
	char	*str = "abcde";
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
	cur = lst;
	while (cur)
	{
		printf("-> %s\n", cur->data);
		cur = cur->next;
	}
	printf("\n\e[33m[?] SUCCESS: ft_list_sort\e[0m\n\n");
}

