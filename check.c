/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:52:50 by kmills            #+#    #+#             */
/*   Updated: 2019/03/01 19:51:35 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

unsigned short int	*tetramina(char *s, int k, int sym, int l);
void				tetr_check(unsigned short int *u, int l);
int					check6or8(unsigned short int u,  int l, int n);
int					dvizh_vverkh(unsigned short int *u, int i, int n);
int					dvizh_vlevo(unsigned short int *u, int i, int n);

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
	return ((i == 4) ? 1 : 0);
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
		k++;
		i = 0;
	}
	tetr_check(u, l);
	return (u);
}

void				tetr_check(unsigned short int *u, int l)
{
	int		i;
	int		k;

	i = 0;
	while (i < l / 16)
	{
		if (!(check6or8(u[i], l, 0)))
			return ; // мб тип функции поменять или ещё что-то я хз что сделать, чтобы это ушло в мэйн
		i++;
	}
	i = 0;
	while (i < l / 16)
	{
		while (dvizh_vverkh(&u[i], 0, 0))
			i = i;
		i++;
	}
	i = 0;
	while (i < l / 16)
	{
		while (dvizh_vlevo(&u[i], 0, 0))
			i = i;
		i++;
	}
}

int					check6or8(unsigned short int u,  int l, int n)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (((32768 >> i) & u))
		{
			if (((32768 >> (i - 1)) & u) && ((i) % 4 != 0))
				n++;
			if (((32768 >> (i + 1)) & u) && ((i + 1) % 4 != 0))
				n++;
			if (((32768 >> (i - 4)) & u))
				n++;
			if (((32768 >> (i + 4)) & u))
				n++;
		}
		i++;
	}
	if (!(n == 8 || n == 6))
		return (0);
	return (1);
}

int					dvizh_vverkh(unsigned short int *u, int i, int n)
{
	while (i < 4)
	{
		if (((32768 >> i) & *u))
			n = 1;
		i++;
	}
	if (!n)
		*u = *u << 4;
	i = 0;
	while (i < 4)
	{
		if (((32768 >> i) & *u))
			n = 3;
		i++;
	}
	return ((n > 2) ? 0 : 1);
}

int					dvizh_vlevo(unsigned short int *u, int i, int n)
{
	while (i < 16)
	{
		if (((32768 >> i) & *u))
			n = 1;
		i = i + 4;
	}
	if (!n)
		*u = *u << 1;
	i = 0;
	while (i < 16)
	{
		if (((32768 >> i) & *u))
			n = 3;
		i = i + 4;
	}
	return ((n > 2) ? 0 : 1);
}

