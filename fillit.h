#ifndef FILLIT_H
# define FILLIT_H
#include "./libft/libft.h"

int					kolvoreshvstroke(char *s);
unsigned short int	*tetramina(char *s, int k, int sym, int l);
int					tetr_check(unsigned short int *u, int l, int k);
int					check6or8(unsigned short int u, int l, int n);
int					dvizh_vverkh(unsigned short int *u, int i, int n);
int					dvizh_vlevo(unsigned short int *u, int i, int n);
int					kolvoresh(int o, int i, int n, unsigned short int *u);

#endif