/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:10:02 by kmills            #+#    #+#             */
/*   Updated: 2019/03/29 22:40:48 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		naris_mass(u_int16_t *summ)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < 16)
	{
		while (i < 16)
		{
			if ((32768 >> i) & summ[j])
				write(1, "#", 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
		i = 0;
	}
}

void		naris(u_int64_t llu)
{
	int			i;
	int			k;

	k = 0;
	i = 0;
	while (i < 64)
	{
		if (((g_imax >> i) & llu))
			write(1, "#", 1);
		else
			write(1, ".", 1);
		i++;
		if ((i + 1) % 8 == 1)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

u_int16_t	*summis(t_tetr *tetr, int k)
{
	int			i;
	u_int16_t	*summ;

	summ = (u_int16_t *)malloc(sizeof(u_int16_t) * 16);
	i = 0;
	while (i < k)
	{
		summ = vstav_v_summ(summ, tetr[i].u, tetr[i].i, tetr[i].j);
		i++;
	}
	return (summ);
}

u_int64_t	uvel_gran(u_int64_t gran)
{
	int			max;

	gran = makegran(gran, (prav_razm(gran) + 1));
	return (gran);
}

int			prav_razm(u_int64_t mapa)
{
	int	hzi;
	int	hzj;

	hzi = 0;
	hzj = 0;
	while (!((((u_int64_t)255 << (8 * hzj))) & (mapa)))
		hzj++;
	while (!((((u_int64_t)72340172838076673 << (hzi))) & (mapa)))
		hzi++;
	hzi = 8 - hzi;
	hzj = 8 - hzj;
	return ((hzj > hzi) ? hzj : hzi);
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