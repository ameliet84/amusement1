#include "fillit.h"

/*
char last_letter(char **tab, int size)
{
	int i;
	int j;

	i=size;
	while(--i>=0)
	{
		j = size;
		while(--j>=0)
			if(tab[i][j]!='.')
				return tab[i][j];
	}
	return '.';
}

char first_letter(char **tab, int size)
{	

	int i;
	int j;

	i=-1;
	while(++i <size)
	{
		j = -1;;
		while(++j < size)
			if(tab[i][j]!='.')
				return tab[i][j];
	}
	return '.';
}

int possible(char **table, t_piece **tab)
{
	int i;
	int j;
	int size;

	size = length(table);
	i =-1;
	while(++i<size)
	{
		j = -1;
		while(++j<size)
			if(test_piece(table, tab, i, j, size) == 1)
				return 1;
	}
	return 0;
}

*/

int test_tab1(char **tab, int i, int j, int size)
{
	int l;

	l = -1;
	while(++l <  2 && j + l<size)
		if(tab[i][j+l] == '.')
			return 1;
	return 0;
}

int test_tab2(char **tab, int i, int j, int size)
{
	int l;

	l = -1;
	while(++l <  2 && i + l<size)
		if(tab[i+l][j] == '.')
			return 1;
	return 0;
}

int finish(t_piece **tab, int i, int j)
{
	while(++j<4)
		if(tab[i][j].car != '.')
			return 0;
	while(++i<4)
	{
		j = -1;
		while(++j<4)
		{
			if(tab[i][j].car!= '.')
				return 0;
		}
	}
	return 1;
}


int ligne(t_piece **tab, int i, int j)
{
	int count;

	count = 0;
	--j;
	while(++j < 4)
		if(tab[i][j].car !='.')
			++count;
//			count=(tab[i][j].car!='.')? k-j+1:k-j;
	return count;
}

int colonne(t_piece **tab, int i, int j)
{
	int count;

	count = 0;
	--i;
	while(++ i <4)
		if(tab[i][j].car >='A' && tab[i][j].car<='Z')
			++count;
	//		count=(tab[i][j].car =='.')? k - i : k- i + 1;
	return count;
}

void coord(t_piece **tab, int i, int j, int k)
{
	if(k == 0)
	{
		(tab[0][0].coord1).x = i;
		(tab[0][0].coord1).y = j;
	}
	else if(k == 1)
	{
		(tab[0][0].coord2).x = i;
		(tab[0][0].coord2).y = j;
	}
	else if(k == 2)
	{
		(tab[0][0].coord3).x = i;
		(tab[0][0].coord3).y = j;
	}
		else if(k == 3)
	{
		(tab[0][0].coord4).x = i;
		(tab[0][0].coord4).y = j;
	}

}

void reduce_piece(t_piece **tab)
{
	int initx;
	int inity;
	int i;
	int j;

	initx = tab[0][0].init/4;
	inity = tab[0][0].init%4;
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++j<4)
			if(i+initx<4 && j+inity<4)
				tab[i][j] = tab[i+initx][j+inity];
			else
				tab[i][j].car = '.';
	}

}

void coord2(t_piece **tab)
{
	int i;
	int j;
	int k;
	t_coord max;

	i =-1;
	k = 0;
	max.x = 0;
	max.y = 0;
	while(++i<4)
	{
		j = -1;
		while(++j<4)
			if(tab[i][j].car!='.')
			{
				if(i>max.x)
					max.x = i;
				if(j>max.y)
					max.y = j;
				coord(tab, i, j, k);
				++k;
			}
	}
	tab[0][0].maxi = max.x+1;
	tab[0][0].maxj = max.y+1;
}

void treat_trio2(t_piece **tab, int l)
{
	int i;
	int j;
//	int maxi;
//	int maxj;

//	maxi = 0;
//	maxj = 0;
	i = 0;
	j = 0;
	while(skip_lines(tab, i) == 1)
		++i;
	while(skip_cols(tab, j) == 1)
		++j;
	tab[0][0].init = i*4 + j;
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++j<4)
		{
			if (tab[i][j].car =='.' && finish(tab, i, j) == 1)
			{
				tab[i][j].line = -1;
				break;
			}
			else
			{
				tab[i][j].line = ligne(tab, i, j);
//				if(tab[i][j].line>maxi)
//					maxi = tab[i][j].line;
				tab[i][j].col = colonne(tab, i, j);
//				if(tab[i][j].col>maxj)
//					maxj = tab[i][j].col;
			}
		}
	}
	tab[3][3].line = -1;
//	tab[0][0].maxi = maxi;
//	tab[0][0].maxj = maxj;
	reduce_piece(tab);
	coord2(tab);
	tab[0][0].letter = 'A' +l;
}

int 	square(int nbr)
{
	int n;

	n=0;
	while(n*n<nbr)
		++n;
	return n;
}

void ft_strcpy(char *src, char *dest)
{
	int j;

	j = 0;
	while(++j<4)
			dest[j] = src[j-1];
}

void ft_strcpy2(char *src, t_piece *dest)
{
	int j;

	j = -1;
	while(++j<4)
	dest[j].car = src[j];
	dest[j].car = '\0';
}

void print_tab(char **tab, int size)
{
	int i;
	int j;

	i = -1;
	while(++i<size)
	{
		j = -1;
		while(++j<size)
		{
				write(1, &tab[i][j], 1);
		}
			write(1, "\n", 1);
	}
	write(1, "\n",1);
}


void print_tab2(t_piece ***tab, int size)
{
	int k;
	int j;
	int i;

	k = -1;
	while (++k <size)
	{

	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++j<4)
				printf("%c", tab[k][i][j].car);
		printf("\n");
	}
	printf("maxi i = %d maxj = %d\n", tab[k][0][0].maxi, tab[k][0][0].maxj);
//	printf("coord 1 x = %d coord1 y = %d\n", (tab[k][0][0].coord1).x,(tab[k][0][0].coord1).y );
//	printf("coord 2 x = %d coord2 y = %d\n", (tab[k][0][0].coord2).x,(tab[k][0][0].coord2).y );
//	printf("coord 3 x = %d coord3 y = %d\n", (tab[k][0][0].coord3).x,(tab[k][0][0].coord3).y );
//	printf("coord 4 x = %d coord4 y = %d\n", (tab[k][0][0].coord4).x,(tab[k][0][0].coord4).y );

		write(1, "\n",1);
		write(1, "\n", 1);
	}


}


int test_trio2(t_piece **tab, int i, int j)
{
	int nbr;

	nbr = 0;
	if(i>0 && tab[i-1][j].car != '.') 
		++nbr;
	if(i<3 && tab[i+1][j].car != '.')
		++nbr;
	if(j>0 && tab[i][j-1].car != '.') 
		++nbr;
	if(j<3 && tab[i][j+1].car != '.')
		++nbr;
	return nbr;
}

int test_trio(t_piece **tab)
{
	int i;
	int j;
	int nbr;

	i = -1;
	nbr = 0;
	while(++i <4)
	{
		j = -1;
		while(++j<4)
			if((tab[i][j].car!= '.' && test_trio2(tab, i, j) == 0))
				return 0;
			else if(tab[i][j].car != '.' && test_trio2(tab, i, j)>nbr)
				nbr = test_trio2(tab, i, j);
	}
	if(nbr == 1)
		return 0;
	return 1;
}

int treat_trio(char a, char *str, int *n)
{
	int i;

	i = -1;
	while(++i <4)
		if(str[i] == '#')
		{
			++(*n);
			str[i] = a;
		}
		else if(str[i] !='.' && str[i] != '#')
			return 0;
	return 1;
}

char **create_tab(int size)
{
	char **tab;
	int i;

	i = -1;
	tab = malloc(sizeof(char *)*size);
	while(++i<size)
		tab[i] = malloc(sizeof(char) * size);
	return tab;
}


int skip_lines(t_piece **tab, int i)
{
	int j;
	
	j= -1;
	while(++j < 4)
		if (tab[i][j].car != '.')
			return 0;
	return 1;	
}

int skip_cols(t_piece **tab, int i)
{
	int j;
	

	j= -1;
	while(++j < 4)
		if (tab[j][i].car != '.')
			return 0;
	return 1;	
}


int test_piece(char **table, t_piece **tab, int i, int j)
{
	if( table[(tab[0][0].coord1).x+i][(tab[0][0].coord1).y + j] != '.')
		return 0;
	if( table[(tab[0][0].coord2).x+i][(tab[0][0].coord2).y + j] != '.')
		return 0;
	if( table[(tab[0][0].coord3).x+i][(tab[0][0].coord3).y + j] != '.')
		return 0;
	if( table[(tab[0][0].coord4).x+i][(tab[0][0].coord4).y + j] != '.')
		return 0;
	return 1;
}



void place_piece(char **table, t_piece **tab, int i, int j)
{
	char a;

	a = tab[0][0].letter;
	table[(tab[0][0].coord1).x+i][(tab[0][0].coord1).y + j] = a;
	table[(tab[0][0].coord2).x+i][(tab[0][0].coord2).y + j] = a;
	table[(tab[0][0].coord3).x+i][(tab[0][0].coord3).y + j] = a;
	table[(tab[0][0].coord4).x+i][(tab[0][0].coord4).y + j] = a;

}


void init_table(char **table, int size)
{
	int i;

	i=-1;
	while(++i<size*size)
		table[i/size][i%size] = '.';
}

int length(char **tab)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while(tab[0][++i])
		j++;
	return j;
}

void remove_piece(char **table, t_piece **tab, int i, int j)
{
	table[(tab[0][0].coord1).x+i][(tab[0][0].coord1).y + j] = '.';
	table[(tab[0][0].coord2).x+i][(tab[0][0].coord2).y + j] = '.';
	table[(tab[0][0].coord3).x+i][(tab[0][0].coord3).y + j] = '.';
	table[(tab[0][0].coord4).x+i][(tab[0][0].coord4).y + j] = '.';
}
