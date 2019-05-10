//Made By: Apurv Jain
//2017KUCP1016
#include<iostream>
#include<string.h>
#define prime 101
using namespace std;

int rabin_karp(string st, string pat) 
{
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
            }
        }
        else
        {
            sa -= st[i];
            if((i+N)<M)
                sa += st[i+N];
        }
        
    }
    return flag;
}
int main()
{
    cout<<"-------- Rabin Karp Pattern Matching ----------"<<endl<<endl;
    string st, pat;
    cout<<"Enter the String: ";
    getline(cin,st);
    cout<<"String: "<<st<<endl;
    cout<<"Enter the pattern for matching: ";
    getline(cin,pat);
    cout<<"Pattern to match: "<<pat<<endl;
    int f;
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
