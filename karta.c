/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/28 14:33:06 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		karta(u_int16_t *u, int l)
{
	int			k;
	u_int64_t	*tetr;
	u_int16_t	*summ;

	summ = (u_int16_t *)malloc(sizeof(u_int16_t) * 16);
	ft_bzero(summ, 32);
	g_size = min_map_size(l);
	summ = doit(summ, u, l);
	naris_mass(summ);
}

u_int16_t	*doit(u_int16_t *summ, u_int16_t *u, int l)
{
	int k;
	int i;
	int wid;
	int hig;
	int j;

	j = 0;
	k = 0;
	i = 0;
	while (k < l)
	{
		wid = widt(u[k]);
		hig = high(u[k]);
		if (norm_li(summ, u[k], i, j))
		{
			if (i + wid > g_size || j + hig > g_size)
			{
				j++;
				i = 0;
			}
			else
			{
				summ = vstav_v_summ(summ, u[k], i, j);
				k++;
			}
		}
		else
			i++;
	}
	return (summ);
}

u_int16_t	*vstav_v_summ(u_int16_t *summ, u_int16_t u, int i, int j)
{
	summ[j] |= (u & 0xF000) >> i;
	if (4 - i > 0)
		summ[j + 1] |= (u & 0x0F00) << (4 - i);
	else
		summ[j + 1] |= (u & 0x0F00) >> (i - 4);
	if (8 - i > 0)
		summ[j + 2] |= (u & 0x00F0) << (8 - i);
	else
		summ[j + 2] |= (u & 0x00F0) >> (i - 8);
	if (12 - i > 0)
		summ[j + 3] |= (u & 0x000F) << (12 - i);
	else
		summ[j + 3] |= (u & 0x000F) >> (i - 12);
	return (summ);
}

int			norm_li(u_int16_t *summ, u_int16_t u, int i, int j)
{
	if (summ[j] & (u & 0xF000) >> i)
		return (0);
	if (4 - i > 0)
	{
		if (summ[j + 1] & (u & 0x0F00) << (4 - i))
			return (0);
	}
	else
		if (summ[j + 1] & (u & 0x0F00) >> (i - 4))
			return(0);
	if (8 - i > 0)
	{
		if (summ[j + 2] & (u & 0x00F0) << (8 - i))
			return (0);
	}
	else
		if (summ[j + 2] & (u & 0x00F0) >> (i - 8))
			return (0);
	if (12 - i > 0)
	{
		if (summ[j + 3] & (u & 0x000F) << (12 - i))
			return (0);
	}
	else
		if (summ[j + 3] & (u & 0x000F) >> (i - 12))
			return (0);
	return (1);
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
			ft_putnbr(g_size);
			tetr = makethis(g_nach8, l, 0, g_nach8[0]);
		}
		k++;
		if (k < l)
			tetrik = g_nach8[k];
	}
	// write(1, "DONE\n", 5);
	// naris(tetr[0]);
	// naris(tetr[1]);
	// naris(tetr[2]);
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
	// ft_putnbr(g_size);
	while (i < g_size * 8)
	{
		narisgrantoo(tetrik >> i, gran);
		if (((tetrik >> i) | gran) == (gran) && !(mapa & tetrik >> i) && \
		(check6or8big((tetrik >> i), 0, 0)))
		{
			tetrik = tetrik >> i;
			return (tetrik);
		}
		i++;
	}
	if (i == g_size * 8 && k == 0)
		return (2);
	if (i == g_size * 8)
		return (1);
	mapa |= (tetrik);
	write(1, "UPS(\n", 5);
	return (mapa);
}

int			min_map_size(int l)
{
	if (l == 1)
		return (2);
	if (l == 2)
		return (3);
	if (l >= 3 && l <= 4)
		return (4);
	if (l >= 5 && l <= 6)
		return (5);
	if (l >= 7 && l <= 9)
		return (6);
	if (l >= 10 && l <= 12)
		return (7);
	if (l >= 13 && l <= 16)
		return (8);
	if (l >= 17 && l <= 20)
		return (9);
	if (l >= 21 && l <= 24)
		return (10);
	if (l >= 25 && l <= 26)
		return (11);
	return (15);
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
