/*                      */
/* 円周率の計算 revival */
/*                      */
#include <stdio.h>
#include <stdlib.h>

#define N 255

void wa(int u[],int v[],int w[]); /* w = u + v */
void sa(int u[],int v[],int w[]); /* w = u - v */
void seki(int u[],int v,int w[]); /* w = u * v */
void shou(int u[],int v,int w[]); /* w = u / v */
void print(int u[]);
void error(char *message);
int isnotzero(int u[]);
