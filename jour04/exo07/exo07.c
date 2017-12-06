#include "exo07.h"

int prime(int nb)
{
int i;
if (nb<2)
{return 0;}

else if (nb%2==0)
{return 0;}
else 
{
for (i=1; 2*i+1<nb/2; i++)
{	if (nb%(2*i+1)==0)
	{return 0;
	break;}
}
return 1;
}
}


int exo07(int nb)
{
int nb1=nb+1, i;


while (prime(nb1)==0)
{
nb1++;}
return nb1;
}
