#include <stdio.h>
#include <stdlib.h>

int count=0;

void print_tab(int tab[4][4])
{
	int	i;
	int j;
	i=-1;
	while(++i<4)
	{
		j=-1;
		while(++j<4)
			printf("%d  ", tab[i][j]);
		printf("\n");
	}
}

void produit(int tab[4][4], int *prod)
{
	int	i;
	int	j;
	char b;
	int result;

	i=0;
	j=0;
	result=tab[i][j];
	while(i+j<6)
	{
		printf("d pour droite, b pour bas\n");
		scanf("%c", &b);
		if(b=='b' && i<3)
			i++;
		else if(b=='d' && j<3)
			j++;
		else
			continue;
		print_tab(tab);
		result*=tab[i][j];
		printf("le produit pour le moment est de : %d et tu es sur la case = %d à la position %d x %d \n", result, tab[i][j], i, j);
	}
	*prod=result;
}
/*
int max(int tab[4][4])
{
	int	i;
	int j;
	while(i<j)
}
*/
int result(int dep[6], int tab[4][4])
{
	int k;
	int i;
	int j;
	int res;

	k=0;
	i=0;
	j=0;
	res=tab[i][j];
	while(k<6)
	{
		if(dep[k]==0)
			i++;
		else
			j++;
		res*=tab[i][j];
		k++;
	}
	return res;
}

void print_dep(int dep[6])
{
	int i;
	i=-1;
	while(++i<6)
		printf("%d ", dep[i]);
	printf("\n");
}

void max(int dep[6], int tab[4][4], int k, int i, int *maximum)
{
	if(k==4)
	{
		if(result(dep, tab) > *maximum)
		{
			*maximum = result(dep,tab);
		}
	}
	while(k<=3 && i<6)
	{
			dep[i]=k;
			max(dep, tab, k+1, i+1, maximum);
			dep[i]=0;
			i++;
	}
//	dep[i]=0;
//	i--;
}

int main(int argc, char **argv)
{
	if(argc==17)
	{
		int	tab[4][4];
		int dep[6];
		int i;
		int j;
		int k;
		int maximum;
		int prod;
		maximum=-2147483648;
		i=-1;
		k=1;
		while(++i<4)
		{
			j=-1;
			while(++j<4)
				tab[i][j]=atoi(argv[k++]);
		}
		i=-1;
		while(++i<6)
			dep[i]=0;
		print_tab(tab);
		max(dep, tab, 1, 0, &maximum);
		while(prod<maximum)
		{
			produit(tab, &prod);
			if(prod==maximum)
				printf("gagné !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			else
				printf("retente ta chance :(\n");
		}
	}
	return 0;
}
