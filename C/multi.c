/*                      */
/* 円周率の計算 revival */
/*                      */

#include "multi.h"

void wa(int u[],int v[],int w[]) /* w = u + v */
{
	int kuriagari = 0;
	int i;
	int add;

	for(i=N;i>=0;i--)
	{
		add = u[i] + v[i] + kuriagari;
		if(add > 10000)
		{
			w[i] = add - 10000;
			kuriagari = 1;
		}
		else
		{
			w[i] = add;
			kuriagari = 0;
		}
	}
}

void sa(int u[],int v[],int w[]) /* w = u - v */
{
	int kari = 0;
	int i;
	int sub;

	for(i=N;i>=0;i--)
	{
		sub = u[i] - kari;
		if(sub < v[i])
		{
			w[i] = sub + 10000 - v[i];
			kari = 1;
		}
		else
		{
			w[i] = sub - v[i];
			kari = 0;
		}
	}
}


void seki(int u[],int v,int w[]) /* w = u * v */
{
	int kuriagari = 0;
	int i;
	int mul;

	for(i=N;i>=0;i--)
	{
		mul = u[i] * v + kuriagari;
		if(mul > 10000)
		{
			w[i] = mul % 10000;
			kuriagari = mul/10000;
		}
		else
		{
			w[i] = mul;
			kuriagari = 0;
		}
	}
}

void shou(int u[],int v,int w[]) /* w = u / v */
{
	int amari = 0;
	int i;
	int div;

	for(i=0;i<N;i++)
	{
		div = u[i] + amari * 10000;
		w[i] = div / v;
		amari = div % v;
	}
}

void print(int u[])
{
    int i;

    printf("%1.1d.", u[0]);
    for(i=1;i<N;i++)
    {
        printf("%4.4d",u[i]);
    }
    putchar('\n');
}

void error(char *message)
{
    puts(message);
    exit(1);
}

int isnotzero(int u[])
{
    int i;
    int flag = 0;

    for(i=0;i<N;i++)
    {
	if(u[i] != 0)
	{
	    flag = 1;
	    break;
	}
    }

    return flag;
}

