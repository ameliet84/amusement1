#include <stdio.h>
#include <stdlib.h>

int	test(char *str, int i)
{
	if (((str[i]==' '||str[i]=='	' ||str[i]=='\n')&& (str[i-1]!=' '&& str[i-1]!='	' && str[i-1]!='\n') && i!=0))
	return 1;
	else
	return 0;
}

char **ft_split_whitespaces(char *str)
{
char	**words;
int	nb_words;
int	i, j,k;
	nb_words=0;
	i=0;
	j=0;
	k=0;

while (str[i])
{
	if (test(str, i)==1||str[i+1]=='\0')
		++nb_words;
	i++;
}

words=(char **)malloc(sizeof(char*)*(nb_words+1));

while (j<i)
{
	words[j]=(char *)malloc(i*sizeof(char));
	j++;
}

j=0;
i=0;

while (j<nb_words)
{
	while (str[i])
	{
		if (test(str, i)==1)
		{	words[j][k]='\0';	
			k=0;
			++j;
		}
		if (str[i]!=' ' && str[i]!='	' && str[i]!='\n')
		{
			words[j][k]=str[i];
			k++;
			if (str[i+1]=='\0')
			{
			words[j][k]='\0';
			j=nb_words;
			}
		}
	i++;
	}
}

words[nb_words][0]='0';
words[nb_words][1]='\0';

return words;
}
