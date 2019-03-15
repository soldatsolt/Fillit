/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/15 19:50:30 by kmills           ###   ########.fr       */
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
		mapa = mod_karta(u[k], mapa, min_size);//tyt poka 64 bita vseg0
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

	imax = 1;
	i = 0;
	imax = imax << 63;
	llu = u;
	// printf("><%llu><\n", imax);
	while (((mapa ^ llu << (48 - i)) != ((mapa | llu << (48 - i)))))
		i++;
		mapa = mapa + (llu << (48 - i));
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