#include <stdio.h>

int ft_str_is_numeric(char *str)
{
unsigned int n=0, i=1;

while (str[n])
{
	if ((str[n]<='9' && str[n]>='0')||str==NULL)
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

printf("%d\n", ft_str_is_numeric(str));
return 0;
}

	
