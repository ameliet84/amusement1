#include "bsq.h"

void create(char **argv)
{
	int fd;
	int line;
	int col;
	char empty;
	char full;
	char obst;
	int i;
	int j;
	int alea;

	line=atoi(argv[2]);
	col=atoi(argv[3]);
	empty=argv[4][0];
	obst=argv[4][1];
	full=argv[4][2];
	srand(time(NULL));

	printf("line =%d, col =%d, empty=%c, obst=%c, full=%c\n", line, col, empty, obst, full);
	fd=open(argv[1], O_CREAT, S_IRWXU);
	printf("fd=%d\n", fd);
	while(*argv[2])
		write(fd, argv[2]++,1);
	write(d, &empty,1);
	write(fd, &obst, 1);
	write(fd, &full, 1);
	write(fd, "\n", 1);
	i=-1;
	while(++i<line)
	{
		j=-1;
		while(++j<col)
		{
			alea=rand()%2;
			if(alea==0)
				write(fd, &empty, 1);
			else if(alea==1)
				write(fd, &obst, 1);
		}
		write(1, "\n", 1);
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