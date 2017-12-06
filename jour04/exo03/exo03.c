#include "exo03.h"

int exo03(int nb, int power)
{

if (power<0)
{
return 0;
}
else if (power==0)
{
return 1;
}


return nb*exo03(nb, power-1);
}
