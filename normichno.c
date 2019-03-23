/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normichno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 00:37:19 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 02:52:27 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		asdfefe(int *i, int max, int *ki)
{
	*i = *i + 8 - max;
	write(1, "\n", 1);
	*ki = *ki + 8;
}

void		ijsdijs(u_int64_t imax, u_int64_t *tetr, int k, int i)
{
	while (!((imax >> i) & tetr[k]))
		k++;
	ft_putchar(65 + k);
	k = 0;
}

void		narisgrantoo(u_int64_t llu, u_int64_t gran)
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
		if (((imax >> i) & gran) && !((imax >> i) & llu))
			write(1, "#", 1);
		else if (((imax >> i) & llu))
			write(1, "*", 1);
		else
			write(1, ".", 1);
		i++;
		if ((i + 1) % 8 == 1)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
}