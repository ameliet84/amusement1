#ifndef _BSQ_H_
#define _BSQ_H_


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h> 
#include <string.h>

typedef struct s_coord
{
	int line;
	int col;
} t_coord;

typedef struct  s_elt
{
	char car;
	int ligne;
	int colonne;
} t_elt;

typedef struct s_obs
{
	int ligne;
	int colonne;
} t_obs;

void print_obs(t_obs *tab, int nb);
void print_tab(t_elt **tab, int line, int col);
int test_char(char c, t_elt **tab);
void init_numbers(char *file, int *line, int *col);
int nb_empty(t_elt **tab, char *c, int col, int j);
int init_tab(char *file, int line, int col, t_elt **tab);
int test_line(t_elt **tab, int i, int j, int max);
int test_col(t_elt **tab,  int i, int j, int max);
int maxi(t_elt **tab, int i, int j);
void repl_col(t_elt **tab, int i, int j, int max);
void repl_line(t_elt **tab, int i, int j, int max);
void replace(t_elt **tab, int i, int j, int max);
void convert_tab(t_elt **tab, int line, int col);
//void convert_tab(char **tab1, t_elt **tab, char *init, int line, int col);

#endif