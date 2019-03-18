/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:30:12 by kmills            #+#    #+#             */
/*   Updated: 2019/03/19 01:00:13 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

int						g_len;
int						kolvoreshvstroke(char *s);
unsigned short int		*tetramina(char *s, int k, int sym, int l);
int						tetr_check(unsigned short int *u, int l, int k);
int						check6or8(unsigned short int u, int l, int n);
int						dvizh_vverkh(unsigned short int *u, int i, int n);
int						dvizh_vlevo(unsigned short int *u, int i, int n);
unsigned short int		*kolvoresh(int o, int i, int n, unsigned short int *u);
unsigned long long int	karta(unsigned short int *u, int l);
int						min_map_size(int l);
unsigned long long int	mod_karta(unsigned short int u, unsigned long long\
	int mapa, int min_size);
void					naris(unsigned long long int llu);
unsigned long long int	zapoln_kartu(unsigned long long int mapa, \
	int i, unsigned long long int llu);

#endif
