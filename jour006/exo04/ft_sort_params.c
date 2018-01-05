#include<unistd.h>

int	size_arg(char *argv)
{
int i=0;

while(argv[i])
i++;
return i;
}

int	main(int argc,char **argv)
{
int i=1, j=0, k=2;
char *temp;

while (i<argc-1)
	{
		while(k<argc)
			{
			j=0;
			while(argv[i][j])
			{	if(argv[i][j]<argv[k][j])
				j=size_arg(argv[i]);

				else if(argv[i][j]>argv[k][j])
				{
				temp=argv[i];
				argv[i]=argv[k];
				argv[k]=temp;
				j=size_arg(argv[i]);
				}
				else
				++j;
			}
			k++;
			}
	++i;
	k=i+1;
	}

	i=1;
while (i<argc)
{
	while(*argv[i])
	{
		write(1, argv[i], 1);
		argv[i]++;
	}
write(1, "\n", 1);
++i;
}
return 0;
}
	
