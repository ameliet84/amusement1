#include <stdio.h>

char *ft_strupcase(char *str)
{
unsigned int n=0;

while (str[n])
{
if (str[n]>='A' && str[n]<='Z')
	{
	str[n]=str[n]+32;
	}
++n;
}
return str;
}

int main(void)
{
char str[]="HELLO";

printf("%s\n", ft_strupcase(str));
return 0;
}

