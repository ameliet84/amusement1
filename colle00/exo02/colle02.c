#include <unistd.h>

void ft_putchar(char c);


void colle(int a, int b)
{

int i=0, j=0;
while (i<b)
{
	while(j<a)
	{
	if (i==0 && (j==0 || j==a-1))
		{
		ft_putchar('A');
		if (j==a-1)
			ft_putchar('\n');
		}
	else if (i==b-1 && (j==0||j==a-1))
		{
		ft_putchar('C');
		if (j==a-1)
			ft_putchar('\n');
		}
	else if ((i==0 ||i==b-1)&& j>0 && j<a-1)
		ft_putchar('B');
	else if ((j==0 && i>0 && i<b-1)||(j==a-1 && i>0 && i<b-1 ))
		{
		ft_putchar('B');
		if (j==a-1)
			ft_putchar('\n');
		}
	else 
		ft_putchar(' ');
	j++;
	}
i++;
j=0;
}
}
	
		
