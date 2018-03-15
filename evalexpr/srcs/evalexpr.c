#include "do_op.h"

int test_gauche(char *str, int i)
{
	int j;

	j=i;
	while(str[++j])
		if(str[j]=='(')
			return 0;
	return 1;
}

int test_droit(char *str, int i)
{
	int j;

	j=i;
	while(str[++j])
		if(str[j]==')')
			return j;
	return 0;
}

int test_parentheses(char *str)
{
	int i;

	i=-1;
	while(str[++i])
		if(str[i]=='(')
			return 1;
	return 0;
}

void parentheses(char *str)
{
	char *expr;
	int n;
	int m;
	int i;

	i=-1;	
	while(str[++i])
	{
		if(str[i]=='(' && test_gauche(str, i)==1)
		{
			n=i;
			m=test_droit(str, i);
			i=length(str);
		}
	}
	expr=malloc(sizeof(char)*(m-n));
	i=n;
	while(++i<m)
		expr[i-1-n]=str[i];
	expr[m-n]='\0';
	simple(expr);
	fusion(str, expr, n, m+1);
}

int test_priorite(char *str)
{
	int i;

	i=-1;
	while(str[++i])
		if(str[i]=='*' || str[i]=='/' || str[i]=='%')
			return i;
	return 0;
}

int negatif(char *str, int i)
{
	int j;

	j=i;
	while((str[j]>='0' && str[j]<='9') || str[j]==' ')
		j--;
	if((str[j]=='+' ||str[j]=='-') &&(j==0 || (str[j-1]<'0' ||str[j-1]>'9')))
		j--;
	j++;
	return j;
}

int chaine(char *str, char *nbre, int i)
{
	int b;
	int j;

	j=i;
	b=0;
	if(str[j+1]=='+' || str[j+1]=='-')
	{
		if(str[j+1]=='-')
		{
			nbre[0]='-';
			b++;
		}
		j++;
	}
	while(str[++j] && ((str[j]>='0' && str[j]<='9')||str[j]==' '))
		nbre[b++]=str[j];
	nbre[b]='\0';
	return j;
}

void priorite(char *str)
{
	int i;
	int m;
	int l;
	char *nbre;
	int a;
	
	m=test_priorite(str);
	i=negatif(str, m-1);	
	nbre= malloc(sizeof(char)* length(str));
	a=0;
	while(i<m)
		nbre[a++]=str[i++];
	nbre[a]='\0';
	a=ft_atoi(nbre);
	l=chaine(str, nbre, m);
	fusion(str, nbr(do_op(a, ft_atoi(nbre), str[m])), negatif(str, m-1), l);
	printf("%s\n", str);
}

int test_sum(char *str)
{
	int i;

	i=-1;
	while(str[++i])
		if(str[i]=='+' || (str[i]=='-' && (i!=0 && (str[i-1]>='0' && str[i-1]<='9'))))
			return i;
	return 0;
}

void sum(char *str)
{
	int i;
	int m;
	int l;
	char *nbre;
	int a;

	m=test_sum(str);
	i=negatif(str, m-1);	
	nbre= malloc(sizeof(char)* length(str));
	a=0;
	while(i<m)
		nbre[a++]=str[i++];
	nbre[a]='\0';
	a=ft_atoi(nbre);
	l=chaine(str, nbre, m);
	fusion(str, nbr(do_op(a, ft_atoi(nbre), str[m])), negatif(str, m-1), l);
	printf("%s\n", str);
}

void simple(char *str)
{
	while(test_priorite(str)!=0)
		priorite(str);
	while(test_sum(str)!=0)
		sum(str);
}

int eval_expr(char *str)
{
	split_white(str);
	while(test_parentheses(str)!=0)
		parentheses(str);
	simple(str);
	return(ft_atoi(str));
}


int main(int argc, char **argv)
{
	if(argc>1)
	{
		ft_putnbr(eval_expr(argv[1]));
		write(1, "\n", 1);
	}
	return 0;
}