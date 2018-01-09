#include<stdlib.h>
#include<stdio.h>

#define ABS(Value)  ((Value<0)?-Value:Value)

int	main(int argc, char **argv)
{
if(argc==2)
{
printf("%d \n", ABS(atoi(argv[1])));
}
return 0;
}
