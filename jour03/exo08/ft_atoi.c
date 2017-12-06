#include "ft_atoi.h"

int ft_atoi(char *str)
{
int a=0, j, puissance=1, debut=0;

if ((int)str[0]==45)
{
debut ++;
}
int i=debut;

while ((int)str[i]<=57 && (int)str[i]>=48)
{
i++;
}
for (j=i-1; j>=debut; j--)
{
a+=((int)str[j]-48)*puissance;
puissance*=10;
}
if ((int)str[0]==45)
{
a*=-1;
}

return a;
}
