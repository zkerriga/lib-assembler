/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:50 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:58:56 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_list_push_front(void)
{
	t_list	*lst = NULL;
	char	*str1 = "str1";
	char	*str2 = "str2";
	int		size;

	printf("size = %d\n", (size = ft_list_size(lst)));
	if (size != 0) error("list size");
	ft_list_push_front(&lst, str1);
	printf("size = %d\n", (size = ft_list_size(lst)));
	if (size != 1) error("list size");
	ft_list_push_front(&lst, str2);
	printf("size = %d\n", (size = ft_list_size(lst)));
	if (size != 2) error("list size");
	printf("lst->data = |%s|, ->next = %p\n", (char *)lst->data, lst->next);
	printf("lst->next->data = |%s|, ->next = %p\n", (char *)lst->next->data, lst->next->next);
	if (lst->next->next != NULL)
		error("add front");
	ft_list_push_front(&lst, str1);
	printf("size = %d\n", (size = ft_list_size(lst)));
	if (size != 3) error("list size");
	printf("lst->data = |%s|, ->next = %p\n", (char *)lst->data, lst->next);
	printf("lst->next->data = |%s|, ->next = %p\n", (char *)lst->next->data, lst->next->next);
	if (lst->next->data != str2)
		error("add front");
	free(lst->next->next);
	free(lst->next);
	free(lst);
	printf("\n\e[32m[+] SUCCESS: ft_list_push_front\e[0m\n\n");
	printf("\n\e[32m[+] SUCCESS: ft_list_size\e[0m\n\n");
}
