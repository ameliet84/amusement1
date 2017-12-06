
#include <stdio.h>

int ft_strlen(char *str)
{
int i=0;
while(str[i])
{
i++;
}
return i;
}

int main(void)
{
char str[]="bonjour c'est moi";
int len=ft_strlen(&str[0]);
printf("le nombre de caractères est %d \n", len);
return 0;
}
