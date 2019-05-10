#include<iostream>
#include<stdlib.h>
using namespace std;
struct adj
{
    char node;
    struct adj *nxt;
};
struct graph
{
    int ver;
    int edg;
    struct adj *arr;
};
graph create_graph(int ver)
{
    graph g;
    g.ver = ver;
    g.edg = 0;
    g.arr = new adj[ver];
    return g;
}
struct edges
{
    char src;
    char dest;
};
void create_nodes(struct graph *g)
{
    for(int i=0;i<(g->ver);i++)
    {
        cout<<"Enter node "<<i+1<<" : ";
        cin>>g->arr[i].node;
        g->arr[i].nxt = NULL;
    }
}
int search_node(graph *g, char ser)
{
    for(int i=0; i<(g->ver); i++)
    {
        if (ser == g->arr[i].node)
        {
            return i;
        }
    }
}
void add_edge(struct graph *g, char src, char dest, struct edges *e)
{
    int v = g->ver;
    for (int j=0; j<(v*(v-1)); j++)
    {
        if (e[j].src == src && e[j].dest == dest)
        {
            cout<<"This edge already exists "<<endl;
            return;
        }
    }
    int f;
    f = search_node(g,src);
    adj *temp = new adj;
    temp->node = dest;
    temp->nxt = NULL;
    adj *t;
    t=&(g->arr[f]);
    while(t->nxt!=NULL)
    {
        t=t->nxt;
    }
    t->nxt=temp;
    e[g->edg].src = src;
    e[(g->edg)++].dest = dest; 
}
void create_edges(struct graph *g, struct edges *e)
{
    for(int i=0;i<(g->ver);i++)
    {
        int con;
        cout<<"Enter the number of nodes connected to the node "<<g->arr[i].node<<" : ";
        cin>>con;
        for(int j=0;j<con;j++)
        {
            char d;
            cout<<"Enter the node to connect: ";
            cin>>d;
            add_edge(g, g->arr[i].node, d, e);
        }
    }
}
void DFS(char ser, int accessed[], graph *g)
{
    int f;
    f = search_node(g,ser);
    cout<<ser;
    accessed[f]=1;
    adj *temp;
    temp = &(g->arr[f]);
    char t;
	while(temp!=NULL)
    {
       int f2;
       t = temp->node;
       f2 = search_node(g,t);
	   if(!accessed[f2])
            DFS(t, accessed, g);
        temp=temp->nxt;
    }
}

int main()
{
    int v;
    cout<<"Enter the number of nodes: ";
    cin>>v;
    graph g = create_graph(v);
    v=v*(v-1);
    struct edges *e = new edges[v];
    for(int i=0;i<v;i++)
    {
        e[i].src='1';
        e[i].dest='1';
    }
    create_nodes(&g);
    create_edges(&g, e);
    cout<<"\n\n";
    for(int i=0;i<g.ver;i++)
    {
        adj *t;
        t=&(g.arr[i]);
        while(t!=NULL)
        {
            cout<<t->node<<"->";
            t=t->nxt;
        }
        cout<<"\n;
    }
    cout<<"\n\n";
    int accessed[v];
    for(int i=0;i<v;i++)
        accessed[i] = 0;
    char ser;
    cout<<"Enter the node for which you want to start the DFS: ";
    cin>>ser;
    cout<<"The nodes of the Graph are: ";
    DFS(ser, accessed, &g);
    return 0;
}