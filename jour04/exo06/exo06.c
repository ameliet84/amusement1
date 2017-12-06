
#include "exo06.h"

int exo06(int nb)
{
int i;
if (nb<2)
{
return 0;
}
if (nb%2==0)
{
return 0;
}
for (i=1;2*i+1<nb;i++)
{
	if (nb%(2*i+1)==0)
		{
		return 0;
		break;
		}
	
}
return 1;
}
