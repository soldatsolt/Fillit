/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:22 by kmills            #+#    #+#             */
/*   Updated: 2019/03/04 17:18:42 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int					kolvoresh(int o, int i, int n, unsigned short int *u)
{
	char	*str;
	char	*karta;

	karta = ft_strnew(1);
	while (get_next_line(o, &str))
	{
		n = n + kolvoreshvstroke(str);
		if (!((ft_strlen(str) == 4 && n < 5) || (n == 4 && !ft_strlen(str))))
			return (0);
		if (ft_strlen(str))
			i++;
		if (ft_strlen(str) == 0)
		{
			n = 0;
			if (i != 4)
				return (0);
			i = 0;
		}
		karta = ft_strrejoin(karta, str);
	}
	u = tetramina(karta, 0, 0, ft_strlen(karta));
	free(karta);
	return (((i == 4) && u) ? 1 : 0);
}

unsigned short int	*tetramina(char *s, int k, int sym, int l)
{
	int					i;
	unsigned short int	*u;

	u = (unsigned short int *)malloc(sizeof(*u) * (l / 16));
	ft_bzero(u, (l / 8));
	i = 0;
	while (k < (l / 16))
	{
		while (i < 16)
		{
			if (s[sym] == '#')
			{
				u[k] |= 1 << (16 - i - 1);
			}
			i++;
			sym++;
		}
		printf("+%i+\n", u[k]);
		k++;
		i = 0;
	}
	return ((tetr_check(u, l, 1)) ? u : NULL);
}
