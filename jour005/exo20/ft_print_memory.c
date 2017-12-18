#include<stdio.h>
#include<unistd.h>

void ft_putchar(char c)
{
write(1, &c, 1);
}



void print_hexa(long nb)
{
char base[]="0123456789abcedf";

if (nb/16>0)
print_hexa(nb/16);

write(1, base + nb%16, 1);
}


void *ft_print_memory(void *addr, unsigned int size)
{
unsigned int i=0, temp = 0;
char *c= (char *)addr;

while (temp  <= size)
{
print_hexa((long)addr+temp);
ft_putchar (':');
	
	while (i<16 && temp + i<size)
	{
	if(c[temp + i]<16)
	ft_putchar('0');
	print_hexa(c[temp + i]);
	i++;
		if (i%2 ==0||temp + i==size)
		ft_putchar(' ');
	}
i=0;
	while (i<16 &&temp +i<size)
	{
		if ((c[temp + i]>=0 && c[temp +i]<=31)||c[temp +i]==127)
		ft_putchar('.');
		else
		write (1, addr+temp+i, 1);		 

	i++;
		if (i%16==0||temp + i==size)
		{
		ft_putchar('\n');
		}
	}
temp +=16;
i=0;
}

return addr;
}

int main(void) 
{
char a[]="salut		a tous bonjour, ca fait chier ces conneries 00123";
void *addr;
addr=&a;

ft_print_memory(addr, 60);

return 0;
}


