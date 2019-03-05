#include "filit.h"

int find_x_offset(char *tetra)
{
	int x;
	int y;

	x = 0;

	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetra[x + (y * WIDTH)] == '#')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

int find_y_offset(char *tetra)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetra[x + (y * WIDTH)] == '#')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}


char *crop(char **tet_inpt)
{
	int pos;
	char *tetra;
	int x_ofs;
	int y_ofs;
	char *ret;

	ret = ft_memalloc(17);
	tetra = *tet_inpt;
	x_ofs = find_x_offset(tetra);
	y_ofs = find_y_offset(tetra);
	pos = 0;
	while (pos < 16)
	{
		if (tetra[pos] == '#')
		{
			ret[((_x(pos) - x_ofs) + WIDTH * (_y(pos) - y_ofs))] = 1;
		}
		pos++;
	}
	return (ret);
}

char **generate_arrays(char **tet_inpt)
{
	unsigned char size;
	char **tetraminos;
	unsigned char i;
	char *current;
	int size_f;

	size = 27;
	tetraminos = malloc(sizeof(char *) * 28);
	while (size--)
	{
		tetraminos[size] = 0x0;
	}

	size = (unsigned char) (ft_strlen(*tet_inpt) / 16);
	i = 1;
	current = ft_memalloc(17);
	while (size--)
	{
		tetraminos[i] = ft_memalloc(17);
		i++;
	}
	size = (unsigned char) (ft_strlen(*tet_inpt) / 16);
	i = 1;
	size_f = size * 16;
	while (size--)
	{
		ft_memcpy(current, *tet_inpt, 16);
		tetraminos[i] = crop(&current);
		tetraminos[i][16] = (char) ('A' - 1 + i);
		*tet_inpt += 16;
		i++;
	}
	i = (unsigned char) (size_f / 16);
	while (++i <= 28)
		tetraminos[i] = 0x0;
	free((*tet_inpt - size_f));
	free(current);
	return (tetraminos);

}
