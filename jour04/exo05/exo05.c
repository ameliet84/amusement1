#include "exo05.h"

int exo05(int nb)
{
int i=0;
while (i*i!=nb && i<nb)
	{ i++;}
if(i*i==nb)
	{ return i;}
else 
{return 0;
}
}
