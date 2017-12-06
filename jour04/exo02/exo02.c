#include "exo02.h"

int exo02(int nb, int power)
{
if (power<0)
{
return 0;
}

int i, a=1;
for(i=0;i<power;i++)
{
a*=nb;
}
return a;
}
