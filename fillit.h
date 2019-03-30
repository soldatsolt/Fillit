/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:30:12 by kmills            #+#    #+#             */
/*   Updated: 2019/03/30 08:57:14 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"

typedef	struct	s_tetr
{
	int			i;
	int			j;
	int			k;
	int			w;
	int			h;
	u_int16_t	u;
}				t_tetr;
typedef	struct	s_koor
{
	int			i1;
	int			j1;
	int			i2;
	int			j2;
	int			i3;
	int			j3;
	int			i4;
	int			j4;
}				t_koor;

int				g_len;
int				g_size;
t_tetr			*g_nach8;
u_int64_t		g_imax;
int				kolvoreshvstroke(char *s);
u_int16_t		*tetramina(char *s, int k, int sym, int l);
int				tetr_check(u_int16_t *u, int l, int k);
int				check6or8(u_int16_t u, int n);
int				dvizh_vverkh(u_int16_t *u, int i, int n);
int				dvizh_vlevo(u_int16_t *u, int i, int n);
u_int16_t		*kolvoresh(int o, int i, int n, u_int16_t *u);
void			karta(u_int16_t *u, int l);
int				min_map_size(int l);
void			naris_mass(u_int16_t *summ, t_koor *t, int l);
u_int16_t		*summis(t_tetr *tetr, int16_t k);
u_int16_t		*vstav_v_summ(u_int16_t *summ, u_int16_t u, int i, int j);
int				norm_li(u_int16_t *summ, u_int16_t u, int i, int j);
t_tetr			dodvizh(t_tetr *tetr, int16_t k, int16_t i);
int				high(u_int16_t u);
int				widt(u_int16_t u);
t_tetr			*maketetrstruct(t_tetr *tetr, u_int16_t *u, int l);
t_tetr			*doit(t_tetr *tetr, int16_t l, int16_t k, int16_t i);
t_koor			*makekoor(t_koor *t, t_tetr *tetr, int l, int k);
void			narisabc(u_int16_t *summ, t_koor *t, int l);
t_koor			mkoor(t_koor t, t_tetr tetr, int f, int i);
t_tetr			retdodvizh(t_tetr tetr, int k);
int				normik(u_int16_t *summ, u_int16_t u, int i, int j);

#endif
