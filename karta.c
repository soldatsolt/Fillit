/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/04/03 01:51:53 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		karta(u_int16_t *u, int l)
{
	t_tetr		*tetr;
	u_int16_t	*summ;
	t_koor		*t;

	summ = (u_int16_t *)malloc(sizeof(u_int16_t) * 16);
	ft_bzero(summ, 32);
	tetr = (t_tetr *)malloc(sizeof(t_tetr) * l);
	g_nach8 = (t_tetr *)malloc(sizeof(t_tetr) * l);
	tetr = maketetrstruct(tetr, u, l);
	g_nach8 = maketetrstruct(g_nach8, u, l);
	g_size = min_map_size(l);
	tetr = doit(tetr, l);
	t = (t_koor *)malloc(sizeof(t_koor) * l);
	t = makekoor(t, tetr, l, 0);
	free(summ);
	summ = summis(tetr, l);
	naris_mass(summ, t, l);
	free(summ);
	free(t);
	free(tetr);
	free(g_nach8);
}

int			fit_tetr(t_tetr *tetr, u_int16_t *summ)
{
	if (norm_li(summ, tetr->u, tetr->i, tetr->j))
	{
		summ = vstav_v_summ(summ, tetr->u, tetr->i, tetr->j);
		return (1);
	}
	return (0);
}

int			check_sqr(t_tetr *tetr, u_int16_t *summ, int k)
{
	u_int16_t	lsumm[16];

	ft_bzero(lsumm, 32);
	if (tetr[k].k == 0)
		return (1);
	ft_memcpy(lsumm, summ, 32);
	while (tetr[k].j <= (g_size - tetr[k].h))
	{
		while (tetr[k].i <= (g_size - tetr[k].w))
		{
			if (fit_tetr(&tetr[k], summ))
			{
				if (check_sqr(tetr, summ, k + 1))
					return (1);
				else
					ft_memcpy(summ, lsumm, 32);
			}
			tetr[k].i++;
		}
		tetr[k].i = 0;
		tetr[k].j++;
	}
	tetr[k].i = 0;
	tetr[k].j = 0;
	return (0);
}

t_tetr		*doit(t_tetr *tetr, int l)
{
	u_int16_t		summ[16];

	tetr[l].k = 0;
	ft_bzero(summ, 32);
	while (!(check_sqr(tetr, summ, 0)))
	{
		ft_bzero(summ, 32);
		g_size++;
	}
	return (tetr);
}
