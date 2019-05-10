#include<iostream>
using namespace std;
int max1(int frac[],int knap[],int n,int t_w,int weights[],int W)
{
    int max = -1; int e = -1;
    for(int i=0; i<n; i++)
    {
        if(frac[i]>max && knap[i]!=1 && (t_w + weights[i]) <= W)
        {
            max = frac[i];
            e = i;
        }
        
    }
    return e;
}
int max2(int benefits[],int knap[],int n,int t_w,int weights[],int W)
{
    int max = -1; int e = -1;
    for(int i=0; i<n; i++)
    {
        if(benefits[i]>max && knap[i]!=1 && (t_w + weights[i]) <= W)
        {
            max = benefits[i];
            e = i;
        }
    }
    return e;
}
int knaps1(int items[],int benefits[],int weights[],int W, int n,int knap[],int frac[],int t_w)
{
    if(W == 0 || n == 0)
        return -1;
    else 
    {
        int k = n;
        while(1)
        {
            
            int b = max2(benefits,knap,k,t_w,weights,W);
            
                knap[b] = 1;
                t_w += weights[b];
            
            if(b == -1)
                break;
        }
    }
    return 0;
}
int knaps2(int items[],int benefits[],int weights[],int W, int n,int knap[],int frac[],int t_w)
{
    if(W == 0 || n == 0)
        return -1;
    else 
    {
        int k = n;
        while(1)
        {
            int a = max1(frac,knap,k,t_w,weights,W);
        
                knap[a] = 1;
                t_w += weights[a];
            
            if(a == -1)
                break;
        }
    }
    return 0;
}
int main()
{
    int n,W;
    cout<<"Enter the Weight required: ";
    cin>>W;
    cout<<"Enter number of items: ";
    cin>>n;
    int items[n];
    int benefits[n];
    int weights[n];
    int knap1[n];
    int knap2[n];
    int frac[n];
    int t_w1 = 0;
    int t_b1 = 0;
    int t_w2 = 0;
    int t_b2 = 0;
    int t_w = 0;
    int t_b = 0;
    for(int i=0; i<n; i++)
    {
        items[i] = i+1;
        cout<<"Enter benefit of item "<<i+1<<": ";
        cin>>benefits[i];
        cout<<"Enter weight of item "<<i+1<<": ";
        cin>>weights[i];
        knap1[i] = 0;
        knap2[i] = 0;
        frac[i] = benefits[i]/weights[n];
    }
    int f = knaps1(items,benefits,weights,W,n,knap1,frac,t_w1);
    int g = knaps2(items,benefits,weights,W,n,knap2,frac,t_w2);
    t_w = 0;
    if(f == 0 && g==0) 
    {
        for(int i=0; i<n; i++)
        {
            if(knap1[i] == 1)
            {
                t_b1 += benefits[i];
                t_w1 += weights[i];
            }
        }
        for(int i=0; i<n; i++)
        {
            if(knap2[i] == 1)
            {
                t_b2 += benefits[i];
                t_w2 += weights[i];
            }
        }
        if(t_b1 > t_b2)
        {
            t_b = t_b1;
            t_w = t_w1;
        }
        else
        {
            t_b = t_b2;
            t_w = t_w2;
        }
        
        cout<<"Optimal Solution: ";
        cout<<"Total Weight: "<<t_w<<" Total Benefit: "<<t_b<<endl;
        cout<<"Items Selected : "<<endl;
        for(int i=0; i<n; i++)
        {
            if(t_b1 > t_b2)
            {
                if(knap1[i] == 1)
                {
                    cout<<"Item: "<<items[i]<<" Benefit: "<<benefits[i]<<endl;
                }
            }
            else
            {
                if(knap2[i] == 1)
                {
                    cout<<"Item: "<<items[i]<<" Benefit: "<<benefits[i]<<endl;
                }
            }
            
        }
    }
    return 0;
}