/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/20 03:31:45 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int64_t	karta(unsigned short int *u, int l)
{
	int			min_size;
	int			k;
	u_int64_t	*tetr;
	u_int64_t	summ;

	summ = 0;
	tetr = (u_int64_t *)malloc(sizeof(u_int64_t) * l);
	bzero(tetr, l * 8);
	k = 0;
	min_size = min_map_size(l * 4);
	while (k < l)
	{
		tetr[k] = mod_karta(u[k], tetr, min_size, k);
		summ |= tetr[k];
		k++;
	}
	printf("><%llu><\n", summ);
	naris_mass(summ, 0, tetr, l);
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

u_int64_t	mod_karta(unsigned short int u, u_int64_t *tetr, int min_size, int k)
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
	return (zapoln_kartu(tetr, k, llu, min_size));
}

u_int64_t	zapoln_kartu(u_int64_t *tetr, int k, u_int64_t llu, int min_size)
{
	u_int64_t gran;
	u_int64_t tmp;
	u_int64_t mapa;
	u_int64_t i;

	i = 0;
	mapa = summis(tetr, k, (u_int64_t)0);
	gran = ((u_int64_t)255 << ((7 - min_size) * 8));
	gran |= ((u_int64_t)72340172838076673 << ((7 - min_size)));
	tmp = llu;
	while ((mapa ^ (llu >> i)) != ((mapa | (llu >> i))) || !(CH_8_6))
	{
		// if ((gran ^ (llu >> i)) != ((gran | (llu >> i))))
		// {
		// 	llu = dvig_tetr_vgran(mapa, llu, min_size, gran);
		// 	if (llu == gran)

		i++;
	}
	mapa |= (llu >> i);
	naris(llu >> i);
	if (!CH_8_6)
		printf("@@@@@@@@@\n");
	return (mapa);
}

u_int64_t	dvig_tetr_vgran(u_int64_t mapa, u_int64_t llu, int min_size, \
u_int64_t gran)
{
	int i;

	i = 0;
	while (i < min_size * 8)
	{
		if ((gran ^ (llu >> i)) == ((gran | (llu >> i))))
			return (llu >> i);
		i++;
	}
	return (llu);
}
