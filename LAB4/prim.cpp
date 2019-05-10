//Prim's Algorithm of Minimum Spanning Tree
//Made By: Apurv Jain 
#include<iostream>
#include<stdio.h> 
#define INF 999
using namespace std; 

int m_Key(int key[], int mstSet[], int V) //To find vetex with min key value not yet included in MST
{  
    int min = INF, m_i; 

    for (int v = 0; v < V; v++) 
    {
        if (mstSet[v] == 0 && key[v] < min) 
        {    
            min = key[v];
            m_i = v; 
        }
    }
    return m_i; 
} 

void p_MST(int mst[], int V, int *graph) //To print the MST
{ 
    cout<<"Edge  Weight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<(char)(mst[i]+65)<<" -- "<<(char)(i+65)<<"  "<<*(graph+(i*V)+mst[i])<<endl;
} 
 
void prim(int *graph, int V) //To create MST
{ 
	int mst[V];                 //To store the MST
	int key[V];                 //To store the key value of vertices
	int mstSet[V];              //To store vertices not included yet in MST
	for (int i = 0; i < V; i++) 
    {
        key[i] = INF;       //To initialize all keys with maximum value (infinite)
        mstSet[i] = 0;          
    }

	key[0] = 0;	                //First node is choosen
	mst[0] = -1;                //Root of MST

	for (int c = 0; c < (V-1); c++) 
	{ 
		int x = m_Key(key, mstSet, V); 	//To find vetex with min key value not yet included in MST
		mstSet[x] = 1;                  //Add the vertex to mstSet as included

		for (int v = 0; v < V; v++) 
        {
		    if ((*((graph+v*V)+x))!=0 && mstSet[v] == 0 && *((graph+v*V)+x) < key[v])  //For adjacent vertices
			{                                                                     //if not yet included,
                mst[v] = x;                                                       //update if the weight of edge is
                key[v] = *((graph+v*V)+x);                                        //smaller than key value
            }
        } 
	} 
	p_MST(mst, V, graph); //Print MST
} 

int main() 
{ 
    cout<<"----------- Prim's Algorithm --------------"<<endl;
    int V;
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
	prim((int *)graph,V); 

	return 0; 
} 
