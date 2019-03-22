/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 01:44:04 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int64_t	karta(unsigned short int *u, int l)
{
	int			k;
	u_int64_t	*tetr;
	u_int64_t	summ;

	summ = 0;
	tetr = (u_int64_t *)malloc(sizeof(u_int64_t) * l);
	ft_bzero(tetr, l * 8);
	k = 0;
	g_size = min_map_size(l * 4);
	while (k < l)
	{
		tetr[k] = mod_karta(u[k], tetr, g_size, k);
		summ |= tetr[k];
		k++;
	}
	naris_mass(summ, 0, tetr, 0);
	return (summ);
}

int			min_map_size(int l)
{
	int	n;
	int	qw;

	n = 2;
	qw = n * n;
	while (qw < l)
	{
		n++;
		qw = n * n;
	}
	return (n);
}

u_int64_t	mod_karta(unsigned short int u, u_int64_t *tetr, int g_size, int k)
{
	u_int64_t	llu;
	int			i;
	u_int64_t	llut;
	u_int64_t	o;

	o = 1;
	llu = 0;
	i = 0;
	llut = u;
	while (i < 16)
	{
		if ((((1 << 15) >> i) & llut) && (i < 4))
			llu |= ((o << (63 - i)));
		else if ((((o << 15) >> i) & llut) && (i >= 4 && i < 8))
			llu |= ((o << (59 - i)));
		else if ((((o << 15) >> i) & llut) && (i >= 8 && i < 12))
			llu = llu + ((o << (55 - i)));
		else if ((((o << 15) >> i) & llut) && (i >= 12 && i < 16))
			llu = llu + ((o << (51 - i)));
		i++;
	}
	tetr[k] = llu;
	return (dvig_tetr_vgran(tetr, k, g_size, tetr[k])); // ТУТ МИНСАЙЗ = 7
}

u_int64_t	zapoln_kartu(u_int64_t *tetr, int k, u_int64_t llu, int min_size)
{
	u_int64_t gran;
	u_int64_t tmp;
	u_int64_t mapa;
	u_int64_t i;

	i = 0;
	mapa = summis(tetr, k, (u_int64_t)0);
	gran = makegran(gran, min_size);
	while (tetr[k] & mapa || !(CH_8_6))
	{
		tetr[k] = tetr[k] >> 1;
		if ((tetr[k] | gran) != (gran))
		{
			tmp = tetr[k];
			tetr[k] = dvig_tetr_vgran(tetr, k, min_size, gran);
			if (tetr[k] == tmp)
			{
				
			}
		}
	}
	mapa |= (tetr[k]);
	return (mapa);
}

u_int64_t	dvig_tetr_vgran(u_int64_t *tetr, int k, int g_size, \
u_int64_t tetrik)
{
	int			i;
	u_int64_t	mapa;
	u_int64_t	gran;

	i = 0;
	mapa = summis(tetr, k, (u_int64_t)0);
	gran = makegran(gran, g_size);
	tetr[k] = tetrik;
	while (i < g_size * 8)
	{
		// naris(tetr[k] >> i);
		if (((tetr[k] >> i) | gran) == (gran) && !(mapa & tetr[k] >> i)/* && CH_8_6*/)
		{
			tetr[k] = tetr[k] >> i;
			ft_putstr("VOSHLO\n");
			return (tetr[k]);
		}
		i++;
	}
	if (i == g_size * 8 && k == 0)
	{
		ft_putstr("1st\n");
		g_size++;
		return (dvig_tetr_vgran(tetr, k, g_size, (tetr[k] >> 1)));
	}
	if (i == g_size * 8)
	{
		ft_putstr("2nd\n");
		return (dvig_tetr_vgran(tetr, k - 1, g_size, tetr[k - 1]));
	}
	ft_putstr("_____________NO IF_____________\n");
	mapa |= (tetr[k]);
	return (mapa);
}
