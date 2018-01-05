#include<stdlib.h>
#include<stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
int	size, i;
int	*tab;

if (min>=max)
{
	size=0;
}
else
{
	size=(max-min);
	i=0;

	tab=malloc(size*sizeof(int));

	while (i<size)
	{
		tab[i]=min;
		i++;
		min++;
	}
}
*range=tab;
return size;
}



int main(int argc, char **argv)
{
	int *range=NULL;
	int	i=0;	

	if (argc == 3)
		printf("taille =%d \n", ft_ultimate_range(&range, atoi(argv[1]),atoi(argv[2])));
	else
		printf("écrire min et max\n");

while (i<ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2])))
{
printf("%d ", range[i]);
i++;
}
return 0;
}
