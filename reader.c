/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:38:39 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/23 18:39:16 by qhetting         ###   ########.fr       */
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
	close(fd);
	return res;
}



int is_req_symbols(char **ch)
{
	char *ptr;

	ptr = *ch - 1;


	while (*(++ptr))
		if (!(*ptr == '.' || *ptr == '\n' || *ptr == '#'))
			return (0);
	return (1);
}

int ft_count_symbol(char *str, char ch)
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
