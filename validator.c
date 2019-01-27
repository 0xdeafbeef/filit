/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:55:09 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/27 16:17:09 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "filit.h"

int g_steps_counter = 0;
int g_sharp_cntr = 0;

int pre_parse(int fd, char **tetraminos)
{
	char *str;
	size_t lines;
	char ptr[17];
	size_t i;

	str = read_file(fd);
	ptr[16] = 0;
	lines = (size_t) ft_count_symbol(str, '\n');
	if ((lines + 1) % 5 != 0)
		return (0);
	if (!is_req_symbols(&str))
		return (0);
	remove_symbols(&str, '\n');
	if (ft_strlen(str) % 16 != 0)
		return 0;
	lines = (size_t) -16;
	i = (size_t) str;
	while ((lines += 16) < ft_strlen((char *) i))
	{
		ft_strncpy(ptr, str, 16);
		if (ft_count_symbol(ptr, '#') != 4)
			return (0);
		str += 16;
	}
	*tetraminos = (char *) i;
	return (1);
}

//void	populate_valid(int i, char valid[20][15])
//{
//	while (++i < 20)
//	{
//		ft_bzero(valid[i], sizeof(valid[i]));
//	}
//	ft_strcpy(valid[0], "###...#");
//	ft_strcpy(valid[1], ".#...#..##");
//	ft_strcpy(valid[2], "#...###");
//	ft_strcpy(valid[3], "##..#...#");
//	ft_strcpy(valid[4], "###.#");
//	ft_strcpy(valid[5], "##...#...#");
//	ft_strcpy(valid[6], "..#.###");
//	ft_strcpy(valid[7], "#...#...##");
//	ft_strcpy(valid[8], "###..#");
//	ft_strcpy(valid[9], ".#..##...#");
//	ft_strcpy(valid[10], ".#..###");
//	ft_strcpy(valid[11], "#...##..#");
//	ft_strcpy(valid[12], ".##.##");
//	ft_strcpy(valid[13], "#...##...#");
//	ft_strcpy(valid[14], "##..##")
//	ft_strcpy(valid[15], "#...#...#...#");
//	ft_strcpy(valid[16], "####");
//	ft_strcpy(valid[17], ".#..##..#");
//	ft_strcpy(valid[18], "##...##");
//}



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
/*
0x23 #
0x2E .
 */

