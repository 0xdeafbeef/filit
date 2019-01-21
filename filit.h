/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:29 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/21 20:58:34 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILIT_FILIT_H
# define FILIT_FILIT_H
#include "libft/libft.h"
#include "libft/get_next_line.h"

char **generate_arrays(char **tet_inpt);
char *read_file(int fd);
int check(char **ch);
int count_symbol(char *str, char ch);
int pre_parse(int fd, char **tetraminos);
void remove_symbols(char **s, char c);

#endif //FILIT_FILIT_H
