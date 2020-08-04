/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:48:51 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/04 08:40:42 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>

void	error(char *output)
{
	printf("\n\e[35m[-] ERROR: %s\e[0m\n\n", output);
	exit(1);
}

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

int		main()
{
	test_ft_strlen();
	test_ft_strcpy();
	return (0);
}
