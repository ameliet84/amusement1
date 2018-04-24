#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

char **trio1(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	j = -1;
	while(++ j<4)
		tab[0][j] = '#';
	i = 0;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			tab[i][j] = '.';
	}
	return tab;
}

char **trio2(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);
	i = -1;
	while(++ i<4)
		tab[i][0] = '#';
	i = -1;
	while(++i<4)
	{
		j = 0;
		while(++ j < 4)
			tab[i][j] = '.';
	}
	return tab;
}

char **trio3(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	i = -1;
	while(++ i<2)
	{
		j = -1;
		while(++j < 2)
			tab[i][j] = '#';
	}
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j]!='#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio4(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[0][0] = '#';
	i = -1;
	while(++ i<3)
		tab[i][1] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio5(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[1][1] = '#';
	i = -1;
	while(++ i<3)
		tab[i][0] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio6(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);
	tab[2][0] = '#';
	i = -1;
	while(++ i<3)
		tab[i][1] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio7(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);
	tab[2][1] = '#';
	i = -1;
	while(++ i<3)
		tab[i][0] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio8(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[0][0] = '#';
	j = -1;
	while(++ j<3)
		tab[1][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio9(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[1][0] = '#';
	j = -1;
	while(++ j<3)
		tab[0][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio10(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[0][2] = '#';
	j = -1;
	while(++ j<3)
		tab[1][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio11(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[1][2] = '#';
	j = -1;
	while(++ j<3)
		tab[0][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio12(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[1][1] = '#';
	j = -1;
	while(++ j<3)
		tab[0][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio13(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[0][1] = '#';
	j = -1;
	while(++ j<3)
		tab[1][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio14(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[1][1] = '#';
	i = -1;
	while(++ i<3)
		tab[i][0] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio15(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	tab[1][0] = '#';
	i = -1;
	while(++ i<3)
		tab[i][1] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio16(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	i = -1;
	while(++ i<2)
		tab[i][0] = '#';
	i = 0;
	while(++i<3)
		tab[i][1] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio17(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	i = -1;
	while(++ i<2)
		tab[i][1] = '#';
	i = 0;
	while(++i<3)
		tab[i][0] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio18(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	j = -1;
	while(++ j<2)
		tab[0][j] = '#';
	j = 0;
	while(++j<3)
		tab[1][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char **trio19(void)
{
	int i;
	int j;
	char **tab;

	i = -1;
	tab = malloc(sizeof(char *)*4);
	while(++ i<4)
		tab[i] = malloc(sizeof(char)* 4);

	j = -1;
	while(++ j<2)
		tab[1][j] = '#';
	j = 0;
	while(++j<3)
		tab[0][j] = '#';
	i = -1;
	while(++i<4)
	{
		j = -1;
		while(++ j < 4)
			if(tab[i][j] != '#')
				tab[i][j] = '.';
	}
	return tab;
}

char ***table_trio(void)
{
	char ***table;
	int i;
	int k;

	table = malloc(sizeof(char **)* 19);
	k = -1;
	while(++k<19)
	{
		table[k] = malloc(sizeof(char *)* 4);
		i = -1;
		while(++i<4)
			table[k][i] = malloc(sizeof(char)*4);
	}

	table[0] = trio1();
	table[1] = trio2();
	table[2] = trio3();
	table[3] = trio4();
	table[4] = trio5();
	table[5] = trio6();
	table[6] = trio7();
	table[7] = trio8();
	table[8] = trio9();
	table[9] = trio10();
	table[10] = trio11();
	table[11] = trio12();
	table[12] = trio13();
	table[13] = trio14();
	table[14] = trio15();
	table[15] = trio16();
	table[16] = trio17();
	table[17] = trio18();
	table[18] = trio19();

	return table;
}

char ***init_table(int nb)
{
	int i;
	int k;
	char ***table;

	table = malloc(sizeof(char **)* nb);
	k = -1;
	while(++k<nb)
	{
		table[k] = malloc(sizeof(char *)* 4);
		i = -1;
		while(++i<4)
			table[k][i] = malloc(sizeof(char)*4);
	}
 	return table;
}

void create_table(char ***tab, char ***table, int nb)
{
	int alea;
	int i;

	i = -1;
	while(++ i < nb)
	{
		alea = rand()%20;
		tab[i] = table[alea];
	}
}


void create_file(char *name, char ***tab, int nb)
{
	int k;
	int i;
	int j;
	int fd;

	k = -1;
	fd = open(name, O_WRONLY, O_CREAT);
	while(++k < nb)
	{
		i = -1;
		while(++ i<4)
		{
			j = -1;
			while(++j<4)
				write(fd, &tab[k][i][j], 1);
			write(fd, "\n", 1);
		}
		if(k<nb-1)
			write(fd, "\n", 1);
	}
}

int main(int argc, char **argv)
{
	char ***tab;
	char ***table;

	table = table_trio();
	printf("nom fichier puis nombre de triominos ?\n");
	srand(time(NULL));
	if(argc == 3)
	{
		tab = init_table(atoi(argv[2]));
		create_table(tab, table, atoi(argv[2]));
		create_file(argv[1], tab, atoi(argv[2]));
	}
	return 0;
}