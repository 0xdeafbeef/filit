/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:55:09 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/27 18:19:53 by qhetting         ###   ########.fr       */
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



int _x(int pos)
{
	return (pos % 4);
}

int _y(int pos)
{
	return (pos / 4);
}

/*
_y(pos) > 0 && _y(pos) < 4 && _x(pos) > 0 && _x(pos) < 4
 */
int check_1(char *tetr, int pos)
{
	int sharps;

	sharps = 0;

	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

//x ==0
int check_2(char *tetr, int pos)
{
	int sharps;

	sharps = 0;

	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	return (sharps);
}

int check_3(char *tetr, int pos)
{
	int sharps;

	sharps = 0;

	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int check_4(char *tetr, int pos)
{
	int sharps;

	sharps = 0;

	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int check_5(char *tetr, int pos)
{
	int sharps;

	sharps = 0;

	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos + DOWN] == '#')
		sharps++;
	return (sharps);
}

int check_6(char *tetr, int pos)
{
	int sharps;

	sharps = 0;

	if (tetr[pos + DOWN] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int check_7(char *tetr, int pos)
{
	int sharps;

	sharps = 0;

	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int check_8(char *tetr, int pos)
{
	int sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos + 1] == '#')
		sharps++;
	return (sharps);
}

int check_9(char *tetr, int pos)
{
	int sharps;

	sharps = 0;
	if (tetr[pos + UP] == '#')
		sharps++;
	if (tetr[pos - 1] == '#')
		sharps++;
	return (sharps);
}

int get_flag(int pos, char *tetra)
{
	int flag;
	if (_y(pos) > 0 && _y(pos) < 4)
	{
		if (_x(pos) > 0 && _x(pos) < 4)
			flag = check_1(tetra, pos);
		else if (_x(pos) == 0)
			flag = check_2(tetra, pos);
		else
			flag = check_3(tetra, pos);
	} else if (_y(pos) == 0)
	{
		if (_x(pos) > 0 && _x(pos) < 4)
			flag = check_4(tetra, pos);
		else if (_x(pos) == 0)
			flag = check_5(tetra, pos);
		else
			flag = check_6(tetra, pos);
	} else
	{
		if (_x(pos) > 0 && _x(pos) < 4)
			flag = check_7(tetra, pos);
		else if (_x(pos) == 0)
			flag = check_8(tetra, pos);
		else
			flag = check_9(tetra, pos);
	}
	return (flag);
}

int validate_tetra(char **tetramino)
{
	int pos;
	int sharp_count;
	char *tetra;
	int flag;

	flag = 0;
	tetra = *tetramino;
	pos = 0;
	sharp_count = pos;
	while (pos < 16)
	{
		if (tetra[pos] == '#' && sharp_count < 4)
			flag += get_flag(pos, tetra);
		pos++;
	}
	return ((flag >= 6 && flag <= 8) ? 1 : 0);
}

int validate(char **tetra)
{
	int i;
	char *cut;
	i = 0;

	cut = malloc(17);
	cut[16] = 0;
	while (i != ft_strlen(*tetra))
	{
		ft_memcpy(cut, (i + *(tetra)), 16);
		if (!validate_tetra(&cut))
			return 0;
		i += 16;
	}
	free(cut);
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
/*
0x23 #
0x2E .
 */

