#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
#include <locale.h>
#include "libraly.h"



int main()
{
    setlocale(LC_ALL, "Portuguese");
	int G[MAX][MAX],i,j,n,u;
	printf("Digite no. de v�rtices:");
	scanf("%d",&n);
	printf("\nDigite a matriz de adjac�ncia:\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);

	printf("\nDigite o n� inicial:");
	scanf("%d",&u);
	dijkstra(G,n,u);

	return 0;
}

