#include "ft_stock_par.h"
#include<stdlib.h>
#include<unistd.h>

struct s_stock_par *ft_param_to_tab(int ac, char **av);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char *ft_nbr(int size)
{
	int	pwr;
	int	temp;
	char	*nbr;
		
		temp=size;
		pwr=0;	
	while(temp!=0)
	{
		temp/=10;
		pwr++;
	}
nbr=malloc(sizeof(char)*pwr);
	while(pwr-1!=0)
	{
		nbr[pwr-1]=size%10+30;
		size/=10;
	}
return nbr;
}

void	ft_show_tab(struct s_stock_par *par)
{
	int	i;
	char	*nbr;
	
		i=0;
while(par->size_param!=0)
{
	while(par->str[i])
	{
		ft_putchar(par->str[i++]);
	}
	ft_putchar('\n');
	nbr=ft_nbr(par->size_param);
	while(*nbr)
		write(1, nbr++,1);
	ft_putchar('\n');
	i=0;
	while(par->tab)
	{
		while(par->tab[0])
			write(1, par->tab[0]++, 1);
		ft_putchar('\n');
		par->tab++;
	}	
par++;
}
}

int	main(int argc, char **argv)
{
ft_show_tab(ft_param_to_tab(argc, argv));

return 0;
}
