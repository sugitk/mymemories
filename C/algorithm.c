/* アルゴリズム概論 レポート 伝先生分*/
/* 9751056 杉村 貴士                 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 最大単語長 */
#define M 5

/* 無限大のようなもの */
#define INFTY 1024

/* 入力文字列 */
static const char String[] = "asumosinaitone";
#define Length 15 /* 0〜14 */

/* グラフ */
int graph[Length][Length];

/* 辞書定義 */
typedef struct
{
	char word[M];
	int penalty;
} Dic;

Dic dic[] = {{"asu", 7}, {"si", 3}, {"sinai", 7},
             {"to", 3}, {"tone", 7}, {"nai", 2},
             {"naito", 7}, {"ne", 1}, {"mo", 1}, {"mosi", 5}};

/* 関数定義 */
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

/* 文字列照合 最もsimpleなアルゴリズム */
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

/* グラフ作成 */
void makegraph()
{
	int i,j;
	int pos; /* 文字の場所 */
	int num; /* Dic配列の要素数 */

	/* グラフの初期化 */
	for(i=0;i<Length;i++)
	{
		for(j=0;j<Length;j++) graph[i][j] = INFTY;
	}

	/* 重みづけ */
	
	num = sizeof(dic)/sizeof(dic[0]);
	for(i=0;i<num;i++)
	{
		int ptn_pos = match(dic[i]); /* パターンの見つかった場所 */
		int ptn_length = strlen(dic[i].word); /* パターンの長さ */
	
		if(ptn_pos == -1) error();
		graph[ptn_pos][ptn_pos+ptn_length] = dic[i].penalty;
	}
}

/* 最短経路 floydのアルゴリズム */
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

/* 結果出力 */
void put_answer()
{
	int i;

	printf("最小の罰金は %d です。\n", graph[0][Length-1]);
	printf("区切りはこのようになります。\n");

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

