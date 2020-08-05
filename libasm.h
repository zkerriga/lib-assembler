/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:29:54 by zkerriga          #+#    #+#             */
/*   Updated: 2020/08/05 09:18:25 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

int		ft_isspace(int c);
int		ft_tolower(int c);
int		get_digit(char c, int base);
int		ft_atoi_base(const char *str, int str_base);


#endif
