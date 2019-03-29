/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/30 01:33:55 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		karta(u_int16_t *u, int l)
{
	int			k;
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
	tetr = doit(tetr, l, 0, 0);
	t = (t_koor *)malloc(sizeof(t_koor) * l);
	t = makekoor(t, tetr, l, 0);

	summ = summis(tetr, l);

	naris_mass(summ, t, l);
}

t_tetr		*doit(t_tetr *tetr, int l, int k, int i)
{
	tetr[k].i = i;
	while (k < l)
	{
		tetr[k] = dodvizh(tetr, k, tetr[k].i);
		if (tetr[k].j == 51)
		{
			tetr[k] = g_nach8[k];
			tetr = doit(tetr, l, k - 1, (tetr[k - 1].i + 1));
		}
		if (tetr[k].j == 52)
		{
			g_size++;
			tetr = doit(g_nach8, l, 0, 0);
		}
		k++;
	}
	return (tetr);
}

t_tetr		dodvizh(t_tetr *tetr, int k, int i)
{
	u_int16_t *summ;

	tetr[k].i = i;
	summ = summis(tetr, k);
	while (tetr[k].j <= g_size - tetr[k].h)
	{
		while (tetr[k].i <= g_size - tetr[k].w)
		{
			if (norm_li(summ, tetr[k].u, tetr[k].i, tetr[k].j))
			{
				free(summ);
				return (tetr[k]);
				tetr[k].j = 41;
				break ;
			}
			tetr[k].i++;
		}
		tetr[k].j++;
		tetr[k].i = 0;
	}
	if (tetr[k].j != 42 && k == 0)
	{
		free(summ);
		tetr[k].j = 52;
		return (tetr[k]);
	}
	if (tetr[k].j != 42)
	{
		free(summ);
		tetr[k].j = 51;
		return (tetr[k]);
	}
	free(summ);
	return (tetr[k]);
}


