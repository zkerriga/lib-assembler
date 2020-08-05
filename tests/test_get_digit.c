/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:28 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:57:03 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_get_digit(void)
{
	char	c;
	int		base;
	int		res;

	c = '1'; base = 10;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != 1)
		error("get_digit");
	c = '1'; base = 14;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != 1)
		error("get_digit");
	c = 'l'; base = 10;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != -1)
		error("get_digit");
	c = 'f'; base = 16;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != 15)
		error("get_digit");
	c = 'f'; base = 14;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != -1)
		error("get_digit");
	c = 'b'; base = 15;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != 11)
		error("get_digit");
	c = 'Z'; base = 16;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != -1)
		error("get_digit");
	c = 'Z'; base = 16;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != -1)
		error("get_digit");
	c = '9'; base = 10;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != 9)
		error("get_digit");
	c = '0'; base = 10;
	printf("c = %c, base = %d --> %d\n", c, base, (res = get_digit(c, base)));
	if (res != 0)
		error("get_digit");
	printf("\n\e[32m[+] SUCCESS: get_digit\e[0m\n\n");
}
