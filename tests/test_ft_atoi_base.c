/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:36 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/06 18:40:16 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_atoi_base(void)
{
	char	*src;
	int		res;

	src = " 0000101";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 2)), src);
	if (res != 5) error("atoi_base");
	src = " -2147483648";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != -2147483648) error("atoi_base");
	src = "abcdefgh";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 500)), src);
	if (res != 0) error("atoi_base");
	if (ft_atoi_base(" 12231", 1) != 0) error("atoi_base");
	src = "          +1234";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != 1234) error("atoi_base");
	src = "   \t     -1234";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != -1234) error("atoi_base");
	src = "-1234";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != -1234) error("atoi_base");
	src = "1234";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);	
	if (res != 1234) error("atoi_base");

	src = "          +4321";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != 4321) error("atoi_base");
	src = "   \t     -4321";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != -4321) error("atoi_base");
	src = "-4321";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != -4321) error("atoi_base");
	src = "4321";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 10)), src);
	if (res != 4321) error("atoi_base");
	
	src = "          +ab2f";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 16)), src);
	if (res != 43823) error("atoi_base");
	src = "   \t     -ab2f";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 16)), src);
	if (res != -43823) error("atoi_base");
	src = "-ab2f";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 16)), src);
	if (res != -43823) error("atoi_base");
	src = "ab2f";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 16)), src);
	if (res != 43823) error("atoi_base");
	src = "gab2f";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 16)), src);
	if (res != 0) error("atoi_base");

	src = " +ab210c";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 13)), src);
	if (res != 4031676) error("atoi_base");

	src = " +AB210C";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 13)), src);
	if (res != 4031676) error("atoi_base");

	src = " +aAaB00";
	printf("nbr = %-5d |%s|\n", (res = ft_atoi_base(src, 12)), src);
	if (res != 2714544) error("atoi_base");

	printf("\n\e[32m[+] SUCCESS: ft_atoi_base\e[0m\n\n");
}
