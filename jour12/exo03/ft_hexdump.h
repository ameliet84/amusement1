#ifndef _FT_HEXDUMP_H
#define _FT_HEXDUMP_H

#include <fcntl.h>
#include <stdlib.h>
#include<stdio.h>
#include<unistd.h>

void ft_putchar(char c);

int power(int pwr);

void print_hexa(int nb);

int file_size(char *str);

char *all(int size, int argc, char **argv);

int size_all(int argc, char **argv);

void print_char(char c);

#endif