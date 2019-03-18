/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/19 00:54:36 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long long int	karta(unsigned short int *u, int l)
{
	int						min_size;
	unsigned long long int	mapa;
	int						k;

	k = 0;
	mapa = 0;
	min_size = min_map_size(l * 4);
	while (k < l)
	{
		mapa = mod_karta(u[k], mapa, min_size);
		k++;
	}
	printf("><%llu><\n", mapa);
	naris(mapa);
	return (mapa);
}

int						min_map_size(int l)
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

unsigned long long int	mod_karta(unsigned short int u, unsigned long long\
	int mapa, int min_size)
{
	unsigned long long int	imax;
	unsigned long long int	llu;
	int						i;
	unsigned long long int	llut;
	u_int64_t				o;

	o = 1;
	llu = 0;
	i = 0;
	llut = u;
	imax = 1;
	imax = imax << 63;
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
	printf(">|||<%llu>|||<\n", llu);
	naris(llu);
	i = 0;
	while ((mapa ^ (llu >> i)) != ((mapa | (llu >> i))))
		i++;
		mapa |= (llu >> i);
	return (mapa);
}

void					naris(unsigned long long int llu)
{
	char					*s;
	int						i;
	int						k;
	unsigned long long int	imax;

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
		s++;
		if ((i + 1) % 8 == 1)
			printf("\n");
	}
	printf("\n");
}
