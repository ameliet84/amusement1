#include"do_op.h"

int	test(char o, t_opp *gl_opptab)
{
	int	i;

	i=-1;
	while(++i<5)
		if(gl_opptab[i].opp==o)
			return 1;
	return 0;
}

int test_expr(int b, char c)
{
	if(c=='/' && b==0)
		{
			write(1, "Stop : division by zero\n", 24);
			return 0;
		}
	else if(c=='%' && b==0)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return 0;
		}
	return 1;
}

int do_op(int a, int b, char c)
{
	int nb;
	int i;
	t_opp gl_opptab[]={{'-', &ft_sub},\
	{'+', &ft_add},\
	{'*', &ft_mul},\
	{'/', &ft_div},\
	{'%', &ft_mod}};

		
		if(test_expr(b, c)==1)
		{
			if (test(c, gl_opptab)==1)
			{
				i=-1;
				while(++i<5)
					if(c==gl_opptab[i].opp)
					{
						nb=gl_opptab[i].ft(a, b);
					}
			}
		}
	return nb;
}