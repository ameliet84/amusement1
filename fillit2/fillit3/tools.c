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
	int k;

	count = 0;
	k = j;
	while(++k < 4)
		if(tab[i][k].car !='.')
			count=k-j;
	return count;
}

int colonne(t_piece **tab, int i, int j)
{
	int k;
	int count;

	count = 0;
	k = i;
	while(++ k <4)
		if(tab[k][j].car !='.')
			count=k - i;
	return count;
}

void treat_trio2(t_piece **tab, int l)
{
	int i;
	int j;
	int init;
	int pos;

	i = 0;
	j = 0;
	tab[0][0].letter = 'A' +l;
	while(skip_lines(tab, i) == 1)
		++i;
	while(skip_cols(tab, j) == 1)
		++j;
	
	init = i*4 + j;
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++j<4)
		{
			pos = 4*i+j;
			if (pos>0 && tab[(pos-1)/4][(pos-1)%4].car == '.' && tab[i][j].car =='.' && finish(tab, i, j) == 1)
			{
				tab[i][j].line = -1;
				return;
			}
			else
			{
				tab[i][j].init = init;
				tab[i][j].line = ligne(tab, i, j);
				tab[i][j].col = colonne(tab, i, j);
			}
		}
	}

}

char caractere(t_piece **tab)
{
	int pos;

	pos = 0;
	while(tab[pos/4][pos%4].car == '.')
		++ pos;
	return tab[pos/4][pos%4].car;
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
				printf("%c*%d*%d  ", tab[k][i][j].car, tab[k][i][j].line, tab[k][i][j].col);
		printf("\n");
	}
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
			(*n)++;
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


int test_piece2(int pos, char **table, int size)
{
	if(pos/size>=size || pos%size>=size)
		return 0;
	if(table[pos/size][pos%size] != '.')
		return 0;
	return 1;
}


int test_piece(char **table, t_piece **tab, int pos, int size)
{
	int piece;
	int init;
	int init2;
	int line;
	int nb;

	nb = 0;
	init = pos;
	piece = tab[0][0].init;
	init2 = piece;
	line = tab[piece/4][piece%4].line;
	if(pos>=size*size-4)
		return 0;
	while(piece < 16 && line != -1)
	{
//	printf("caractère = %c pos = %d , piece = %d et init = %d et ligne = %d et col = %d\n", caractere(tab), pos, piece, tab[piece/4][piece%4].init,tab[piece/4][piece%4].line, tab[piece/4][piece%4].col);
		if(nb == 4)
			return 1;
		if((tab[piece/4][piece%4].car != '.' && (table[pos/size][pos%size] != '.'
													||pos/size!=(size*((piece-init2)/4)+init)/size))
				||/*piece%4+*/(line+(pos%size) >size|| /*piece/4 +*/ tab[piece/4][piece%4].col + (pos/size) >size))
		{
			remove_piece(table, tab, size, init-1);
			return test_piece(table, tab, pos+1, size);
		}
		if(tab[piece/4][piece%4].car != '.')
		{
			++nb;
			table[pos/size][pos%size] = tab[piece/4][piece%4].car;
		}
		++piece;
		pos = (piece%4 == 0) ? size*(((piece+init2%4)-init2)/4) + init : pos +1;
		if(piece%4 == 0)
			piece+=(init2%4);
		if(pos>=size*size && tab[piece/4][piece%4].line != -1)
			return 0;
		line = tab[piece/4][piece%4].line;
	}
	return 0;
}



void place_piece(char **table, t_piece **tab, int pos, int size)
{
	int piece;
	int init;
	int init2;

	init = pos;
	piece = 0;
	piece = tab[0][0].init;
	init2 = piece;
	while(pos<size*size && piece < 16)
	{
		if(tab[piece/4][piece%4].car != '.')
			table[pos/size][pos%size] = tab[piece/4][piece%4].car;
		piece++;
				pos = (piece%4 == 0) ? size*(((piece+init2%4)-init2)/4) + init : pos +1;
		if(piece%4 == 0)
			piece+=(init2%4);
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

void remove_piece(char **table, t_piece **tab, int size, int init)
{
	char a;
	int k;

	k = 0;
	a = tab[0][0].letter;
	while(k<3 && ++init<size*size)
		if(table[init/size][init%size] == a)
		{
			++k;
			table[init/size][init%size] ='.';
		}
}
