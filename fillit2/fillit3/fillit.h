#ifndef FILLIT_H_
#define FILLIT_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

typedef struct s_coord{
	int x;
	int y;
} t_coord;

typedef struct s_piece{
	char car;
	int line;
	int col;
	int init;
	char letter;
	int maxi;
	int maxj;
	struct s_coord coord1;
	struct s_coord coord2;
	struct s_coord coord3;
	struct s_coord coord4;
}	t_piece;

#include "fillit.h"



int line(t_piece **tab, int i, int j);

int colonne(t_piece **tab, int i, int j);

void treat_trio2(t_piece **tab, int l);

char caractere(t_piece **tab);

int	square(int nbr);

void ft_strcpy(char *src, char *dest);

void ft_strcpy2(char *src, t_piece *dest);

void print_tab(char **tab, int size);

void print_tab2(t_piece ***tab, int size);

int test_trio2(t_piece **tab, int i, int j);

int test_trio(t_piece **tab);

int treat_trio(char a, char *str, int *n);

char **create_tab(int size);

int skip_lines(t_piece **tab, int i);

int skip_cols(t_piece **tab, int i);

int test_piece2(int pos, char **table, int size);

int test_piece(char **table, t_piece **tab, int i, int j);

void place_piece(char **table, t_piece **tab, int i, int j);

void init_table(char **table, int size);

int length(char **tab);

void remove_piece(char **table, t_piece **tab, int i, int j);

int test_tab1(char **tab, int i, int j, int size);

int test_tab2(char **tab, int i, int j, int size);

char last_letter(char **tab, int size);

char first_letter(char **tab, int size);

int possible(char **table, t_piece **tab);



#endif