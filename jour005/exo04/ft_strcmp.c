#include<string.h>
#include<stdio.h>

int ft_strcmp(char *s1, char *s2)
{
int i=0, n=0, m=0, temp=0;
while (s1[n])
{
++n;
}

while (s2[m])
{
++m;
}

if (n<m)
{
	while (i<n)
	{
	temp= temp + (s1[i]-s2[i]);
	i++;
	}
}
else
{	while (i<m)
	{
	temp = temp + (s1[i]-s2[i]);
	i++;
	}
}
return temp;
}



int main(void)
{
char s1[]="hellp";
char s2[]="helloz";

printf("%d \n",ft_strcmp(s1,s2));
printf("%d \n", strcmp(s1,s2));
return 0;
}
