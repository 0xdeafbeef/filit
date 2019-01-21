/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:55:09 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/21 22:31:23 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "filit.h"

int pre_parse(int fd, char **tetraminos)
{
	char *str;
	int lines;
	char *ptr;
	int i;
	str = read_file(fd);
	lines = count_symbol(str, '\n');
	if (lines % 5 != 0)
		return (0);
	if (!check(&str))
		return (0);
	remove_symbols(&str, '\n');
	i = 0;
	ptr = str;
	while (*(ptr++))
		if (*ptr == '#')
			i++;

	if (i != (lines - 1) * 4)
		return (0);
	*tetraminos = str;
	return (1);
}

char **generate_arrays(char **tet_inpt)
{
	char size;
	char **tetraminos;
	int i;

	size = (char) (ft_strlen(*tet_inpt) / 16);
	tetraminos = malloc(sizeof(char *) * size);
	i = 0;
	while (size--)
	{
		tetraminos[i] = ft_memalloc(17);
		i++;
	}
	size = (char) (ft_strlen(*tet_inpt) / 16);
	i = 0;
	while (size--)
	{
		tetraminos[i] = ft_memcpy(tetraminos[i], *tet_inpt, 16);
		tetraminos[i][16] = (char) ('A' + i);
		*tet_inpt += 16;
		i++;
	}
	return (tetraminos);
}

