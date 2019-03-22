/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:30:12 by kmills            #+#    #+#             */
/*   Updated: 2019/03/23 01:50:40 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# define CH_8_6 (check6or8big((tetr[k] >> i), 0, 0, g_size))

int			g_len;
int			g_size;
int			kolvoreshvstroke(char *s);
u_int16_t	*tetramina(char *s, int k, int sym, int l);
int			tetr_check(u_int16_t *u, int l, int k);
int			check6or8(u_int16_t u, int l, int n);
int			dvizh_vverkh(u_int16_t *u, int i, int n);
int			dvizh_vlevo(u_int16_t *u, int i, int n);
u_int16_t	*kolvoresh(int o, int i, int n, u_int16_t *u);
u_int64_t	karta(u_int16_t *u, int l);
int			min_map_size(int l);
u_int64_t	mod_karta(u_int16_t u, u_int64_t *tetr, int k);
void		naris(u_int64_t llu);
u_int64_t	zapoln_kartu(u_int64_t *tetr, int k, u_int64_t llu);
void		naris_mass(u_int64_t mapa, int k, u_int64_t *tetr, int i);
u_int64_t	dvig_tetr_vgran(u_int64_t *tetr, int k, u_int64_t tetrik);
u_int64_t	summis(u_int64_t *tetr, int k, u_int64_t summ);
u_int64_t	uvel_gran(u_int64_t gran);
int			prav_razm(u_int64_t mapa);
int			check6or8big(u_int64_t u, int l, int n, int size);
u_int64_t	makegran(u_int64_t gran, int size);
void		ijsdijs(u_int64_t imax, u_int64_t *tetr, int k, int i);
void		asdfefe(int *i, int max, int *ki);

#endif
