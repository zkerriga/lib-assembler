/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:48:51 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/03 13:48:03 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

/*
** There should be tests for the library here.
*/

int	main()
{
	size_t		len = 0;
	const char	*str = "Bloody hell!";

	len = ft_strlen(str);
	printf("Len = %u\n", len);
	printf("Zero str len = %u\n", ft_strlen("\0"));
	printf("Zero str len = %u\n", ft_strlen("1"));
	printf("Zero str len = %u\n", ft_strlen("12"));
	printf("Zero str len = %u\n", ft_strlen("123"));
	printf("Zero str len = %u\n", ft_strlen("1234"));
	printf("Zero str len = %u\n", ft_strlen("12345"));
	return (0);
}
