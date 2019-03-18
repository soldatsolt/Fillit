/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:30:12 by kmills            #+#    #+#             */
/*   Updated: 2019/03/19 01:58:12 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
int			g_len;
int			kolvoreshvstroke(char *s);
u_int16_t	*tetramina(char *s, int k, int sym, int l);
int			tetr_check(u_int16_t *u, int l, int k);
int			check6or8(u_int16_t u, int l, int n);
int			dvizh_vverkh(u_int16_t *u, int i, int n);
int			dvizh_vlevo(u_int16_t *u, int i, int n);
u_int16_t	*kolvoresh(int o, int i, int n, u_int16_t *u);
u_int64_t	karta(u_int16_t *u, int l);
int			min_map_size(int l);
u_int64_t	mod_karta(u_int16_t u, u_int64_t mapa, int min_size);
void		naris(u_int64_t llu);
u_int64_t	zapoln_kartu(u_int64_t mapa, int i, u_int64_t llu);
void		naris_mass(u_int64_t mapa, int k, u_int64_t *prav_tetr, int l);

#endif
