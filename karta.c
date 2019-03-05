/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:16:24 by kmills            #+#    #+#             */
/*   Updated: 2019/03/05 07:35:42 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long long int	karta(unsigned short int *u, int l)
{
	int						min_size;
	unsigned long long int	mapa;

	mapa = 0;
	min_size = min_map_size(l * 4);
	mapa = mod_karta(u, mapa, min_size);
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

unsigned long long int	mod_karta(unsigned short int *u, unsigned long long\
	int mapa, int min_size)
{
	unsigned long long int imax;

	imax = 1;
	imax = imax << 63;
	// printf("><%llu><\n", imax);
	mapa = u[0];
	mapa = mapa << 48;
	printf("><%llu><\n", mapa);
	return (mapa);
}

