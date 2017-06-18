/*                      */
/* 円周率の計算 revival */
/*                      */

#include <stdio.h>

int arctan(int,int[],int);
int wa(int[],int[],int[]);
int sa(int[],int[],int[]);
int seki();
int shou();

int main(void)
{
	int s1[252];
	int s2[252];
	int i;

	arctan(5,s1,716);
	seki(s1,16,s1);
	arctan(239,s2,210);
	seki(s2,4,s2);
	sa(s1,s2,s1);

	printf("\n円周率の計算 (1000桁まで)\n\n");
	printf("(円周率)=\n");
	printf("%1.1d.", s1[0]);

	for(i=1;i<251;i++)
	{
		printf("%4.4d",s1[i]);
		if(i%15==0) putchar('\n');
	}
	putchar('\n');
	return 0;
}

int arctan(int l, int w[], int max)
{
	int i,j,fugou;
	int u[252];
	int v[252];

	for(i=0;i<252;i++)
	{
		u[i]=v[i]=w[i]=0;
	}

	u[1]=10000;
	shou(u,l,u);
	
	for(i=0;i<252;i++)
	{
		w[i]=u[i];
	}

	fugou = -1;
	for(j=1;j<max;j++)
	{
		shou(u,l,u);
		shou(u,l,u);
		shou(u,2*j+1,v);
		if(fugou == -1)
		{
			sa(w,v,w);
			fugou = 1;
		}
		else if(fugou == 1)
		{
			wa(w,v,w);
			fugou = -1;
		}
	}

	for(i=0;i<252;i++)
	{
		return w[i];
	}
}

int wa(int u[],int v[],int w[]) /* w = u + v */
{
	int kuriagari = 0;
	int i;
	int add;

	for(i=251;i>=0;i--)
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

	for(i=0;i<252;i++)
	{
		return w[i];
	}
}

int sa(int u[],int v[],int w[]) /* w = u - v */
{
	int kari = 0;
	int i;
	int sub;

	for(i=251;i>=0;i--)
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

	for(i=0;i<252;i++)
	{
		return w[i];
	}
}


int seki(int u[],int v,int w[]) /* w = u * v */
{
	int kuriagari = 0;
	int i;
	int mul;

	for(i=251;i>=0;i--)
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


	for(i=0;i<252;i++)
	{
		return w[i];
	}
}

int shou(int u[],int v,int w[]) /* w = u / v */
{
	int amari = 0;
	int i;
	int div;

	for(i=0;i<252;i++)
	{
		div = u[i] + amari * 10000;
		w[i] = div / v;
		amari = div % v;
	}

	for(i=0;i<252;i++)
	{
		return w[i];
	}
}

