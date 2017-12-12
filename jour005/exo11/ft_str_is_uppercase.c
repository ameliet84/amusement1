#include <stdio.h>

int ft_str_is_uppercase(char *str)
{
unsigned int n=0, i=1;

while (str[n])
{
	if ((str[n]<='Z' && str[n]>='A')||str==NULL)
	n++;
	else
	{
	i=0;
	n++;
	}
}
return i;
}

int main(void)
{
char str[]="111564324";

printf("%d\n", ft_str_is_uppercase(str));
return 0;
}

	
