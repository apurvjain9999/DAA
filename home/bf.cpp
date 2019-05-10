//Made By: Apurv Jain
//2017KUCP1016
#include<iostream>
#include<string.h>

using namespace std;

int bruteforce(string st, string pat)
{
    int M = st.length();
    int N = pat.length();
    //cout<<M<<" "<<N<<endl;
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
            }
        }
    }
    return flag;
}
int main()
{
    cout<<"-------- Brute Force Pattern Matching ----------"<<endl<<endl;
    string st, pat;
    cout<<"Enter the String: ";
    getline(cin,st);
    cout<<"String: "<<st<<endl;
    cout<<"Enter the pattern for matching: ";
    getline(cin,pat);
    cout<<"Pattern to match: "<<pat<<endl;
    int f;
    f = bruteforce(st,pat);
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
