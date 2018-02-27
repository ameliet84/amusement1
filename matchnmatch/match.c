#include "match.h"

int match(char *s1, char *s2)
{
	int n;
	int m;

	n=0;
	m=0;
	while(s1[n])
	{
		if(s1[n]!=s2[m] && s2[m]!='*')
			return 0;
		else
		{
			if(s1[n++]==s2[m])
				m++;
			else if(s1[n]!=s2[m])
			{
				n++;
				if (s1[n]==s2[m+1] && s1[n]!='\0')
					m++;
			}
		}
	}
	while(s2[m]=='*')
		m++;
	if(s2[m]!='\0')
		return 0;
	return 1;
}

/*
int main(int argc, char **argv)
{
	if(argc == 3)
		printf("%d\n", match(argv[1], argv[2]));
	return 0;
}
*/