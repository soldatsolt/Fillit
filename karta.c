/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/19 03:36:32 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

u_int64_t	karta(unsigned short int *u, int l)
{
	int			min_size;
	u_int64_t	mapa;
	int			k;
	u_int64_t	*prav_tetr;

	prav_tetr = (u_int64_t *)malloc(sizeof(u_int64_t) * l);
	bzero(prav_tetr, l * 8);
	k = 0;
	mapa = 0;
	min_size = min_map_size(l * 4);
	while (k < l)
	{
		prav_tetr[k] = mod_karta(u[k], mapa, min_size);
		mapa |= prav_tetr[k];
		k++;
	}
	printf("><%llu><\n", mapa);
	naris(mapa);
	naris_mass(mapa, 0, prav_tetr, l);
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

u_int64_t	mod_karta(unsigned short int u, u_int64_t mapa, int min_size)
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
	return (zapoln_kartu(mapa, 0, llu, min_size));
}

u_int64_t	zapoln_kartu(u_int64_t mapa, int i, u_int64_t llu, int min_size)
{
	u_int64_t gran;

	gran = ((u_int64_t)255 << ((7 - min_size) * 8));
	gran |= ((u_int64_t)72340172838076673 << ((7 - min_size)));
	naris(gran);
	while ((mapa ^ (llu >> i)) != ((mapa | (llu >> i))))
	{
		if ((gran ^ (llu >> i)) != ((gran | (llu >> i))))

		i++;
	}
	mapa |= (llu >> i);
	naris(mapa);
	return (mapa);
}

void		naris_mass(u_int64_t mapa, int k, u_int64_t *prav_tetr, int l)
{
	int			i;
	u_int64_t	imax;

	i = 0;
	imax = 1;
	imax = imax << 63;
	while (i < 64)
	{
		if (((imax >> i) & mapa))
		{
			while (!((imax >> i) & prav_tetr[k]))
				k++;
			printf("%c", (65 + k));
			k = 0;
		}
		else
			printf(".");
		i++;
		if ((i + 1) % 8 == 1)
			printf("\n");
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
