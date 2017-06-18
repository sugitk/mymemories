/* $B%"%k%4%j%:%`35O@(B $B%l%]!<%H(B $BEA@h@8J,(B*/
/* 9751056 $B?yB<(B $B5.;N(B                 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* $B:GBgC18lD9(B */
#define M 5

/* $BL58BBg$N$h$&$J$b$N(B */
#define INFTY 1024

/* $BF~NOJ8;zNs(B */
static const char String[] = "asumosinaitone";
#define Length 15 /* 0$B!A(B14 */

/* $B%0%i%U(B */
int graph[Length][Length];

/* $B<-=qDj5A(B */
typedef struct
{
	char word[M];
	int penalty;
} Dic;

Dic dic[] = {{"asu", 7}, {"si", 3}, {"sinai", 7},
             {"to", 3}, {"tone", 7}, {"nai", 2},
             {"naito", 7}, {"ne", 1}, {"mo", 1}, {"mosi", 5}};

/* $B4X?tDj5A(B */
void error();
int match(Dic);
void makegraph();
void least_penalty();
void put_answer();

/* error */
void error()
{
	puts("Error occurred.");
	exit(1);
}

/* $BJ8;zNs>H9g(B $B:G$b(Bsimple$B$J%"%k%4%j%:%`(B */
int match(Dic d)
{
	int ptn_length = strlen(d.word);

	int i = 0;
	int j = 0;

	while(j < ptn_length)
	{
		if(String[i] == d.word[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 1; j = 0;	
		}
	}

	if(j == ptn_length)
		return (i - j);
	else return -1;
}

/* $B%0%i%U:n@.(B */
void makegraph()
{
	int i,j;
	int pos; /* $BJ8;z$N>l=j(B */
	int num; /* Dic$BG[Ns$NMWAG?t(B */

	/* $B%0%i%U$N=i4|2=(B */
	for(i=0;i<Length;i++)
	{
		for(j=0;j<Length;j++) graph[i][j] = INFTY;
	}

	/* $B=E$_$E$1(B */
	
	num = sizeof(dic)/sizeof(dic[0]);
	for(i=0;i<num;i++)
	{
		int ptn_pos = match(dic[i]); /* $B%Q%?!<%s$N8+$D$+$C$?>l=j(B */
		int ptn_length = strlen(dic[i].word); /* $B%Q%?!<%s$ND9$5(B */
	
		if(ptn_pos == -1) error();
		graph[ptn_pos][ptn_pos+ptn_length] = dic[i].penalty;
	}
}

/* $B:GC;7PO)(B floyd$B$N%"%k%4%j%:%`(B */
void least_penalty()
{
	int i,j,k;

	for(k=0;k<Length;k++)
	{
		for(i=0;i<Length;i++)
		{
			for(j=0;j<Length;j++)
			{
				if(graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

/* $B7k2L=PNO(B */
void put_answer()
{
	int i;

	printf("$B:G>.$NH36b$O(B %d $B$G$9!#(B\n", graph[0][Length-1]);
	printf("$B6h@Z$j$O$3$N$h$&$K$J$j$^$9!#(B\n");

	for(i=0;i<Length;i++)
	{
		putchar(String[i]);
		if(graph[0][i+1] < INFTY)
		{
			putchar('/');
		}	
	}
	putchar('\n');
}

/* main */
int main()
{
	makegraph();
	least_penalty();
	put_answer();

	return 0;
}

