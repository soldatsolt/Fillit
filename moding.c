/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:15:52 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 06:50:35 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check6or8big(u_int64_t u, int l, int n, int size)
{
	int			i;

	l = size;
	if (size == 8)
		return (checkif8(u, 0, 0));
	i = -1;
	while (++i < size * 8)
		if (((g_imax >> i) & u))
		{
			if (((g_imax >> (i - 1)) & u) && ((i) % 8 != 0))
				n++;
			if (((g_imax >> (i + 1)) & u) && (i != l))
				n++;
			else if (i == l)
				l = l + 8;
			if (((g_imax >> (i - 8)) & u))
				n++;
			if (((g_imax >> (i + 8)) & u))
				n++;
		}
	if (!(n == 8 || n == 6))
		return (0);
	return (1);
}

u_int64_t	makegran(u_int64_t gran, int size)
{
	int			i;
	int			k;

	ft_bzero(&gran, 8);
	g_imax = 1;
	g_imax = g_imax << 63;
	i = 0;
	k = size;
	while (i < size * 8)
	{
		if (i == k)
		{
			i = i + 8 - size;
			k = k + 8;
			continue ;
		}
		else
			gran |= g_imax >> i;
		i++;
	}
	return (gran);
}

int			checkif8(u_int64_t u, int i, int n)
{
	while (i < 64)
	{
		if (((g_imax >> i) & u))
		{
			if (((g_imax >> (i - 1)) & u) && ((i) % 8 != 0))
				n++;
			if (((g_imax >> (i + 1)) & u) && ((i + 1) % 8 != 0))
				n++;
			if (((g_imax >> (i - 8)) & u))
				n++;
			if (((g_imax >> (i + 8)) & u))
				n++;
		}
		i++;
	}
	if (!(n == 8 || n == 6))
		return (0);
	return (1);
}
