/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:15:52 by kmills            #+#    #+#             */
/*   Updated: 2019/03/20 05:18:25 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check6or8big(u_int64_t u, int l, int n, int size)
{
	int			i;
	u_int64_t	imax;

	imax = 1;
	imax = imax << 63;
	i = 0;
	/* size != only 8 */size = 8;
	while (i < 64)
	{
		if (((imax >> i) & u))
		{
			if (((imax >> (i - 1)) & u) && ((i) % size != 0))
				n++;
			if (((imax >> (i + 1)) & u) && ((i + 1) % size != 0))
				n++;
			if (((imax >> (i - size)) & u))
				n++;
			if (((imax >> (i + size)) & u))
				n++;
		}
		i++;
	}
	if (!(n == 8 || n == 6))
		return (0);

	return (1);
}
