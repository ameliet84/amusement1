#ifndef _BSQ_H_
#define _BSQ_H_


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h> 

void print_tab(char **tab, int line, int col);
int test_char(char c, char *init);
void init_numbers(char *file, int *line, int *col, char *init);
void init_tab(char *file, int line, int col, char **tab, char *init);
int test_line(char **tab, char *init, int i, int j, int max);
int test_col(char **tab, char *init, int i, int j, int max);
int maxi(char **tab, char *init, int i, int j, int line, int col);
void repl_col(char **tab, char *init, int i, int j, int max);
void repl_line(char **tab, char *init, int i, int j, int max);
void replace(char **tab, char *init, int i, int j, int line, int col);

#endif