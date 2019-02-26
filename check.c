/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:52:50 by kmills            #+#    #+#             */
/*   Updated: 2019/02/26 17:45:32 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		kolvoreshvstroke(char *s)
{
	int		i;
	int 	n;

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

int		kolvoresh(char *file, int o)
{
	int		i;
	char	*str;
	int		n;

	i = 0;
	while (get_next_line(o, &str))
	{
		if (!(ft_strlen(str) == 4 || (n == 4 && ft_strlen(str) == 0)))
			return (0);
		n = n + kolvoreshvstroke(str);
		if (ft_strlen(str) == 0)
			n = 0;
	}
	return (1);
}