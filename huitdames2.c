#include <stdio.h>

int count=0;

void initialiser_tableau(int tab[8][8])
{
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{	tab[i][j]=0;	}
	}
}

void ligne(int *l, int i, int j, int tab[8][8])
{

	for (int k=0; k<j; k++)
	{
		if (k!=j)
		{
			if (tab[i][k]==1)
			*l=1;
		}
	}
}

void colonne(int *c,int i, int j, int tab[8][8])
{
	for (int k=0; k<i; k++)
	{
		if (k!=i)
		{
		if (tab[k][j]==1)
		*c=1;
		}
	}
}

void diagonales(int *d, int i, int j, int tab[8][8])
{

	int k;
/*	for (k=1; k<8; k++)
	{
		if (i+k <=8 && j-k>=0)
		{
			if (tab[i+k][j-k]==1)
			*d=1;
		}
	}
	for (k=1; k<8; k++)
	{
		if (i+k<=8 && j+k<=8)
		{
			if (tab[i+k][j+k]==1)
			*d=1;
		}
	}

*/	for (k=1; k<8; k++)
	{
		if (i-k>=0 && j+k<=8)
		{
			if (tab[i-k][j+k]==1)
			*d=1;
		}
	}

	for (k=1; k<8; k++)
	{
		if (i-k>=0 && j-k>=0)
		{
			if (tab[i-k][j-k]==1)
			*d =1;
		}
	}
}

/*void remplir_autour(int r, int i, int j,int tab[8][8])
{
ligne(r, i, j, tab);
colonne(r, i, j, tab);
diagonales(r, i, j, tab);
}
*/
void placer_une_dame(int *test,int *position, int tab[8][8])
{
int *l, *c, *d;
int li=0, co=0, di=0;
l=&li;
c=&co;
d=&di;
*test=0;

int i=*position/8, j=*position%8;
ligne(l,i, j, tab);
colonne(c, i,j,tab);
diagonales(d, i,j,tab);
		if(*l==0 && *c ==0 && *d==0)
		{
		*test=1;/*
		tab[i][j]=1;
		(*dames)++;*/
		}
//remplir_autour(r, i, j, tab);
}

void affiche_tableau(int tab[8][8])
{
	for (int i=0; i<8; i++)
	{
		for (int j=0; j<8; j++)
		{
			printf("%d  ", tab[i][j]);
		}
	printf("\n");
	}
printf("\n\n\n");
}

void placer_dames(int te, int da, int po, int tab[8][8])

{
int  *position, *test;
test=&te;
position=&po;

	if (da ==8)
	{	count ++;
		affiche_tableau(tab);
		printf("il y a %d solutions\n", count);
		
	}
	while (po<64)
	{
		int i=po/8, j=po%8;
		placer_une_dame(test,  position, tab);
		if (tab[i][j]==0 && te==1)
		{ 	tab[i][j]=1;
			da++;
	//		printf("il y a %d dames\n", da);
	//		affiche_tableau(tab);
			placer_dames(te, da, po+1, tab);
			--da;
			tab[i][j]=0;
			po++;

			//remplir_autour(-2, i, j, tab);
	//		affiche_tableau(tab);
		}	
		else
		{++po;}
	}


}


int main(void)
{

int tab[8][8];

initialiser_tableau(tab);
placer_dames(0, 0,7, tab);

return 0;
}

