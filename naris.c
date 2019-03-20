/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:10:02 by kmills            #+#    #+#             */
/*   Updated: 2019/03/21 02:06:52 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		naris_mass(u_int64_t mapa, int k, u_int64_t *tetr, int i)
{
	u_int64_t	imax;
	int			max;
	int			ki;

	max = prav_razm(mapa);
	imax = 1;
	imax = imax << 63;
	ki = max;
	while (i < max * 8)
	{
		if (i == ki && max != 8)
		{
			asdfefe(&i, max, &ki);
			continue ;
		}
		if (((imax >> i) & mapa))
		{
			ijsdijs(imax, tetr, k, i);
		}
		else
			write(1, ".", 1);
		i++;
		if ((i) % 8 == 0)
			write(1, "\n", 1);
	}
}

void		naris(u_int64_t llu)
{
	int			i;
	int			k;
	u_int64_t	imax;

	imax = 1;
	imax = imax << 63;
	k = 0;
	i = 0;
	while (i < 64)
	{
		if (((imax >> i) & llu))
			write(1, "#", 1);
		else
			write(1, ".", 1);
		i++;
		if ((i + 1) % 8 == 1)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

u_int64_t	summis(u_int64_t *tetr, int k, u_int64_t summ)
{
	int i;

	i = 0;
	while (i < k)
	{
		summ |= tetr[i];
		i++;
	}
	return (summ);
}

u_int64_t	uvel_gran(u_int64_t gran)
{
	u_int64_t	i;
	u_int64_t	imax;

	imax = 1;
	imax = imax << 63;
	i = 0;
	while (!((imax >> i) & (gran)))
		i++;
	i++;
	gran = 0;
	gran = ((u_int64_t)255 << ((7 - i) * 8));
	gran |= ((u_int64_t)72340172838076673 << ((7 - i)));
	return (gran);
}

int			prav_razm(u_int64_t mapa)
{
	int			hzi;
	int			hzj;

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
