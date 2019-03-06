/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/06 15:44:04 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long long int	karta(unsigned short int *u, int l)
{
	int						min_size;
	unsigned long long int	mapa;

	mapa = 0;
	min_size = min_map_size(l * 4);
	mapa = mod_karta(u[0], mapa, min_size);
	mapa = mod_karta(u[1], mapa, min_size);
	printf("><%llu><\n", mapa);
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

