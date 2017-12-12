#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
unsigned int i=0;
unsigned int temp=0, r=0, t=0;
while(s1[r])
	{r++;}
--r;

while(s2[t])
	{t++;}
--t;

if (r<t)
	{
	temp=r;
	r=t;
	t=temp;
	}

if(t<n)
	{
	temp=t;
	t=n;
	n=temp;
	}


temp=0;

while (i<=n)
	{
	temp+=s1[i]-s2[i];
	i++;
	}

return temp;
}

int main(void)
{
char s1[]="zello";
char s2[]= "hellosalut";
unsigned int n= 7;

printf("%d \n", ft_strncmp(s1, s2, n));
printf("%d \n", strncmp(s1, s2, n));
return 0;
}

