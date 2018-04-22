#include "fillit.h"

char caractere(char **tab)
{
	int pos;

	pos = 0;
	while(tab[pos/4][pos%4] == '.')
		++ pos;
	return tab[pos/4][pos%4];
}

int 	square(int nbr)
{
	int n;

	n=0;
	while(n*n<nbr)
		++n;
	return n;
}

void ft_strcpy(char *src, char *dest, int i)
{
	int j;

	j = i;
	while(++j<4)
	{
		if (i == 0)
			dest[j] = src[j-1];
		else
			dest[j] = src[j];
	}
	dest[j] = '\0';
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
			write(1, &tab[i][j], 1);
		write(1, "\n", 1);
	}
	write(1, "\n",1);
}

void print_tab2(char ***tab, int size)
{
	int i;

	i = -1;
	while (++i <size)
	{
		print_tab(tab[i], 4);
		write(1, "\n", 1);
	}

}
/*
int test_trio(char **tab)
{
	int i;
	int j;

	i = -1;
	while(++i <4)
	{
		j = -1;
		while(++j<4)
			if(tab[i])
	}
}
*/
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


int skip_lines(char **tab, int i)
{
	int j;
	

	j= -1;
	while(++j < 4)
		if (tab[i][j] != '.')
			return 0;
	return 1;	
}

int skip_cols(char **tab, int i)
{
	int j;
	

	j= -1;
	while(++j < 4)
		if (tab[j][i] != '.')
			return 0;
	return 1;	
}

int test_line(char **tab, int piece)
{
	int i;

	i = 0;
	if(tab[piece/4][piece%4] !='.')
		i++;
	while(++piece%4 != 0)
		if(tab[piece/4][piece%4] !='.')
			i++;
	printf("test ligne =%d\n", i);
	return i;
}

int test_col(char **tab, int piece)
{
	int i;

	i = 0;
	while(piece/4 != 4)
	{
		if(tab[piece/4][piece%4] !='.')
			i++;
	piece += 4;
	}
//	printf("test col =%d\n", i);
	return i;
}

int test_piece(char **table, char **tab, int pos, int size)
{
	int piece;
	int init;
	int init2;
	int obst;

	obst = 0;
	init = pos;
	piece = 0;
	while(skip_lines(tab, piece/4) == 1)
		piece+=4;
	while(skip_cols(tab, piece%4) == 1)
		++piece;
	init2 = piece;
	while(pos<size*size && piece < 16)
	{
//	printf("position de test : ligne %d et col %d et piece = %d\n", pos/size, pos%size , piece);
		if(test_line(tab, piece)+(pos%size) >size || test_col(tab, piece) + (pos/size) >size)
		{
			printf("WHHHATTTT\n");
			return 0;
		}
		if(tab[piece/4][piece%4] != '.' && table[pos/size][pos%size]!='.')
		{
			return 0;
		}
		else if(tab[piece/4][piece%4] != '.' && table[pos/size][pos%size] == '.')
			++obst;
		piece++;
		if(piece%4 == 0)
		{
			piece+=(init2%4);
			pos = size*((piece-init2)/4) + init; 
		}
		else
			++pos;
	}
	if(obst!=4)
	{
		return 0;
	}
//	print_tab(table, size*size);
	return 1;
}

int place_piece(char **table, char **tab, int pos, int size)
{
	int piece;
	int init;
	int init2;

	init = pos;
	piece = 0;
	while(skip_lines(tab, piece/4) == 1)
		piece+=4;
	while(skip_cols(tab, piece%4) == 1)
		++piece;
	init2 = piece;
	while(test_piece(table, tab, pos, size) == 0 && pos<size*size)
	{
//		if(caractere(tab) == 'D')
		pos++;
	}
	printf("pos = %d\n", pos);
	if(pos == size*size)
		return 0;
	while(pos<size*size && piece < 16)
	{
		if(tab[piece/4][piece%4] != '.')
			table[pos/size][pos%size] = tab[piece/4][piece%4];
		piece++;
		if(piece%4 == 0)
		{
			piece+=(init2%4);
			pos = size*((piece-init2)/4) + init; 
		}
		else
			++pos;
	}
	if(piece<=15)
		return 0;
//	print_tab(table, size*size);
	return 1;
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

void remove_piece(char **table, char **tab, int size)
{
	char a;
	int pos;

	pos = 0;
	while(tab[pos/4][pos%4] =='.')
		pos++;
	a = tab[pos/4][pos%4];
	pos = -1;
	while(++pos<size*size)
		if(table[pos/size][pos%size] == a)
			table[pos/size][pos%size] ='.';
//	printf("try\n");
}

int factorial(int nbr)
{
	int result;

	result = 1;
	while(nbr>0)
		result *= nbr--;
	return result;
}
