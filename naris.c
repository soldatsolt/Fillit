/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:10:02 by kmills            #+#    #+#             */
/*   Updated: 2019/03/20 02:00:02 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		naris_mass(u_int64_t mapa, int k, u_int64_t *tetr, int l)
{
	int			i;
	u_int64_t	imax;
	int			max;

	max = prav_razm(mapa);
	i = 0;
	imax = 1;
	imax = imax << 63;
	while (i < max * 8)
	{
		if (max != 8 && (i == max || ((((i % 8) % max) == 0) && (i > 8) && (i % 8))))
		{
			i = i + 8 - max;
			write(1, "\n", 1);
			continue ;
		}
		if (((imax >> i) & mapa))
		{
			while (!((imax >> i) & tetr[k]))
				k++;
			ft_putchar(65 + k);
			k = 0;
		}
		else
			write(1, ".", 1);
		i++;
		if ((i + 1) % 8 == 1)
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
			printf("#");
		else
			printf(".");
		i++;
		if ((i + 1) % 8 == 1)
			printf("\n");
	}
	printf("\n");
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
