/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:49:30 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/21 21:28:28 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "filit.h"
#include "stdbool.h"
int main(int argc, char *argv[])
{
	int fd;
	char *tetraminos;
	if (argc != 2){
		ft_putstr("usage: fillit input_file\n");
		return (10);
	}
	fd = open(argv[1], O_RDONLY);
	if(!pre_parse(fd, &tetraminos))
		ft_putstr("error\n");

	char **pr = generate_arrays(&tetraminos);
	for (int i = 0; i < 5; ++i)
		printf("%s\n", pr[i]);
	return (0);
}