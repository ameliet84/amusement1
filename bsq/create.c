#include "bsq.h"

void create_line(char *ligne, char empty, char obst, int col)
{
	int alea;
	int i;

	i=-1;
	while(++i<col)
	{
			alea=rand()%7;
			if(alea==0)
				ligne[i]=obst;
			else 
				ligne[i]=empty;
		}
}

void create(char **argv)
{
	int fd;
	int line;
	int col;
	char empty;
	char full;
	char obst;
	int i;
	srand(time(NULL));

	line=atoi(argv[2]);
	col=atoi(argv[3]);
	char *ligne;
	empty=argv[4][0];
	obst=argv[4][1];
	full=argv[4][2];
	i=-1;
	printf("line =%d, col =%d, empty=%c, obst=%c, full=%c\n", line, col, empty, obst, full);
	fd=open(argv[1], O_CREAT | O_WRONLY);
	while(*argv[2])
		write(fd, argv[2]++,1);
	write(fd, &empty,1);
	write(fd, &obst, 1);
	write(fd, &full, 1);
	write(fd, "\r", 1);
	write(fd,"\n",1);
	while(++i<line)
	{
		ligne=malloc(sizeof(char )*col);
		create_line(ligne, empty, obst, col);
		write(fd, ligne, col);
		free(ligne);
		write(fd, "\r", 1);
		write(fd, "\n", 1);
	}
	close(fd);
}

int main(int argc, char **argv)
{
	if(argc==5)
		create(argv);
	else
		printf("pas le bon nombre d'arguments\n");
	return 0;
}