/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naris.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:10:02 by kmills            #+#    #+#             */
/*   Updated: 2019/03/20 00:11:34 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		naris_mass(u_int64_t mapa, int k, u_int64_t *tetr, int l)
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
			while (!((imax >> i) & tetr[k]))
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

u_int64_t	summis(u_int64_t *tetr, int k, u_int64_t summ)
{
	int i;

	i = 0;
	while (i < k)
	{
		summ |= tetr[i];
		i++;
	}
	return (summ);
}