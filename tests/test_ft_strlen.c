/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:48:38 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:52:59 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_strlen(void)
{
	size_t	len;

	len = 0;
	if ((len = ft_strlen("")) != strlen(""))
		error("zero str");
	printf("len = %ld\n", len);
	if ((len = ft_strlen("\0")) != strlen("\0"))
		error("zero str");
	printf("len = %ld\n", len);
	if ((len = ft_strlen("\0\0")) != strlen("\0\0"))
		error("zero str");
	printf("len = %ld\n", len);
	if ((len = ft_strlen("123")) != strlen("123"))
		error("tree str 123");
	printf("len = %ld\n", len);
	if ((len = ft_strlen("abc")) != strlen("abc"))
		error("tree str abc");
	printf("len = %ld\n", len);
	if ((len = ft_strlen("looooooooooooooooooooooooooooooooong")) !=
		strlen("looooooooooooooooooooooooooooooooong"))
	{
		error("long str");
	}
	printf("len = %ld\n", len);
	printf("\n\e[32m[+] SUCCESS: ft_strlen\e[0m\n\n");
}
