#include <stdio.h>
#include "ft_strrev.h"

int main(void)
{
char str[]="salut";

*ft_strrev(&str[0]);
printf("%s \n", str);
return 0;
}
