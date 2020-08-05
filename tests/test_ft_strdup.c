/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:06 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:55:16 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_strdup(void)
{
	char	*src0;
	char	*sys;
	char	*ft;

	src0 = "";
	printf("ft_strdup: |%s|\n   strdup: |%s|\n\n", (ft = ft_strdup(src0)), (sys = strdup(src0)));
	if (strcmp(sys, ft) != 0)
		error("zero str");
	free(sys);
	free(ft);

	src0 = "short";
	printf("ft_strdup: |%s|\n   strdup: |%s|\n\n", (ft = ft_strdup(src0)), (sys = strdup(src0)));
	if (strcmp(sys, ft) != 0)
		error("short str");
	free(sys);
	free(ft);

	src0 = "llooooooooooooooooooooooooooooooooooooong!";
	printf("ft_strdup: |%s|\n   strdup: |%s|\n\n", (ft = ft_strdup(src0)), (sys = strdup(src0)));
	if (strcmp(sys, ft) != 0)
		error("long str");
	free(sys);
	free(ft);
	printf("\n\e[32m[+] SUCCESS: ft_strdup\e[0m\n\n");
}
