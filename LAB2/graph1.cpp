#include<iostream>
#include<stdlib.h>
using namespace std;
struct adj
{
    char node;
    struct adj *nxt;
};
struct adj_list
{
    struct adj *head;
};
struct graph
{
    int ver;
    int edg;
    struct adj_list *arr;
};
struct graph* create_graph(int ver)
{
    struct graph *g = (struct graph*)malloc(sizeof(struct graph*));
    g->ver = ver;
    g->edg = 0;
    g->arr = (struct adj_list *)malloc(ver*sizeof(struct adj_list));
    for (int i=0;i<ver;i++)
        g->arr[i].head == NULL;
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
        struct adj *temp = (struct adj*)malloc(sizeof(struct adj));
        cout<<"Enter node "<<i+1<<" : ";
        cin>>temp->node;
        temp->nxt = NULL;
        g->arr[i].head = temp;
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
        if (src == g->arr[i].head->node)
        {
            flag = i;
            break;
        }
    }
    struct adj *temp = (struct adj*)malloc(sizeof(struct adj));
    temp->node == dest;
    temp->nxt == NULL;
    struct adj *h = g->arr[flag].head;
    while(h->nxt != NULL)
        h = h->nxt;
    h->nxt = temp;
    e[g->edg].src = src;
    e[(g->edg)++].dest = dest; 
}
void create_edges(struct graph *g, struct edges *e)
{
    for(int i=0;i<(g->ver);i++)
    {
        int con;
        cout<<"Enter the number of nodes connected to the node "<<g->arr[i].head->node<<" : ";
        cin>>con;
        for(int j=0;j<con;j++)
        {
            char d;
            cout<<"Enter the node to connect: ";
            cin>>d;
            add_edge(g, g->arr[i].head->node, d, e);
        }
    }
}
int main()
{
    int v;
    cout<<"Enter the number of nodes: ";
    cin>>v;
    struct graph *g = create_graph(v);
    struct edges *e = (struct edges*)malloc((v*(v-1))*sizeof(struct edges));
    create_nodes(g);
    create_edges(g, e);
    return 0;
}