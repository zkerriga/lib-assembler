/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:48:51 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/06 17:54:20 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

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

