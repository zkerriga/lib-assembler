/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:58:33 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_lstnew(void)
{
	t_list	*lst;
	int		data;

	data = 123;
	lst = ft_lstnew(&data);
	printf("*(lst->data) = %d\n", *((int *)(lst->data)));
	printf("lst->next = %d\n", lst->next);
	if (*((int *)(lst->data)) != 123 || lst->next != NULL)
		error("123 t_list");
	free(lst);

	data = 190001;
	lst = ft_lstnew(&data);
	printf("*(lst->data) = %d\n", *((int *)(lst->data)));
	printf("lst->next = %d\n", lst->next);
	if (*((int *)(lst->data)) != 190001 || lst->next != NULL)
		error("190001 t_list");
	free(lst);
	printf("\n\e[32m[+] SUCCESS: ft_lstnew\e[0m\n\n");
}
