// Prim's MST

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define V 6

int minc(int key[], bool vnotinc[])
{
    int min = INT_MAX, min_ind;
    for(int i = 0; i < V; i++)
    {
        if(vnotinc[i] == false && key[i] < min)
        {
            min = key[i];
            min_ind = i;
        }
    }
    return min_ind;
}

void prim(int graph[V][V])
{
    int parent[V]; //to store Min Span Tree
    int key[V]; // for minimum weight 
    bool vnotinc[V]; // vertices not included in mst
    for(int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        vnotinc[i] = false;
    }
    key[0] = 0; //make key 0 for the source ver
    parent[0] = -1; //first node is root of mst
    for(int j = 0; j < V-1; j++)
    {
        int a = minc(key, vnotinc);
        vnotinc[a] = true;
        for(int j = 0; j < V; j++)
        {
            if(graph[a][j] && vnotinc[j] == false && graph[a][j] < key[j])
            {
                parent[j] = a;
                key[j] = graph[a][j];
            }
        }
    }
    
    printf("Edge \tWeight\n"); 
    for (int i = 1; i < V; i++) 
    printf("%c - %c \t%d \n", parent[i]+65, i+65, graph[i][parent[i]]);
}

int main()
{
    int graph[V][V] = {
        {0,5,0,0.0,4},{5,0,2,0,0,10},{0,2,0,5,6,12},{0,0,5,0,3,0},{0,0,6,3,0,1},{4,10,12,0,1,0}
    };
    prim(graph);
    return 0;
}