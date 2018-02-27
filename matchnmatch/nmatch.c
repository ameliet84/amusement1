#include "match.h"

void put_str(char *src, char *dest, int i)
{
	int j;

	j=0;
	while(src[i]!='\0')
		dest[j++]=src[i++];
	dest[j]='\0';
}

int change(char *s1, char *s2, int n, int m)
{
	char *s3;
	char *s4;

	s3=s1;
	s4=s2;
	put_str(s1, s3, n);
	put_str(s2, s4, m);
	if(match(s3, s4)==0 || s3[n]=='\0' || s4[m]=='\0')
		return 0;
	else
	{
		printf("s1 = %s, et s2=%s\n", s3, s4);
		return(1+change(s1,s2, n+1, m+1));
	}
}
/*
int count(char *s1, char *s2, int i)
{
	int n;
	int m;

	n=0;
	m=0;
	if(s1[n]!=s2[m] && s2[m]!='*')
		return 0;
	else
	{
		if(s1[n++]==s2[m])
			m++;
		else

	}
}

int nmatch(char *s1, char *s2)
{

}
*/

int main(int argc, char **argv)
{
	if(argc==3)
	{
		
		printf("%d\n", change(argv[1], argv[2], 0, 0));
	}
	return 0;
}