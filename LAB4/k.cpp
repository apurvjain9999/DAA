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
    char node1;
    char node2;
    int weight;
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
int add_edge(struct graph *g, char src, char dest, struct edges *e, int w)
{
    int v = g->ver;
    for (int j=0; j<(v*(v-1)); j++)
    {
        if ((e[j].node1 == src && e[j].node2 == dest) || (e[j].node2 == src && e[j].node1 == dest))
        {
            //cout<<"This edge already exists "<<endl;
            return 0;
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
    if (src!=dest)
    {
        f = search_node(g,dest);
        adj *t1 = new adj;
        t1->node = src;
        t1->nxt = NULL;
        adj *t2;
        t2=&(g->arr[f]);
        while(t2->nxt!=NULL)
        {
            t2=t2->nxt;
        }
        t2->nxt=t1;
    }
    e[g->edg].node1 = src;
    e[g->edg].node2 = dest; 
    e[(g->edg)++].weight = w;
    return 1;
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
            int f;
            char d;
            int w;
            cout<<"Enter the node to connect: ";
            cin>>d;
            cout<<"Enter the weight of the edge: ";
            cin>>w;
            f=add_edge(g, g->arr[i].node, d, e, w);
            if(f==0)
                cout<<"This edge already exists "<<endl;
            else
            {
                cout<<"Edge created "<<endl;
            }
            
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
struct stack 
{
     char node;
     stack *nxt;
};
stack *top = NULL;
void push(char n)
{
    stack *temp = new stack;
    temp->node = n;
    temp->nxt = top;
    top = temp;
}
char pop()
{
    stack *temp = new stack;
    temp = top;
    top = top->nxt;
    char n;
    n = temp->node;
    delete temp;
    return n;
}
char *arr = new char;
int i=0;
int detect(char start, graph *g, int accessed[])
{
      int f;
      f = search_node(g,start);
      int flag =0;
      for(int j=0;j<i;j++)
      {
          
          if(arr[j]==start)
          {
             
            flag =1;
            
          }
      }
    if(flag == 1)
    {
        return 1;
    }
      if(accessed[f]==0)
      {
          push(start);
          cout<<start;
          accessed[f]=1;
          if(g->arr[f].nxt!=NULL)
          {
              arr[i] = pop();
              i++;
              adj* temp = g->arr[f].nxt;
              while(temp!=NULL)
              {
                  push(temp->node);
                  temp = temp->nxt;
              }
              char ch = pop();
              detect(ch,g,accessed);
          }
          else 
          {
             arr[i] = pop();
             i++;
             /*if(f==g->ver)
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
             if (g->ver==i)
                return 0;
             char ch = pop();
             detect(ch,g,accessed);
          }
      }
      
    return flag;
}

/*void DFS(char n, graph *g)
{
    push(n);
    cout<<n;
    int f = search_node(g,n);
    if(g->arr[f].nxt!=NULL)
    {
        pop();
        adj *temp = g->arr[f].nxt;
        while(temp->nxt!=NULL)
        {
            push(temp->node);
            temp = temp->nxt;
        }
        DFS(top->node,g);
    }
    else
    {
            DFS(g->arr[f+1].node,g);
    }
    

}*/

int find_min(int *c, graph *g)
{
    int t;
    for(int i=0; i<(g->edg); i++)
    {
        if(c[i]!=-1)
        {
            t = c[i];
            break;
        }
    }
    for(int i=0; i<(g->edg); i++)
    {
        if(c[i]<t && c[i]>0)
            t=c[i];
    }
    return t;
}
void kruskal(graph *g, int *c, edges *e)
{
    int *ar = new int[g->ver];
    int count = 2;
    for(int k=0;k<(g->ver);k++)
        ar[k]=0;
    for(int j=0;j<((g->ver)-1);j++)
    {
        graph g1;
        g1 = create_graph(((g->ver)-1));
        edges *e1 =  new edges[((g->ver)-1)];
        for(int i=0;i<(g1.ver);i++)
            {
                e1[i].node1='1';
                e1[i].node2='1';
            }
        int t = find_min(c,g);
        //cout<<"\n"<<t;
        for(int i=0;i<(g->edg);i++)
        {
            if(e[i].weight == t)
            {
                if(c[i]!=-1)
                {
                    int f;
                    //g1 = &(create_graph(count));
                    g1.ver = count;
                    g1.edg = j+1;
                    for(int m=0;m<(g1.ver);m++)
                    {
        
                        g1.arr[m].node = g->arr[m].node;
                        g1.arr[m].nxt = NULL;
                    }
                    //edges *e1 =  new edges[count];
                    
                    f = add_edge(&g1,e[i].node1,e[i].node2,e1,e[i].weight);
                    int acc[(g1.ver)];
                    for(int n=0;n<(g1.ver);n++)
                        acc[n] = 0;
                    f = detect(e[i].node1,&g1,acc);
                    if(f==1)
                    {
                        e1[((g1.ver)-1)].node1 = '1';
                        e1[((g1.ver)-1)].node2 = '1';
                    }
                    else
                    {
                        cout<<"\n";
                        cout<<e[i].node1<<"->"<<e[i].node2<<": "<<e[i].weight;
                        if(j==0)
                        {
                            ar[search_node(g,e[i].node1)] = 1;
                            ar[search_node(g,e[i].node2)] = 1;
                        }
                        if(ar[search_node(g,e[i].node1)]!=1)
                        {
                            ar[search_node(g,e[i].node1)] = 1;
                            count++;
                        }
                        if(ar[search_node(g,e[i].node2)]!=1)
                        {
                            ar[search_node(g,e[i].node2)] = 1;
                            count++;
                        }
                        c[i] = -1;
                    }
                    
                }
            }
        }
    }

}
int main()
{
    int v;
    cout<<"Enter the number of nodes: ";
    cin>>v;
    graph g = create_graph(v);
    v=(v*(v-1))/2;
    struct edges *e = new edges[v];
    for(int i=0;i<v;i++)
    {
        e[i].node1='1';
        e[i].node2='1';
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
            cout<<t->node;
            if(t->nxt!=NULL)
                cout<<"->";
            t=t->nxt;
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    int accessed[v];
    for(int i=0;i<v;i++)
        accessed[i] = 0;
    char ser;
    /*cout<<"Enter the node for which you want to start the DFS: ";
    cin>>ser;
    cout<<"The nodes of the Graph are: ";*/
    //DFS(ser,&g);
   // DFS(ser, accessed, &g);
    /*cout<<"Enter the node with which you want to start the search: ";
    cin>>ser;
    int flag;
    flag = detect(ser, accessed, &g);
    if(flag == 1)
        cout<<"The Graph contains a Cycle";
    else
    {
        cout<<"The Graph does not contain a Cycle";
    }*/
    for(int i=0;i<(g.edg);i++)
    {
        cout<<"\n";
        cout<<e[i].node1<<"->"<<e[i].node2<<":"<<e[i].weight;
    }
    int *c = new int[g.edg];
    cout<<"\n";
    for(int i=0;i<(g.edg);i++)
    {
        c[i] = e[i].weight;
        //cout<<c[i]<<" ";
    }

    kruskal(&g,c,e);

    return 0;
}