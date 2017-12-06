#include "exo04.h"

int exo04(int index)
{

if (index<0)
{
return -1;
}
else if (index == 0)
{return 0;}
else if (index==1)
{return 1;}

return exo04(index -1) + exo04(index -2);
}

