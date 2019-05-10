#include<iostream>
#include<stdlib.h>
using namespace std;
char *arr=new char[4];
int qq=0;
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
/*
struct stack 
{
     char node;
     stack *nxt;
};
void push(char n)
{
    stack *temp = new stack;
    temp->node = n;
    temp->nxt = top;
    top = temp;
}
char pop()
{
    stack *temp;
    temp = top;
    top = top->nxt;
    char n;
    n = temp->node;
    delete temp;
    return n;
}*/
bool isCyclic(int f, int accessed[], int *stack, graph *g)
{
    if(accessed[f] == 0)
    {
        accessed[f] = 1;
        stack[f] = 1;
    }
    adj *temp = g->arr[f].nxt;
    for(;temp != NULL; temp = temp->nxt)
    {
        if(accessed[search_node(g,temp->node)] == 1 && isCyclic(search_node(g,temp->node), accessed, stack, g))
            return true;
        else if(stack[search_node(g,temp->node)] == 1)
            return true;
        
    }
    stack[f] = 0;
    return false;
}
int detect(graph *g)
{
    int *accessed = new int[g->ver];
    int *stack = new int[g->ver];
    for(int i=0; i<(g->ver); i++)
    {
        accessed[i] = 0;
        stack[i] = 0;
    }
    for(int i=0; i<(g->ver); i++)
    {
        if(isCyclic(i,accessed,stack,g))
            return 1;
    }
    return 0;
}
/*int detect(char start, graph *g, int accessed[])
{
      int f,kk;
      f = search_node(g,start);
      int flag =0;
      for(int j=0;j<qq;j++)
      {
          cout<<"this is "<<arr[j]<<" ";
          cout<<"start "<<start<<" ";
          if(arr[j]==start)
          {
         
         
         
         
            cout<<"Hello ";
            flag = 1;
            
          }
      }
    if(flag == 1)
        return flag;
      if(accessed[f]==0)
      {
          push(start);
          cout<<start;
          accessed[f]=1;
          if(g->arr[f].nxt!=NULL)
          {
              arr[qq] = pop();
              qq++;
              adj* temp = g->arr[f].nxt;
              while(temp!=NULL)
              {
                  push(temp->node);
                  temp = temp->nxt;
              }
              char ch = pop();
              kk=detect(ch,g,accessed);
              if(kk==1)
              return kk;
          }
          else 
          {
             arr[qq] = pop();
             qq++;
             if(f==g->ver)
             {
                 stack *temp = top;
                 int h;
                 while(temp!=NULL)
                 {
                     h = search_node(g,temp->node);
                     if(accessed[h]==0)
                        detect(temp->node,g,accessed);
                     else
                     {
                         temp = temp->nxt;
                     }
                     
                 }
             }*/
             /*char ch = pop();
             kk=detect(ch,g,accessed);
             if(kk==1)
              return kk;
          }
      }
      
    return flag;
}*/

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
    /*int accessed[v];
    for(int i=0;i<v;i++)
        accessed[i] = 0;
    */
    /*char ser;
    cout<<"Enter the node for which you want to start detecting the cycle: ";
    cin>>ser;*/
    int w;

    w=detect(&g);
    cout<<"F"<<w;

    if(w == 0)
        cout<<"\nThe Graph is not Cyclic";
    else
    {
        cout<<"\nThe Graph is Cyclic";
    }
    
    return 0;
}