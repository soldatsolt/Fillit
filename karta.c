/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 02:42:57 by kmills           ###   ########.fr       */
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
	g_nach8 = (u_int64_t *)malloc(sizeof(u_int64_t) * l);
	ft_bzero(tetr, l * 8);
	k = 0;
	g_size = min_map_size(l * 4);
	while (k < l)
	{
		tetr[k] = mod_karta(u[k], tetr, k);
		// naris(tetr[k]);
		k++;
	}
	k = 0;
	while (k < l)
	{
		g_nach8[k] = mod_karta(u[k], g_nach8, k);
		// naris(g_nach8[k]);
		k++;
	}
	tetr = makethis(tetr, l, 0, tetr[0]);
	k = -1;
	while (++k < l)
		summ |= tetr[k];
	naris_mass(summ, 0, tetr, 0);
	summ = 1;
	return (summ);
}

u_int64_t	*makethis(u_int64_t *tetr, int l, int k, u_int64_t tetrik)
{
	while (k < l)
	{
		// ft_putstr("K = ");
		// ft_putnbr(k);
		// ft_putchar('\n');
		// ft_putstr("l = ");
		// ft_putnbr(l);
		// ft_putchar('\n');
		tetr[k] = dvig_tetr_vgran(tetr, k, tetrik);
		if (tetr[k] == 1)
		{
			ft_putstr("1st\n");
			tetr = makethis(tetr, l, k - 1, tetr[k - 1] >> 1);
		}
		if (tetr[k] == 2)
		{
			ft_putstr("2nd\n");
			g_size++;
			tetr = makethis(g_nach8, l, 0, g_nach8[0]);
		}
		k++;
	}
	return (tetr);
}

u_int64_t	dvig_tetr_vgran(u_int64_t *tetr, int k, u_int64_t tetrik)
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
		ft_putstr("2nd\n");
		// g_size++;
		return (2);
	}
	if (i == g_size * 8)
	{
		ft_putstr("1st\n");
		return (1);
	}
	ft_putstr("_____________NO IF_____________\n");
	mapa |= (tetr[k]);
	return (mapa);
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

u_int64_t	mod_karta(unsigned short int u, u_int64_t *tetr, int k)
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
	return (tetr[k]); // ТУТ МИНСАЙЗ = 7
}

u_int64_t	zapoln_kartu(u_int64_t *tetr, int k, u_int64_t llu)
{
	u_int64_t gran;
	u_int64_t tmp;
	u_int64_t mapa;
	u_int64_t i;

	i = 0;
	mapa = summis(tetr, k, (u_int64_t)0);
	gran = makegran(gran, g_size);
	while (tetr[k] & mapa || !(CH_8_6))
	{
		tetr[k] = tetr[k] >> 1;
		if ((tetr[k] | gran) != (gran))
		{
			tmp = tetr[k];
			tetr[k] = dvig_tetr_vgran(tetr, k, gran);
			if (tetr[k] == tmp)
			{
				
			}
		}
	}
	mapa |= (tetr[k]);
	return (mapa);
}