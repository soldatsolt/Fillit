/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:52:50 by kmills            #+#    #+#             */
/*   Updated: 2019/02/26 21:12:37 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

unsigned short int	tetramina(char *s);
char				*tetr_check(unsigned short int u);

int					kolvoreshvstroke(char *s)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == '#')
			n++;
		if (!(s[i] == '#' || s[i] == '.'))
			n = 10;
		i++;
	}
	return (n);
}

int					kolvoresh(int o)
{
	int		i;
	char	*str;
	int		n;
	char	*karta;

	i = 0;
	n = 0;
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
	printf("%i\n", tetramina(karta));
	return (i == 4 ? 1 : 0);
}

unsigned short int	tetramina(char *s)
{
	int					i;
	unsigned short int	*u;
	int					l;

	l = ft_strlen(s);
	u = (unsigned short int *)malloc(sizeof(unsigned short int) * l / 16);
	u[0] = 0;
	i = 0;
	while (i < 16)
	{
		if (s[i] == '#')
		{
			u[0] |= 1 << (16 - i - 1);
		}
		i++;
	}
	return (u[0]);
}

char				*tetr_check(unsigned short int u)
{

}