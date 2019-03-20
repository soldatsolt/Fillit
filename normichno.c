/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normichno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 00:37:19 by kmills            #+#    #+#             */
/*   Updated: 2019/03/21 00:37:34 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ijsdijs(u_int64_t imax, u_int64_t *tetr, int k, int i)
{
	while (!((imax >> i) & tetr[k]))
		k++;
	ft_putchar(65 + k);
	k = 0;
}

void		asdfefe(int *i, int max, int *ki)
{
	*i = *i + 8 - max;
	write(1, "\n", 1);
	*ki = *ki + 8;
}
