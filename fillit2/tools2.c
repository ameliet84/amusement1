#include "fillit.h"

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

void treat_trio2(t_piece **tab, int l)
{
	int i;
	int j;
	int maxi;
	int maxj;

	maxi = 0;
	maxj = 0;
	i = 0;
	j = 0;
	tab[0][0].letter = 'A' +l;
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
				if(tab[i][j].line>maxi)
					maxi = tab[i][j].line;
				tab[i][j].col = colonne(tab, i, j);
				if(tab[i][j].col>maxj)
					maxj = tab[i][j].col;
			}
		}
	}
	tab[15][15].line = -1;
	tab[0][0].maxi = maxi;
	tab[0][0].maxj = maxj;
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


int test_piece(char **table, t_piece **tab, int i, int j, int size)
{
	int piece;
	int init;
	int init2;
	int line;

	init = j;
	piece = tab[0][0].init;
	init2 = piece;
	line = tab[piece/4][piece%4].line;
	while(line != -1 && piece < 16)
	{
		if(tab[piece/4][piece%4].car !='.' && (i>=size || j>=size || table[i][j]!='.'))
			return 0;
		++piece;
		++j;
		if(piece%4 == 0)
		{
			piece+=(init2%4);
			++i;
			j = init;
		}
		if(piece<16)
			line = tab[piece/4][piece%4].line;
	}
	return 1;
}



void place_piece(char **table, t_piece **tab, int i, int j)
{
	int piece;
	int init;
	int init2;
	int line;

	init = j;
	piece = tab[0][0].init;
	init2 = piece;
	line = tab[piece/4][piece%4].line;
	while(line!=-1 && piece < 16)
	{
		if(tab[piece/4][piece%4].car != '.')
			table[i][j] = tab[piece/4][piece%4].car;
		piece++;
		j++;
		if(piece%4 == 0)
		{
			piece+=init2%4;
			++i;
			j = init;
		}
		if(piece<16)
			line = tab[piece/4][piece%4].line;
	}
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

void remove_piece(char **table, t_piece **tab, int i, int j, int size)
{
	char a;
	int k;
	int count;

	count = -1;
	a = tab[0][0].letter;
	while(++count<4 && i+count < size)
	{	
		k = -1;
		while(++k<4 && j+k <size)
			if(table[i+count][j+k] == a)
			{
				table[i+count][j+k] ='.';
			}
	} 
}
