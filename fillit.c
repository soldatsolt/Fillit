/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:22 by kmills            #+#    #+#             */
/*   Updated: 2019/02/26 19:06:41 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		kolvoresh(char *file, int o);

int		main(int argc, char **argv)
{
	int		o;
	int		r;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	str = ft_strnew(1);
	if (argc > 1)
	o = open(argv[1], O_RDONLY);
	// while ((r = read(o, buf, BUFF_SIZE)))
	// {
	// 	buf[r] = '\0';
	// 	str = ft_strrejoin(str, buf);
	// }
	r = kolvoresh(str, o);
	printf("___%i___\n", r);
	return (0);
}