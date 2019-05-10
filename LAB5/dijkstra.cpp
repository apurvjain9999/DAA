//Dijkstra's Algorithm of Shortest Path Tree
//Made By: Apurv Jain 
#include<iostream>
#include<stdio.h>
#define INF 999  
using namespace std;

int minDist(int dist[], int sptSet[], int V) //To find vertex with min distance value from set of vertices 
{                                                //not yet included in shortest path tree

    int min = INF, m_i; 

    for (int v = 0; v < V; v++) 
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        { 
            min = dist[v];
            m_i = v; 
        }
    }
    return m_i; 
} 


int print_s(int dist[], int V)   //Print the dist array
{ 
    cout<<"Vertex Distance from Source\n"; 
    for (int i = 0; i < V; i++) 
        cout<<(char)(i+65)<<" -- "<<dist[i]<<endl;
} 

void dijkstra(int *graph, int src, int V) 
{ 
	int dist[V];	 //Hold the shortest distance from source
	int sptSet[V];   //will be 1 if vertex is included in shortest path tree
	for (int i = 0; i < V; i++) 
    {
		dist[i] = INF;  //initialize with maximum value (infinite)
        sptSet[i] = 0; 
    }   
	dist[src] = 0;          //dist of source from itself is zero
	for (int c = 0; c < V-1; c++) 
	{ 
	
	    int u = minDist(dist, sptSet, V); //To find vetex with min distance value from set of vertices 
                                              //not yet included in shortest path tree
        sptSet[u] = 1;                        //mark the picked vertex

        for (int v = 0; v < V; v++) 
        {
            // Update dist[v] only if is not in sptSet & there is an edge from 
		    // u to v & total weight of path from src to v via u is 
		    // smaller than current value of dist[v] 
        
            if (!sptSet[v] && *((graph+(u*V))+v) && dist[u] != INF 
                                        && (dist[u] + (*((graph+(u*V))+v))) < dist[v]) 
                dist[v] = dist[u] + (*((graph+(u*V))+v));
        } 
	} 
	print_s(dist, V); 
} 


int main() 
{ 
    int V;
    cout<<"----------- Dijkstra's Algorithm --------------"<<endl;
    cout<<"Enter number of vertices: ";
    cin>>V;
    int graph[V][V];
    for(int i=0; i<V; i++)
    {
        cout<<"For vertex: "<<(char)(i+65)<<endl;
        cout<<"Enter the weights for respective edges with vertices"<<endl;
        for(int j=0; j<V; j++)
        {
            cout<<"Enter for vertex "<<(char)(j+65)<<": ";
            cin>>graph[i][j];
        }
        cout<<endl;
    }
    int src = 0;
    char sr;
    cout<<"Enter the source vertex to start from : ";
    cin>>sr;
    src = (int)sr - 65;
    dijkstra((int *)graph, src, V); 

	return 0; 
} 
