#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_numbers(void)
{
int i;
for(i=48; i<58; i++)
{
ft_putchar(i);
}
}

int main(void)
{
ft_print_numbers();
printf("\n");
}
