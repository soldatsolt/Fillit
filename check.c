/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:52:50 by kmills            #+#    #+#             */
/*   Updated: 2019/03/20 03:36:39 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	kolvoreshvstroke(char *s)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '#')
			n++;
		if (!(s[i] == '#' || s[i] == '.'))
			n = 10;
		i++;
	}
	return (n);
}

int	tetr_check(u_int16_t *u, int l, int k)
{
	int		i;

	i = 0;
	while (i < l / 16)
	{
		if (!(check6or8(u[i], l, 0)))
			k = 0;
		i++;
	}
	i = 0;
	while (i < l / 16)
	{
		while (dvizh_vverkh(&u[i], 0, 0))
			i = i;
		i++;
	}
	i = 0;
	while (i < l / 16)
	{
		while (dvizh_vlevo(&u[i], 0, 0))
			i = i;
		i++;
	}
	return ((k) ? 1 : 0);
}

int	check6or8(u_int16_t u, int l, int n)
{
	int		i;

	i = 0;
	while (i < 16 && n <= 8)
	{
		if (((32768 >> i) & u))
		{
			if (((32768 >> (i - 1)) & u) && ((i) % 4 != 0))
				n++;
			if (((32768 >> (i + 1)) & u) && ((i + 1) % 4 != 0))
				n++;
			if (((32768 >> (i - 4)) & u))
				n++;
			if (((32768 >> (i + 4)) & u))
				n++;
		}
		i++;
	}
	if (!(n == 8 || n == 6))
		return (0);
	return (1);
}

int	dvizh_vverkh(u_int16_t *u, int i, int n)
{
	while (i < 4)
	{
		if (((32768 >> i) & *u))
			n = 1;
		i++;
	}
	if (!n)
		*u = *u << 4;
	i = 0;
	while (i < 4)
	{
		if (((32768 >> i) & *u))
			n = 3;
		i++;
	}
	return ((n > 2) ? 0 : 1);
}

int	dvizh_vlevo(u_int16_t *u, int i, int n)
{
	while (i < 16)
	{
		if (((32768 >> i) & *u))
			n = 1;
		i = i + 4;
	}
	if (!n)
		*u = *u << 1;
	i = 0;
	while (i < 16)
	{
		if (((32768 >> i) & *u))
			n = 3;
		i = i + 4;
	}
	return ((n > 2) ? 0 : 1);
}
