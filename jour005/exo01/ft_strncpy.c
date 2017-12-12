#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
for (unsigned int i=0; i<n; i++)
	{
	if (src[i])
		{
		dest[i]=src[i];
		}
	else
	dest[i]='\0';
	}
dest[n]='\0';
return dest;
}

int main(void)
{
char src[]="bonjour";
unsigned int n=14;
char dest[n+1];


printf("la chaine de départ est %s\n", src);
printf("la chaine obtenue est %s\n", ft_strncpy(dest, src, n));
return 0;
}
