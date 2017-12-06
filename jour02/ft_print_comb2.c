#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c)
{
write(1, &c, 1);
}

void ft_print_comb2(void)
{
int i,j,k,l;
for (i=48; i<58; i++)
	{
		for (j=48; j<58; j++)
		{		
			for (k=i; k<58; k++)
			{
			for(l=48; l<58; l++)
			{
			if((k==i && l>j)||k>i)
				
			{
			ft_putchar(i);
			ft_putchar(j);
			ft_putchar(' ');
			ft_putchar(k);
			ft_putchar(l);
			if(!(i==57 && j==56))
			{
			ft_putchar(',');
			ft_putchar(' ');
			}
			}
			}
			}
		}
	}
			
			
}
	
int main(void)
{
ft_print_comb2();
printf("\n");
return 0;
}



