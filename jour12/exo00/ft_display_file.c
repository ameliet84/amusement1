#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc==1)
		write(2, "File name is missing", 21);
	else if(argc==2)
	{
		int op;
		char c;

		op=open(argv[1], O_RDONLY);
		while(read(op, &c, 1)>0)
			write(1, &c, 1);
	}
	else
		write(2, "Too many arguments", 18);
	write(1, "\n",1);
	return 0;
}