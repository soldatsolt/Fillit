/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:10:02 by kmills            #+#    #+#             */
/*   Updated: 2019/03/30 04:43:47 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		naris_mass(u_int16_t *summ, t_koor *t, int l)
{
	int	i;
	int	j;
	int k;

	j = 0;
	k = 0;
	i = 0;
	while (j < g_size)
	{
		while (i < g_size)
		{
			if ((32768 >> i) & summ[j])
			{
				while (k < l)
				{
					if ((t[k].i1 == i && t[k].j1 == j) || (t[k].i2 == i && t[k].j2 == j) || (t[k].i3 == i && t[k].j3 == j) || (t[k].i4 == i && t[k].j4 == j))
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
			i++;
		}
		write(1, "\n", 1);
		j++;
		i = 0;
	}
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
	while (!((((u_int64_t)4369 << (wid))) & (u)))
		wid++;
	wid = 4 - wid;
	return (wid);
}