#include <stdio.h>

int ft_str_is_alpha(char *str)
{
unsigned int n=0, i=1;

while (str[n])
{
	if ((str[n]<='Z' && str[n]>='A')||(str[n]<='z'&&str[n]>='a')||str==NULL)
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
char str[]="i+u-4";

printf("%d\n", ft_str_is_alpha(str));
return 0;
}

	
