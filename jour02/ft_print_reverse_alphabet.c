
#include<unistd.h>
#include<stdio.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_reverse_alphabet(void)
{
char c;
for (c='Z'; c>='A'; c--)
{ft_putchar(c);}
}

int main(void)
{
ft_print_reverse_alphabet();
printf("/n");
}
