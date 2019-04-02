/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:10:02 by kmills            #+#    #+#             */
/*   Updated: 2019/04/03 00:41:30 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_i;
int	g_j;

void		naris_mass(u_int16_t *summ, t_koor *t, int l)
{
	int k;

	g_j = 0;
	k = 0;
	g_i = 0;
	while (g_j < g_size)
	{
		while (g_i < g_size)
			narisabc(summ, t, l);
		write(1, "\n", 1);
		g_j++;
		g_i = 0;
	}
}

void		narisabc(u_int16_t *summ, t_koor *t, int l)
{
	int k;

	k = 0;
	if ((32768 >> g_i) & summ[g_j])
	{
		while (k < l)
		{
			if ((t[k].i1 == g_i && t[k].j1 == g_j) || \
			(t[k].i2 == g_i && t[k].j2 == g_j) || \
			(t[k].i3 == g_i && t[k].j3 == g_j) || \
			(t[k].i4 == g_i && t[k].j4 == g_j))
			{
				ft_putchar('A' + k);
				break ;
			}
			k++;
		}
		k = 0;
	}
	else
		write(1, ".", 1);
	g_i++;
}

u_int16_t	*summis(t_tetr *tetr, int16_t k)
{
	int16_t		i;
	u_int16_t	*summ;

	summ = (u_int16_t *)malloc(sizeof(u_int16_t) * 16);
	ft_bzero(summ, 32);
	i = 0;
	while (i < k)
	{
		summ = vstav_v_summ(summ, tetr[i].u, tetr[i].i, tetr[i].j);
		i++;
	}
	return (summ);
}

int			high(u_int16_t u)
{
	int	hig;

	hig = 0;
	while (!((((u_int16_t)15 << (4 * hig))) & (u)))
		hig++;
	hig = 4 - hig;
	return (hig);
}

int			widt(u_int16_t u)
{
	int	wid;

	wid = 0;
	while (!(((u_int16_t)4369 << (wid)) & (u)))
		wid++;
	wid = 4 - wid;
	return (wid);
}
