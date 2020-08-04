/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:48:51 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/04 09:29:08 by zkerriga         ###   ########.fr       */
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

void	test_ft_strcmp(void)
{
	char	*s1;
	char	*s2;

	s1 = "";
	s2 = "";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("zero str");
	s1 = "avd";
	s2 = "";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("avd str");
	s1 = "";
	s2 = "avd";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("avd2 str");
	s1 = "cbs";
	s2 = "avd";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("not equal str");
	s1 = "123l\tasd\n";
	s2 = "123l\tasd\n";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("equal str");
	s1 = "123l\tasd\n1s23l\tas1d\n1k23l\tasd\n000001\b\r_";
	s2 = "123l\tasd\n1s23l\tas1d\n1k23l\tasd\n000001\b\r_";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("long equal str");
	s1 = "123l\tasd\n1s23l\tas1d\n1_23l\tasd\n000001\b\r_";
	s2 = "123l\tasd\n1s23l\tas1d\n1k23l\tasd\n000001\b\r_";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("long not equal str");
	printf("ft_strcmp: %d\n   strcmp: %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	s1 = "123l\tasd\n1s23l\tas1d\n1k23l\tasd\n000001\b\r_";
	s2 = "123l\tasd\n1s23l\tas1d\n1_23l\tasd\n000001\b\r_";
	if (!!strcmp(s1, s2) != !!ft_strcmp(s1, s2))
		error("long not equal str");
	printf("ft_strcmp: %d\n   strcmp: %d\n", ft_strcmp(s1, s2), strcmp(s1, s2));
	printf("\n\e[32m[+] SUCCESS: ft_strcmp\e[0m\n\n");
}

int		main()
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	return (0);
}
