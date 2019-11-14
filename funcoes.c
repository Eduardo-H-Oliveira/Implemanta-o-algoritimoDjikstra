#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
#include "libraly.h"

void dijkstra(int G[MAX][MAX],int n,int startnode)
{

	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j;

	//pred[] armazena o antecessor de cada nó
	//count fornece o número de nós vistos até agora
	//cria a matriz de custos
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	//inicializa pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INFINITY;

		//nextnode dá o nó à distância mínima
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//verifique se existe um caminho melhor através do nextnode
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//imprime o caminho e a distância de cada nó
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistância do nó %d =%d",i,distance[i]);
			printf("\nCaminho=%d",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
}
