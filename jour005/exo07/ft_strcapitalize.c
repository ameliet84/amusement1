#include <stdio.h>

char *ft_strcapitalize(char *str)
{
unsigned int n=1;

if (str[0]<='z' && str[0]>='a')
	str[0]=str[0]-32;

while (str[n])
{
	if(str[n-1]>'z'||(str[n-1]<'a' && str[n-1]>'Z')||str[n-1]<'A')
		{
		if (str[n]<='z' && str[n]>='a')
			{
			str[n]=str[n]-32;
			n++;
			}
		else
			n++;
		}
	if((str[n-1]>='a'&&str[n-1]<='z') || (str[n-1]<='Z' && str[n-1]>'A'))
		{
		if (str[n]>='A' && str[n]<='Z')
			{
			str[n]+=32;
			++n;
			}
		else
			++n;
		}
}
	
return str;
}

int main(void)
{
char str[]="salut, comment tu vas ? 42mots quarante-deux; cinqUante+et+un";
printf("%s\n", ft_strcapitalize(str));
return 0;
}

