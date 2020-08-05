/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:14 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:55:52 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_isspace(void)
{
	for (int i = 100; i != 0; --i)
	{
		if (!!ft_isspace(i) != !!isspace(i))
			error("not space");
	}
	printf("\n\e[32m[+] SUCCESS: ft_isspace\e[0m\n\n");
}
