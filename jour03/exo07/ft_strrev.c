#include <stdio.h>
#include "ft_strrev.h"

char *ft_strrev(char *str)
{
int count=0;

while(str[count])
{
count++;
}
int i, moitie;
if (i%2==1)
{	
	moitie = (count-1)/2;
}
else
{
	moitie = count/2;
}

for (i=0; i++; i<=moitie)
{
char temp = str[i];
str[i]=str[count - i-1];
str[count -i-1]=temp;
}
return str;
}


