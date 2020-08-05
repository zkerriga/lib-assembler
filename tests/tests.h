/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:59:30 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 11:30:16 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <string.h>
# include <strings.h>
# include <fcntl.h>
# include <unistd.h>
# include <ctype.h>
# include <stdio.h>

# include "libasm.h"

void	error(char *output);

void	test_ft_strlen(void);
void	test_ft_strcpy(void);
void	test_ft_strcmp(void);
void	test_ft_write(void);
void	test_ft_read(void);
void	test_ft_strdup(void);
void	test_ft_isspace(void);
void	test_ft_tolower(void);
void	test_get_digit(void);
void	test_ft_atoi_base(void);
void	test_ft_lstnew(void);
void	test_ft_list_push_front(void);
void	test_ft_list_sort(void);
void	test_ft_list_remove_if(void);

#endif
