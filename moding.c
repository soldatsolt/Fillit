/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:15:52 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 05:05:01 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check6or8big(u_int64_t u, int l, int n, int size)
{
	int			i;
	u_int64_t	imax;

	l = size;
	imax = 1;
	imax = imax << 63;
	i = 0;
	///* size != only 8 */size = 8;
	while (i < 64)
	{
		if (((imax >> i) & u))
		{
			if (((imax >> (i - 1)) & u) && ((i) % 8 != 0))
				n++;
			if (((imax >> (i + 1)) & u) && (i != l))
				n++;
			else
				l = l + 8;
			if (((imax >> (i - 8)) & u))
				n++;
			if (((imax >> (i + 8)) & u))
				n++;
		}
		i++;
	}
	if (!(n == 8 || n == 6))
		return (0);
	return (1);
}

u_int64_t	makegran(u_int64_t gran, int size)
{
	int			i;
	u_int64_t	imax;
	int			k;

	ft_bzero(&gran, 8);
	imax = 1;
	imax = imax << 63;
	i = 0;
	k = size;
	while (i < size * 8)
	{
		if (i == k)
		{
			i = i + 8 - size;
			k = k + 8;
			continue ;
		}
		else
			gran |= imax >> i;
		i++;
	}
	return (gran);
}
