/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:30:12 by kmills            #+#    #+#             */
/*   Updated: 2019/03/28 12:38:59 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

int			g_len;
int			g_size;
u_int64_t	*g_nach8;
u_int64_t	g_imax;
int			kolvoreshvstroke(char *s);
u_int16_t	*tetramina(char *s, int k, int sym, int l);
int			tetr_check(u_int16_t *u, int l, int k);
int			check6or8(u_int16_t u, int l, int n);
int			dvizh_vverkh(u_int16_t *u, int i, int n);
int			dvizh_vlevo(u_int16_t *u, int i, int n);
u_int16_t	*kolvoresh(int o, int i, int n, u_int16_t *u);
void		karta(u_int16_t *u, int l);
int			min_map_size(int l);
void		naris(u_int64_t llu);
void		naris_mass(u_int16_t summ[16]);
u_int64_t	dvig_tetr_vgran(u_int64_t *tetr, int k, u_int64_t tetrik);
u_int64_t	summis(u_int64_t *tetr, int k, u_int64_t summ);
u_int64_t	uvel_gran(u_int64_t gran);
u_int64_t	mod_karta(unsigned short int u, u_int64_t *tetr, int k);
int			prav_razm(u_int64_t mapa);
int			check6or8big(u_int64_t u, int l, int n);
u_int64_t	makegran(u_int64_t gran, int size);
void		ijsdijs(u_int64_t *tetr, int k, int i);
void		asdfefe(int *i, int max, int *ki);
u_int64_t	*makethis(u_int64_t *tetr, int l, int k, u_int64_t tetrik);
void		narisgrantoo(u_int64_t llu, u_int64_t gran);
int			checkif8(u_int64_t u, int i, int n);
void		vstav_v_summ(u_int16_t **sum, u_int16_t u);

#endif
