#include "filit.h"

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

