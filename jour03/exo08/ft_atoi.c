#include "ft_atoi.h"

int ft_atoi(char *str)
{
int a=0, j, puissance=1, debut=0;

while (str[debut]==' '||str[debut]=='	'||(int)str[debut]==13)
{
debut++;
}

if (str[debut]=='-')
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
if (str[debut -1]=='-')
{
a*=-1;
}

return a;
}
