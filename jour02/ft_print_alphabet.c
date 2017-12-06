#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_alphabet(void)
{
char c;
for (c='A'; c<='Z'; c++)
{ ft_putchar(c);}
}

int main(void)
{
ft_print_alphabet();
printf("/n");
}
