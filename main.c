/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:48:51 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 20:42:29 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	error(char *output)
{
	printf("\n\e[35m[-] ERROR: %s\e[0m\n\n", output);
	exit(1);
}

int		main()
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	test_ft_isspace();
	test_ft_tolower();
	test_get_digit();
	test_ft_atoi_base();
	test_ft_lstnew();
	test_ft_list_push_front();
	test_ft_list_sort();
	test_ft_list_remove_if();
	return (0);
}
