#include "ft_stock_par.h"
#include<stdlib.h>
#include<stdio.h>

int	len(char *str)
{
	int	i;
		i=0;
while(*str)
	i++;
return i;
}

char	*ft_copy(char *str)
{
int	i;
char	*memory;
	
	i=0;
memory=malloc(sizeof(char)*len(str));

while(i<len(str))
{
	memory[i]=str[i];
	i++;
}
return (memory);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
int	i;
int	j;
struct s_stock_par *tab1;
char	*param;
	
	j=0;
	i=0;
tab1=malloc(sizeof(char **)*(ac+1));
while(i<=ac)
{	
printf("entrée dans la boucle\n");
	if(i<ac)
	{
		printf("%s \n", av[i]);
//		param=malloc(sizeof(char)*len(av[i]));	
		param=av[i];
		printf("%s \n", param);
	}
	else
	{
		param=malloc(sizeof(char)*1);
		param="0";
	}
printf("ok\n");
	tab1[i].size_param=len(param);
printf("ok2\n");
//	tab1->str=malloc(sizeof(char)*len(param));
	tab1->str=param;
//	tab1->copy=malloc(sizeof(char)*len(ft_copy(param)));
	tab1->copy=ft_copy(param);
printf("bientôt\n");
	tab1->tab=malloc(sizeof(char *)*len(param));
	while (j<len(param))
	{
		printf("%d \n", j);
		tab1->tab[j++]=malloc(sizeof(char *)*len(param));
		printf("%d \n", j);
	}	
	tab1->tab=ft_split_whitespaces(param);
	tab1++;
	j=0;
	i++;
	printf("%d \n", i);
}
return tab1;
}


