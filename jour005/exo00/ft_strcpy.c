#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
unsigned int n=0;

while (src[n])
{
	dest[n]=src[n];
	n++;
}
dest[n]='\0';
return dest;
}

int main(void)
{
char src[]="hello world";

unsigned int n=0;
while (src[n])
{
n++;
}
char dest[n];
printf("il y a %d caractères \n", n); 
printf("la chaine de départ est %s\n", src);
printf("la chaine d'arrivée est %s\n", ft_strcpy(dest, src));
return 0;
}

