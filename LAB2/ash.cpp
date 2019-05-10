#include<iostream>
#include<stdlib.h>
using namespace std;
struct adj
{
    char node;
    struct adj *nxt;
};
/*struct adj_list
{
    struct adj *head;
};
*/
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
    int flag;
    for(int i=0;i<v;i++)
    {
        if (src == g->arr[i].node)
        {
            flag = i;
            break;
        }
    }
    adj *temp = new adj;
    temp->node = dest;
    temp->nxt = NULL;
    adj *t;
    t=&(g->arr[flag]);
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
        cout<<"\n";
    }
    cout<<"\n\n";
    return 0;
}