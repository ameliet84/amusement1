#ifndef FILLIT_H_
#define FILLIT_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int 	square(int nbr);
void ft_strcpy(char *src, char *dest, int i);
void print_tab(char **tab, int size);
void print_tab2(char ***tab, int size);
int treat_trio(char a, char *str, int *n);
char **create_tab(int size);
int test_piece(char **table, char **tab, int pos, int size);
void place_piece(char **table, char **tab, int pos, int size);
void init_table(char **table, int size);
int length(char **tab);
void remove_piece(char **table, char **tab, int size);
char caractere(char **tab);
int test_trio(char **tab);

#endif