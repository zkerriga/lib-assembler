/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:49:00 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 10:54:51 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_read(void)
{
	int		fd;
	int		ret[2];
	char	buf[30];

	errno = 0;
	fd = open("main.c", O_RDONLY);
	bzero(buf, sizeof(buf));
	ret[0] = read(fd, buf, 20);
	buf[20] = '\0';
	printf("fd == %d, ret == %d, buf == %s, errno == %d\n", fd, ret[0], buf, errno);
	close(fd);

	errno = 0;
	fd = open("main.c", O_RDONLY);
	bzero(buf, sizeof(buf));
	ret[1] = ft_read(fd, buf, 20);
	buf[20] = '\0';
	printf("fd == %d, ret == %d, buf == %s, errno == %d\n\n", fd, ret[1], buf, errno);
	close(fd);
	if (ret[0] != ret[1])
		error("normal read");

	errno = 0;
	fd = open("-1", O_RDONLY);
	bzero(buf, sizeof(buf));
	ret[0] = read(fd, buf, 20);
	buf[20] = '\0';
	printf("fd == %d, ret == %d, buf == %s, errno == %d\n", fd, ret[0], buf, errno);

	errno = 0;
	fd = open("-1", O_RDONLY);
	bzero(buf, sizeof(buf));
	ret[1] = ft_read(fd, buf, 20);
	buf[20] = '\0';
	printf("fd == %d, ret == %d, buf == %s, errno == %d\n\n", fd, ret[1], buf, errno);
	if (ret[0] != ret[1])
		error("fake read");
	printf("\n\e[32m[+] SUCCESS: ft_read\e[0m\n\n");
}
