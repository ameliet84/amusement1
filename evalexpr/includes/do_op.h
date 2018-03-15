#ifndef DO_OP_H_
#define DO_OP_H_

#include<unistd.h>
#include<stdio.h>
#include <stdlib.h>

typedef struct s_opp
{
char opp;
int  (*ft)(int, int);
}	t_opp;


int	ft_add(int a, int b);
int	ft_sub(int a, int b);
int	ft_div(int a, int b);
int	ft_mul(int a, int b);
int	ft_mod(int a, int b);
int ft_strcmp(char *s1, char *s2);
int	length(char *str);
void ft_putnbr(int nb);
int	ft_atoi(char *str);
int test_expr(int b, char c);
char *nbr(int a);
void fusion(char *s1, char *s2, int m, int n);
int do_op(int a, int b, char c);
int test_gauche(char *str, int i);
int test_droit(char *str, int i);
int test_parentheses(char *str);
void parentheses(char *str);
int test_priorite(char *str);
void priorite(char *str);
int test_sum(char *str);
void sum(char *str);
void simple(char *str);
void eval(char *str);
void split_white(char *str);



#endif


