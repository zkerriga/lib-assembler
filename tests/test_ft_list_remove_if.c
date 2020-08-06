/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:27:54 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/06 18:46:57 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	compare(void *data_ref, void *data)
{
	return (data_ref - data);
}

void		test_ft_list_remove_if(void)
{
	t_list	*lst = NULL;
	t_list	*i;
	char	*str = "abcde";

	ft_list_push_front(&lst, str + 4);
	ft_list_push_front(&lst, str + 3);
	ft_list_push_front(&lst, str + 2);
	ft_list_push_front(&lst, str + 1);
	ft_list_push_front(&lst, str + 0);
	i = lst;
	while (i)
	{
		printf("-> %s\n", i->data);
		i = i->next;
	}
	printf("\n");
	ft_list_remove_if(&lst, str + 3, compare);
	i = lst;
	while (i)
	{
		printf("-> %s\n", i->data);
		i = i->next;
	}
	printf("\n");
	ft_list_remove_if(&lst, str + 1, compare);
	i = lst;
	while (i)
	{
		printf("-> %s\n", i->data);
		i = i->next;
	}
	printf("\n");
	ft_list_remove_if(&lst, str + 4, compare);
	i = lst;
	while (i)
	{
		printf("-> %s\n", i->data);
		i = i->next;
	}
	printf("\n");
    ft_list_remove_if(&lst, str, compare);
    i = lst;
    while (i)
    {
        printf("-> %s\n", i->data);
        i = i->next;
    }
    ft_list_remove_if(&lst, NULL, compare);
	printf("\n last:\n");
    ft_list_remove_if(&lst, str + 2, compare);
    i = lst;
    while (i)
    {
        printf("-> %s\n", i->data);
        i = i->next;
    }
	printf("\n\e[33m[?] SUCCESS: ft_list_remove_if\e[0m\n\n");
}
