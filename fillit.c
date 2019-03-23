/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:22 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 11:19:11 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int			o;
	u_int16_t	*u;

	if (argc == 2)
		o = open(argv[1], O_RDONLY);
	if (read(o, NULL, 0) < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	u = kolvoresh(o, 0, 0, NULL);
	close(o);
	if (u)
	{
		karta(u, g_len);
		free(u);
		u = NULL;
	}
	else
		write(1, "error\n", 6);
	return (0);
}

u_int16_t	*kolvoresh(int o, int i, int n, u_int16_t *u)
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
	ft_strdel(&karta);
	return (((i == 4) && u) ? u : NULL);
}

u_int16_t	*tetramina(char *s, int k, int sym, int l)
{
	int			i;
	u_int16_t	*u;

	g_len = l / 16;
	u = (u_int16_t *)malloc(sizeof(*u) * (l / 16));
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
		k++;
		i = 0;
	}
	return ((tetr_check(u, l, 1) && (g_len < 27)) ? u : NULL);
}
