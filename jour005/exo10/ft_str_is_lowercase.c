#include <stdio.h>

int ft_str_is_lowercase(char *str)
{
unsigned int n=0, i=1;

while (str[n])
{
	if ((str[n]<='z' && str[n]>='a')||str==NULL)
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
char str[]="aaaaaabbdd4";

printf("%d\n", ft_str_is_lowercase(str));
return 0;
}

	
