/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:15:52 by kmills            #+#    #+#             */
/*   Updated: 2019/03/30 03:14:52 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*maketetrstruct(t_tetr *tetr, u_int16_t *u, int l)
{
	int k;

	k = 0;
	while (k < l)
	{
		tetr[k].u = u[k];
		tetr[k].i = 0;
		tetr[k].j = 0;
		tetr[k].k = k;
		tetr[k].w = widt(u[k]);
		tetr[k].h = high(u[k]);
		k++;
	}
	return (tetr);
}

t_koor		*makekoor(t_koor *t, t_tetr *tetr, int l, int k)
{
	int f;
	int i;
	
	i = 0;
	f = 0;
	while (k < l)
	{
		while (f < 4 && i < 16)
		{
			if (((32768 >> i) & tetr[k].u))
			{
				if (f == 0)
				{
					t[k].i1 = tetr[k].i + i % 4;
					t[k].j1 = tetr[k].j + i / 4;
				}
				if (f == 1)
				{
					t[k].i2 = tetr[k].i + i % 4;
					t[k].j2 = tetr[k].j + i / 4;
				}
				if (f == 2)
				{
					t[k].i3 = tetr[k].i + i % 4;
					t[k].j3 = tetr[k].j + i / 4;
				}
				if (f == 3)
				{
					t[k].i4 = tetr[k].i + i % 4;
					t[k].j4 = tetr[k].j + i / 4;
				}
				f++;
			}
			i++;
		}
		i = 0;
		f = 0;
		k++;
	}
	return (t);
}

u_int16_t	*vstav_v_summ(u_int16_t *summ, u_int16_t u, int i, int j)
{
	summ[j] |= (u & 0xF000) >> i;
	if (4 - i > 0)
		summ[j + 1] |= (u & 0x0F00) << (4 - i);
	else
		summ[j + 1] |= (u & 0x0F00) >> (i - 4);
	if (8 - i > 0)
		summ[j + 2] |= (u & 0x00F0) << (8 - i);
	else
		summ[j + 2] |= (u & 0x00F0) >> (i - 8);
	if (12 - i > 0)
		summ[j + 3] |= (u & 0x000F) << (12 - i);
	else
		summ[j + 3] |= (u & 0x000F) >> (i - 12);
	return (summ);
}
