#include<stdlib.h>
#include<stdio.h>

int	*ft_range(int min, int max)
{
	int *tab=NULL;
	int size;
	int i=0;

	if(min<max)
		size=(max-min)+1;
	
	tab=malloc(size);
	
	if(min<max)
	{
		while(min+i<max)
		{
			tab[i]=min+i;
			i++;
		}
	}
	return tab;
}

int	main(int argc, char **argv)
{	int	i;
		i=0;

	if(argc>=3)
	{
	int *tab=ft_range(atoi(argv[1]),atoi(argv[2]));
	
	while(tab[i])
	{
		printf("%d ", tab[i]);
		++i;
	}
	printf("\n");
	}

	return 0;
}
