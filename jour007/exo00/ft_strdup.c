#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char *ft_strdup(const char *s)
{
int	size;
int	i;
	size=0;
	i=0;

while(s[size])
{
size++;
}

char *memory=NULL;

memory=malloc(size);

while(i<size)
{
memory[i]=s[i];
++i;
}

return memory;
}

int main(int argc,char **argv)
{
if (argc>=2)
{
printf("%s\n", strdup(argv[1]));
printf("%s\n", ft_strdup(argv[1]));
return 0;
}
}

