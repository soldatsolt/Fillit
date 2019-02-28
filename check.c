/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:52:50 by kmills            #+#    #+#             */
/*   Updated: 2019/02/28 17:29:46 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

unsigned short int	*tetramina(char *s);
void				tetr_check(unsigned short int *u, int l);
int					check6or8(unsigned short int u,  int l);

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
	printf("%s\n", karta);
	printf("%i\n", tetramina(karta)[0]);
	return (i == 4 ? 1 : 0);
}

unsigned short int	*tetramina(char *s)
{
	int					i;
	unsigned short int	*u;
	int					l;
	int					k;

	k = 0;
	l = ft_strlen(s);
	u = (unsigned short int *)malloc(sizeof(unsigned short int) * l / 16);
	ft_bzero(u, l);
	i = 0;
	while (k < l / 16)
	{
		while (i < 16)
		{
			if (*s == '#')
			{
				u[k] |= 1 << (16 - i - 1);
			}
			i++;
			s++;
		}
		k++;
		i = 0;
	}
	tetr_check(u, l);
	return (u);
}

void				tetr_check(unsigned short int *u, int l)
{
	char	*s;
	int		i;
	int		k;

	k = 0;
	s = ft_strnew(l);
	i = 0;
	while (k < l / 16)
	{
		while (i < 16)
		{
			if (((32768 >> i) & u[k]))
				*s = '#';
			else
				*s = '.';
			i++;
			s++;
		}
		i = 0;
		k++;
	}
	s = s - l;
	printf("%s\n", s);
	k = 0;
	while (k < l / 16)
	{
		printf("++%i++\n", check6or8(u[k], l));
		k++;
	}
}

int					check6or8(unsigned short int u,  int l)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (i < 16)
	{
		if (((32768 >> i) & u))
		{
			if(((32768 >> (i - 1)) & u))
				n++;
			if(((32768 >> (i + 1)) & u))
				n++;
			if(((32768 >> (i - 4)) & u))
				n++;
			if(((32768 >> (i + 4)) & u))
				n++;
		}
		i++;
	}
	return ((n == 6 || n == 8) ? 1 : 0);
}
