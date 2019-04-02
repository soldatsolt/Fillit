/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:15:52 by kmills            #+#    #+#             */
/*   Updated: 2019/04/02 22:38:41 by kmills           ###   ########.fr       */
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
		tetr[k].k = k + 1;
		tetr[k].w = widt(u[k]);
		tetr[k].h = high(u[k]);
		k++;
	}
	return (tetr);
}

t_koor		mkoor(t_koor t, t_tetr tetr, int f, int i)
{
	if (f == 0)
	{
		t.i1 = tetr.i + i % 4;
		t.j1 = tetr.j + i / 4;
	}
	if (f == 1)
	{
		t.i2 = tetr.i + i % 4;
		t.j2 = tetr.j + i / 4;
	}
	if (f == 2)
	{
		t.i3 = tetr.i + i % 4;
		t.j3 = tetr.j + i / 4;
	}
	if (f == 3)
	{
		t.i4 = tetr.i + i % 4;
		t.j4 = tetr.j + i / 4;
	}
	return (t);
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
				t[k] = mkoor(t[k], tetr[k], f, i);
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
