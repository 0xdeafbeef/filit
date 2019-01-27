/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:54:29 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/24 16:40:58 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FILIT_FILIT_H
# define FILIT_FILIT_H
#include "libft/libft.h"
#include "libft/get_next_line.h"

#define DOWN 4

char **generate_arrays(char **tet_inpt);
char *read_file(int fd);
int is_req_symbols(char **ch);
int ft_count_symbol(char *str, char ch);
int pre_parse(int fd, char **tetraminos);
void remove_symbols(char **s, char c);
int validate(char **tet_inpt,int flag);
int validate_tetra(char **tetramino) ;

#endif //FILIT_FILIT_H
