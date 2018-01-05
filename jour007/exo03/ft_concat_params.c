#include <stdio.h>
#include <stdlib.h>

char *ft_concat_params(int argc, char **argv)
{
char	*str;
int	size;
int	i,j, k;
	j=0;
	i=1;
	size=0;
	k=0;

while (i<argc)
{
	while (argv[i][k]!='\0')
	{
		size++;
		k++;
	}
	if (argv[i][k]=='\0')
	{
		k=0;
		size++;
		i++;
	}
}

str=(char *)malloc(sizeof(char)*(size-1));

i=1;

while(i<argc)
{
	while(argv[i][k]!='\0')
	{
	str[j]=argv[i][k];
	j++;
	k++;
	}
	if (argv[i][k]=='\0')
	{
	str[j]='\n';
	j++;
	i++;
	k=0;
	}
}

return str;
}
