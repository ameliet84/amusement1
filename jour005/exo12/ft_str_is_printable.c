#include <stdio.h>

int ft_str_is_printable(char *str)
{
unsigned int n=0, i=1;

while (str[n])
{
	if ((str[n]<=32  && str[n]>=0)|| str[n]==127||str==NULL)
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

printf("%d\n", ft_str_is_printable(str));
return 0;
}

	
