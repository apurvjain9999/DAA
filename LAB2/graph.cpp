#include<iostream>
#include<stdlib.h>
using namespace std;
struct con
{
    char data;
    struct con *c;
};
struct nodes
{
    char data;    
    struct con *c; 
};

int main()
{
    int node;
    cout<<"Enter the number of nodes: ";
    cin>>node;
    struct nodes *st;
    st = new nodes[node];
    for(int i=0;i<node;i++)
    {
        cout<<"Enter node data "<<i+1<<" : ";
        cin>>st[i].data;
        st[i].c = NULL;
    }
    for(int i=0;i<node;i++)
    {
        int dir;
        cout<<"Enter the number of nodes directed from node "<<st[i].data<<" : ";
        cin>>dir;
        for(int j=0;j<dir;j++)
        {
            struct con *temp;
            int flag;
            cout<<"Enter the node directed from "<<st[i].data<<" : ";
            cin>>temp->data;
            temp->c = NULL;
            if(st[i].c == NULL)
                st[i].c = temp;
            else
            {
                    struct con *t1;
                    t1 = st[i].c;
                    while(t1->c != NULL)
                    {
                        t1 = st[i].c;
                    }
                    t1->c = temp;
            }
            
        }
    }
    return 0;
}