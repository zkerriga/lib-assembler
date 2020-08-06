/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:48:56 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/06 18:03:59 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_write(void)
{
	int		fd;
	ssize_t		ret;
	int		errno_tmp;
	char	*str = "Zkerriga's string\n";

	ret = ft_write(1, str, 18);
	ret += ft_write(1, &"", 1);
	ret += ft_write(1, &"\n", 1);
	ret -= write(1, str, 18);
	ret -= write(1, &"", 1);
	ret -= write(1, &"\n", 1);
	if (ret != 0)
		error("return error");

	fd = open("write.txt", O_CREAT | O_APPEND | O_WRONLY, 0755);
	ft_write(fd, str, 18);
	write(fd, str, 18);
	close(fd);

	errno = 0;
	ret = ft_write(-1, str, 18);
	printf("errno == %d\n", (errno_tmp = errno));

	errno = 0;
	write(-1, str, 18);
	printf("errno == %d\n", errno);
	if (errno_tmp != errno)
		error("not equal errno");

	errno = 0;
	fd = open("write.txt", O_WRONLY);
	ft_write(fd, str, 18);
	write(fd, str, 18);
	close(fd);
	if (errno != 0)
		error("errno wtf");
	printf("\n\e[32m[+] SUCCESS: ft_write\e[0m\n\n");
}
