#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
int i=0;
while (str[i])
{
ft_putchar(str[i]);
i++;
}
}

int main(void)
{
char str[]="bonjour c'est moi";
ft_putstr(&str[0]);
printf("\n");
return 0;
}
