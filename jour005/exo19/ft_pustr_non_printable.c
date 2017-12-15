#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
write(1, &c, 1);
}

void hexa(int nb)
{
char base[]="0123456789abcdef";

if (nb<100)
{
	ft_putchar(base[nb/16]);
	nb = nb%16;
	ft_putchar(base[nb]);
}
else 
{
	ft_putchar('7');
	ft_putchar('F');
}
}

void ft_putstr_non_printable(char *str)
{
int i=0;
while (str[i])
{
	if ((str[i]>=0 && str[i]<32)||str[i]==127)
		{
		ft_putchar(92);
		hexa(str[i]);
		}
	else
	ft_putchar(str[i]);
i++;
}
}

int main(void)
{
char str[]="Coucou\ntu vas bien ?";
ft_putstr_non_printable(str);
ft_putchar('\n');
return 0;
}
		
