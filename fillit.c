/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 21:53:22 by kmills            #+#    #+#             */
/*   Updated: 2019/02/26 16:18:57 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		main(int argc, char **argv)
{
	int		o;
	int		r;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	str = ft_strnew(1);
	if (argc > 1)
	o = open(argv[1], O_RDONLY);
	while ((r = read(o, buf, BUFF_SIZE)))
	{
		buf[r] = '\0';
		str = ft_strrejoin(str, buf);
	}
	printf("%s\n", str);
	return (0);
}