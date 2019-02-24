/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:49:30 by qhetting          #+#    #+#             */
/*   Updated: 2019/02/24 18:26:14 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "filit.h"

void print(char *tetra)
{
	int x;
	int y;
	int a;
	int intern;

	x = find_x_r_offset(tetra);
	y = find_y_r_offset(tetra);
	a = 0;
	intern = 0;
	y = y > x ? y : x;
	x = y > x ? y : x;

	while (a < 16)
	{
		if (_x(a) <= x && _y(a) <= y)
		{
			if (intern && intern % (x + 1) == 0)
				ft_putchar('\n');
			if (tetra[a] == 1)
				write(1, "A", 1);
			if (tetra[a] == 0)
				write(1, ".", 1);
			intern++;
		}
		a++;
	}
}

int main(int argc, char *argv[])
{
	int fl;
	char *tetraminos;
	int cnt;

	cnt = 0;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (10);
	}
	fl = open(argv[1], O_RDONLY);
	if (!((pre_parse(fl, &tetraminos)) && validate(&tetraminos)))
	{
		ft_putstr("error\n");
		free(tetraminos);
		return (123);
	}
	char **pr = generate_arrays(&tetraminos);
	fl = 0;
	while (++fl < 27)
		cnt += pr[fl] ? 1 : 0;
	if (cnt == 1)
	{
		print(pr[1]);
		cnt = -1;
		while (++cnt < 28)
			free(pr[cnt]);
		free(pr);
		return (1);
	}
//	for (int i = 0; i < 27; ++i)
//	{
//		if (pr[i] != NULL)
//			for (int j = 0; j < 17; ++j)
//			{
//				if (j % 4 == 0)
//					write(1, "\n", 1);
//
//				if (j != 16)
//				{
//					char c;
//					c = pr[i][j] + (char) '0';
//					write(1, &c, 1);
//				} else
//					write(1, &(pr[i][j]), 1);
//			}
//	}
	write(1, "\n", 1);
	ft_fillit(pr, cnt);
	ft_gc(&g_memaloced);
	return (0);
}

