/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:19 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:56:24 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_tolower(void)
{
	for (int i = 127; i > 0; --i)
	{
		if (ft_tolower(i) != tolower(i))
			error("not lower");
	}
	printf("\n\e[32m[+] SUCCESS: ft_tolower\e[0m\n\n");
}
