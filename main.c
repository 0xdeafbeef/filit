/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:49:30 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/27 20:13:08 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "filit.h"

int main(int argc, char *argv[])
{
	int fl;
	char *tetraminos;
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (10);
	}
	fl = open(argv[1], O_RDONLY);
	if (!((pre_parse(fl, &tetraminos)) && validate(&tetraminos)))
	{
		ft_putstr("error\n");
		return (123);
	}
	char **pr = generate_arrays(&tetraminos);



	return (0);
}