#include<iostream>
using namespace std;
int max1(float frac[],int knap[],int n,int t_w,float weights[],int W)
{
    int max = -1; int e = -1;
    for(int i=0; i<n; i++)
    {
        if(frac[i]>max && knap[i]!=1)
        {
            max = frac[i];
            e = i;
        }
        
    }
    return e;
}
int max2(float benefits[],int knap[],int n,int t_w,float weights[],int W)
{
    int max = -1; int e = -1;
    for(int i=0; i<n; i++)
    {
        if(benefits[i]>max && knap[i]!=1)
        {
            max = benefits[i];
            e = i;
        }
    }
    return e;
}
int knaps1(int items[],float benefits[],float weights[],int W, int n,int knap[],float frac[],int t_w,float *t_b)
{
    if(W == 0 || n == 0)
        return -1;
    else 
    {
        int k = n;
        while(1)
        {
            
            int b = max2(benefits,knap,k,t_w,weights,W);
            if((t_w + weights[b]) > W)
            {
                *t_b += (W - weights[b])*frac[b];
                b = -1;
            }
            else
            {
                *t_b += benefits[b];
                knap[b] = 1;
                t_w += weights[b];
            }
            if(b == -1)
                break;
        }
    }
    return 0;
}
int knaps2(int items[],float benefits[],float weights[],int W, int n,int knap[],float frac[],int t_w,float *t_b)
{
    if(W == 0 || n == 0)
        return -1;
    else 
    {
        int k = n;
        while(1)
        {
            
            int b = max1(benefits,knap,k,t_w,weights,W);
            if((t_w + weights[b]) > W)
            {
                *t_b += (W - weights[b])*frac[b];
                b = -1;
            }
            else
            {
                *t_b += benefits[b];
                knap[b] = 1;
                t_w += weights[b];
            }
            if(b == -1)
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
    float benefits[n];
    float weights[n];
    int knap1[n];
    int knap2[n];
    float frac[n];
    int t_w1 = 0;
    float t_b1 = 0;
    int t_w2 = 0;
    float t_b2 = 0;
    int t_w = 0;
    float t_b = 0;
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
    int f = knaps1(items,benefits,weights,W,n,knap1,frac,t_w,&t_b1);
    int g = knaps2(items,benefits,weights,W,n,knap2,frac,t_w,&t_b2);
    t_w = 0;
    if(f == 0 && g==0) 
    {
        if(t_b1 > t_b2)
        {
            t_b = t_b1;
        }
        else
        {
            t_b = t_b2;
        }
        cout<<"Optimal Solution: ";
        cout<<"Total Benefit: "<<t_b<<endl;
        cout<<"Items Selected : "<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<t_b1<<" "<<t_b2<<endl;
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