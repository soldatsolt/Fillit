/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/26 15:53:24 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		karta(unsigned short int *u, int l)
{
	int			k;
	u_int64_t	*tetr;
	u_int64_t	summ;

	summ = 0;
	tetr = (u_int64_t *)malloc(sizeof(u_int64_t) * l);
	g_nach8 = (u_int64_t *)malloc(sizeof(u_int64_t) * l);
	ft_bzero(tetr, l * 8);
	k = -1;
	g_size = min_map_size(l * 4);
	while (++k < l)
		tetr[k] = mod_karta(u[k], tetr, k);
	k = -1;
	while (++k < l)
		g_nach8[k] = mod_karta(u[k], g_nach8, k);
	tetr = makethis(tetr, l, 0, tetr[0]);
	k = -1;
	while (++k < l)
		summ |= tetr[k];
	naris_mass(summ, 0, tetr, 0);
}

u_int64_t	*makethis(u_int64_t *tetr, int l, int k, u_int64_t tetrik)
{
	while (k < l)
	{
		tetr[k] = dvig_tetr_vgran(tetr, k, tetrik);
		if (tetr[k] == 1)
			tetr = makethis(tetr, l, k - 1, tetr[k - 1] >> 1);
		if (tetr[k] == 2)
		{
			g_size++;
			tetr = makethis(g_nach8, l, 0, g_nach8[0]);
		}
		k++;
		if (k < l)
			tetrik = g_nach8[k];
	}
	write(1, "DONE\n", 5);
	naris(tetr[0]);
	naris(tetr[1]);
	naris(tetr[2]);
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
	while (i < 64)
	{
		if (k == 2)
			naris(tetrik >> i);
		// narisgrantoo(tetrik >> i, gran);
		if (((tetrik >> i) | gran) == (gran) && !(mapa & tetrik >> i) && \
		(check6or8big((tetrik >> i), 0, 0)))
		{
			tetrik = tetrik >> i;
			return (tetrik);
		}
		i++;
	}
	if (i == 64 && k == 0)
		return (2);
	if (i == 64)
		return (1);
	mapa |= (tetrik);
	write(1, "UPS(\n", 5);
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
	return (tetr[k]);
}
