/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:13:52 by qhetting          #+#    #+#             */
/*   Updated: 2019/02/24 18:27:21 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *src)
{
	char *tmp;
	size_t l;

	l = ft_strlen(src);
	tmp = malloc(l + 1);
	ft_memcpy(tmp, src, l + 1);
	return tmp;
}
