#include "filit.h"

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