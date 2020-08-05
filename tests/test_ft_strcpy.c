/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:48:45 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:52:53 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_strcpy(void)
{
	char		dest1[30];
	char		dest2[30];
	char		*src0;

	src0 = "";
	printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0), strcpy(dest2, src0));
	if (strcmp(dest1, dest2) != 0)
		error("zero str");
	src0 = "123456789";
	printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0), strcpy(dest2, src0));
	if (strcmp(dest1, dest2) != 0)
		error("digits str");
	src0 = "abc";
	printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0), strcpy(dest2, src0));
	if (strcmp(dest1, dest2) != 0)
		error("abc str");
	src0 = "-ad1+%\n";
	printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0), strcpy(dest2, src0));
	if (strcmp(dest1, dest2) != 0)
		error("wtf str");
	src0 = "llloooooooooooooooooooooooong";
	printf("ft_strcpy: |%s|\n   strcpy: |%s|\n", ft_strcpy(dest1, src0), strcpy(dest2, src0));
	if (strcmp(dest1, dest2) != 0)
		error("long str");
	printf("\n\e[32m[+] SUCCESS: ft_strcpy\e[0m\n\n");
}
