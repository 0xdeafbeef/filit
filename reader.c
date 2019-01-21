/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:38:39 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/21 20:29:49 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filit.h"

char *read_file(int fd)
{
	char *redd;
	char *temp;
	char *res;

	res = ft_strnew(0);
	redd = ft_strnew(BUFF_SIZE - 1);
	while (read(fd, redd, BUFF_SIZE) > 0)
	{
		temp = ft_strdup(res);
		free(res);
		res = ft_strjoin(temp, redd);
		ft_strdel(&temp);
		ft_bzero(redd, BUFF_SIZE);
	}
	ft_strdel(&redd);
	return res;
}

void remove_symbols(char **s, char c)
{
	char *s_ptr;
	size_t size;
	char *ret;

	s_ptr = *s;
	size = 0;
	while (*s_ptr)
	{
		if (*s_ptr != c)
			size++;
		s_ptr++;
	}
	ret = ft_strnew(size);
	s_ptr = *s;
	size = (size_t) ret;
	while (**s)
	{
		if (**s != c)
		{
			*ret = **s;
			ret++;
		}
		(*s)++;
	}
	free(s_ptr);
	*s = (char *) (size);
}

int check(char **ch)
{
	char *ptr;

	ptr = *ch - 1;


	while (*(++ptr))
		if (!(*ptr == '.' || *ptr == '\n' || *ptr == '#'))
			return (0);
	return (1);
}

int count_symbol(char *str, char ch)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == ch)
			i++;
		str++;
	}
	return (i);
}
