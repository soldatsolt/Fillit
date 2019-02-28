/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:52:50 by kmills            #+#    #+#             */
/*   Updated: 2019/02/28 22:16:01 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

unsigned short int	*tetramina(char *s);
void				tetr_check(unsigned short int *u, int l);
int					check6or8(unsigned short int *u,  int l, int n, int k);

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

int					kolvoresh(int o, int i, int n)
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
	printf("%s\n", karta);
	printf("%i\n", tetramina(karta)[0]);
	return ((i == 4) ? 1 : 0);
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
	printf("++%i++\n", check6or8(u, l, 0, 0));
}

int					check6or8(unsigned short int *u,  int l, int n, int k)
{
	int		i;

	i = 0;
	while (k < l / 16)
	{
		while (i < 16)
		{
			if (((32768 >> i) & u[k]))
			{
				if (((32768 >> (i - 1)) & u[k]) && ((i) % 4 != 0))
					n++;
				if (((32768 >> (i + 1)) & u[k]) && ((i + 1) % 4 != 0))
					n++;
				if (((32768 >> (i - 4)) & u[k]))
					n++;
				if (((32768 >> (i + 4)) & u[k]))
					n++;
			}
			i++;
		}
		if (!(n == 8 || n == 6))
			return (0);
		i = 0;
		k++;
		n = 0;
	}
	return (1);
}

int					dvizh(unsigned short int u)
{
	int		i;
	int 	n;

	n = 0;
	while (i < 4)
		{
			if (((32768 >> i) & u))
			{
				if (((32768 >> (i - 1)) & u))
					n++;
				if (((32768 >> (i + 1)) & u))
					n++;
				if (((32768 >> (i - 4)) & u))
					n++;
				if (((32768 >> (i + 4)) & u))
					n++;
			}
			i++;
		}
	return (0);
}
