//Made By: Apurv Jain
//2017KUCP1016
#include<iostream>
#include<string.h>
#define prime 101
using namespace std;

int bruteforce(string st, string pat)
{
    int M = st.length();
    int N = pat.length();
    //cout<<M<<" "<<N<<endl;
    int count = 0;
    int flag = 1;
    for(int i=0; i<=(M-N); i++)
    {
        if(st[i] == pat[0])
        {   
            int j;
            int k = 1;
            for(j=1; j<N; j++, k++)
            {
                if(st[i+j] != pat[k])
                    break;
            }
            if(j == N)
            {
                cout<<"Pattern is found at index: "<<i+1<<endl;
                flag = 0;
                count++;
            }
        }
    }
    cout<<"The Pattern is found "<<count<<" times"<<endl;
    return flag;
}
int rabin_karp(string st, string pat) 
{
    int count = 0;
    int M = st.length();               
    int N = pat.length();               
    int pa = 0;
    for(int i=N-1; i>=0; i--)      
    {
        pa += (int)pat[i];
    }
    int p_m = pa%prime;
    //cout<<M<<" "<<N<<endl;
    int flag = 1;
    int sa = 0;
    for(int i=0; i<=(M-N); i++)
    {
        int j;
        if(i==0)
        {
            for(j=N-1; j>=0; j--)
            {
                sa += (int)st[i+j];
            }
        }
        int s_m = sa%prime;
        if(p_m == s_m)
        {
            int l;
            for(l=0; l<N; l++)
            {
                if(pat[l] != st[i+l])
                    break;
            }
            if(l==N)
            {
                cout<<"Pattern is found at index: "<<i+1<<endl;
                flag = 0;
                count++;
            }
        }
        else
        {
            sa -= st[i];
            if((i+N)<M)
                sa += st[i+N];
        }
        
    }
    cout<<"The Pattern is found "<<count<<" times"<<endl;
    return flag;
}
int main()
{
    cout<<"-------- Pattern Matching ----------"<<endl<<endl;
    string st, pat;
    cout<<"Enter the String: ";
    getline(cin,st);
    cout<<"String: "<<st<<endl;
    cout<<"Enter the pattern for matching: ";
    getline(cin,pat);
    cout<<"Pattern to match: "<<pat<<endl;
    int ans;
    cout<<"Select method to match : "<<endl;
    cout<<"1. Brute Force (Naive) Method "<<endl;
    cout<<"2. Rabin Karp (R-K) Method "<<endl;
    cout<<"Enter your choice: ";
    cin>>ans;
    int f;
    if(ans == 1)
        f = bruteforce(st,pat);
    else
        f = rabin_karp(st,pat);
    if(f==0)
    {
        ;
    }
    else
    {
        cout<<"The Pattern is not in the String"<<endl;
    }
    return 0;
}
