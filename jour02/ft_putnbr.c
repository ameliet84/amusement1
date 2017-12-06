#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
if (nb<0)
{	ft_putchar('-');
	nb=-nb;
}
int i=1, temp=nb, c;
while (temp/10!=0)
	{i*=10;
	temp/=10;
	}
temp = nb;
while (i>=1)
	{temp=temp/i;
	c= temp + 48;
	temp=nb%i;
	ft_putchar(c);
	i/=10;
	}
	
}

int main(void)
{
ft_putnbr(-190008907);
printf("\n");
return 0;
}
