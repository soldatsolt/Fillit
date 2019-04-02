/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normichno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 00:37:19 by kmills            #+#    #+#             */
/*   Updated: 2019/04/03 00:35:23 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	{
		if (summ[j + 1] & (u & 0x0F00) >> (i - 4))
			return (0);
	}
	return (normik(summ, u, i, j));
}

int			normik(u_int16_t *summ, u_int16_t u, int i, int j)
{
	if (8 - i > 0)
	{
		if (summ[j + 2] & (u & 0x00F0) << (8 - i))
			return (0);
	}
	else
	{
		if (summ[j + 2] & (u & 0x00F0) >> (i - 8))
			return (0);
	}
	if (12 - i > 0)
	{
		if (summ[j + 3] & (u & 0x000F) << (12 - i))
			return (0);
	}
	else
	{
		if (summ[j + 3] & (u & 0x000F) >> (i - 12))
			return (0);
	}
	return (1);
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
