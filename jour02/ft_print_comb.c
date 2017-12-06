#include <stdio.h>
#include<unistd.h>

int ft_putchar(char c)
{
write (1, &c, 1);
}

void ft_print_comb(void)
{
int m=48, n=49, o=50;

while (m<58)
{  	while (n>m && n<58)
	{
		while (o>n && o<58)
		{ ft_putchar(m);
		 ft_putchar(n);
		ft_putchar(o);
	       		if (m!=55)
			{
			ft_putchar(',');
			ft_putchar(' ');
			}
		o++;
		}
	n++;
	o=n+1; }
m++;
n=m+1;
o=n+1;
}
}
	
int main(void)
{
ft_print_comb();
printf("\n");
return 0;
}
