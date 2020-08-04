/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:48:51 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/04 07:35:02 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>

void	error(char *output)
{
	printf("ERROR: %s\n", output);
	exit(1);
}

void	test_ft_strlen(void)
{
	size_t	len;

	len = 0;
	if ((len = ft_strlen("")) != strlen(""))
		error("zero str");
	if ((len = ft_strlen("\0")) != strlen("\0"))
		error("zero str");
	if ((len = ft_strlen("\0\0")) != strlen("\0\0"))
		error("zero str");
	if ((len = ft_strlen("123")) != strlen("123"))
		error("tree str 123");
	if ((len = ft_strlen("abc")) != strlen("abc"))
		error("tree str abc");
	if ((len = ft_strlen("looooooooooooooooooooooooooooooooong")) !=
		strlen("looooooooooooooooooooooooooooooooong"))
	{
		error("long str");
	}
	printf("\n\e[32m[+] SUCCESS: ft_strlen\e[0m\n\n");
}

int		main()
{
	test_ft_strlen();
	return (0);
}
