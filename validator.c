/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 21:55:09 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/23 18:11:30 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "filit.h"

int g_steps_counter = 0;
int g_sharp_cntr = 0;

int pre_parse(int fd, char **tetraminos) {
    char *str;
    size_t lines;
    char ptr[16];
    size_t i;

    str = read_file(fd);
    lines = (size_t) count_symbol(str, '\n');
    if (lines % 5 != 0)
        return (0);
    if (!is_req_symbols(&str))
        return (0);
    remove_symbols(&str, '\n');
    if (ft_strlen(str) % 16 != 0)
        return 0;
    lines = (size_t) -16;
    i = (size_t) str;
    while ((lines += 16) < ft_strlen(str)) {
        ft_strncpy(ptr, str, 16);
        if (count_symbol(ptr, '#') != 4)
            return (0);
        str += 16;
    }
    *tetraminos = (char *) i;
    return (1);
}

//int validate(char **tet_inpt) {
//    char *str;
//    char tetra[17];
//    size_t i;
//    int j;
//    int sharp_cntr;
//
//    sharp_cntr = 0;
//
//    tetra[16] = 0;
//    i = (size_t) -16;
//    str = *tet_inpt;
//    while ((j += 16) < ft_strlen(str)) {
//        ft_strncpy(tetra, str, 16);
//        i = 0;
//
//            i++;
//        }
//        str += 16;
//    }
//
//
//}
char *crop(char **tetramino) {
    size_t i;
    int crop_flag;
    char temp[17];

    ft_bzero(temp,16);
    ft_memcpy(temp, *tetramino, 16);
    temp[16] = 0;
    i = 0;
    if (temp[i] == '#' || temp[i + LOWER] == '#' || temp[i + 1] == '#' || temp[i + LOWER + 1] == '#')
        crop_flag = LEFT_UP;
    i = 3;
    if (temp[i] == '#' || temp[i + LOWER] == '#' || temp[i - 1] == '#' || temp[i + LOWER - 1] == '#')
        crop_flag = RIGHT_UP;
    i = 12;
    if (temp[i] == '#' || temp[i + HIGHER] == '#' || temp[i + 1] == '#' || temp[i + HIGHER + 1] == '#')
        crop_flag = LEFT_DOWN;
    if (temp[i] == '#' || temp[i + HIGHER] == '#' || temp[i - 1] == '#' || temp[i + HIGHER - 1] == '#')
        crop_flag = RIGHT_DOWN;

}

char **generate_arrays(char **tet_inpt) {
    char size;
    char **tetraminos;
    int i;

    size = (char) (ft_strlen(*tet_inpt) / 16);
    tetraminos = malloc(sizeof(char *) * size);
    i = 0;
    while (size--) {
        tetraminos[i] = ft_memalloc(17);
        i++;
    }
    size = (char) (ft_strlen(*tet_inpt) / 16);
    i = 0;
    while (size--) {
        tetraminos[i] = ft_memcpy(tetraminos[i], *tet_inpt, 16);
        tetraminos[i][16] = (char) ('A' + i);
        *tet_inpt += 16;
        i++;
    }
    return (tetraminos);
}

