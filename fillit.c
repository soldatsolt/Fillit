/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:22 by kmills            #+#    #+#             */
/*   Updated: 2019/03/01 19:21:45 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		kolvoresh(int o, int i, int n, unsigned short int *u);

int		main(int argc, char **argv)
{
	int		o;
	int		r;

	if (argc > 1)
		o = open(argv[1], O_RDONLY);
	r = kolvoresh(o, 0, 0, NULL);
	printf("___%i___\n", r);
	return (0);
}
