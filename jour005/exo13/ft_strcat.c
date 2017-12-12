#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
unsigned int n=0, i=0;

while (dest[n])
++n;

while (src[i])
	{
	dest[n+i]=src[i];
	++i;
	}
dest[n+i]='\0';

return dest;
}

int main(void)
{
char dest1[]="bonjour et encore";
char src[]=" c'est moi";

unsigned int n=0, m=0, i=0;
while (dest1[n])
n++;

while (src[m])
m++;

--m;

char dest[n+m];
while (i<n)
	{
	dest[i]=dest1[i];
	i++;
	}
while (i>=n && i<=n+m)
	{
	dest[i]='\0';
	i++;
	}

printf("%s \n", ft_strcat(dest, src));
return 0;
}

