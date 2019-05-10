#include<iostream>
using namespace std;

void lcs(string a, string b)
{
    int i1 = a.length();
    int j1 = b.length();
    int l[a.length()+1][b.length()+1], k[a.length()+1][b.length()+1], m=0, n=0;

    for(int i=0; i<=a.length(); ++i)
    {
        for(int j=0; j<=b.length(); ++j)
        {
            if(i==0 || j==0)
            {
                l[i][j] = 0;
                k[i][j] = 0;
            }
            else if(a[i-1] == b[j-1])
            {
                l[i][j] = l[i-1][j-1] + 1;
                k[i][j] = 1;
            }
            else
            {
                m = l[i-1][j];
                n = l[i][j-1];
                if(m < n)
                {
                    l[i][j] = n;
                    k[i][j] = 3;
                }
                else
                {
                    l[i][j] = m;
                    k[i][j] = 2;
                }
            }
        }
    }
    cout<<l[a.length()][b.length()]<<endl;
    cout<<"\n";
    for(int i=0;i<=a.length();i++)
    {
        for(int j=0;j<=b.length();j++)
        {
            cout<<l[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<=a.length();i++)
    {
        for(int j=0;j<=b.length();j++)
        {
            cout<<k[i][j];
        }
        cout<<"\n";
    }
    //cout<<i1<<j1;
    cout<<"Longest Common Subsequence: ";
    while(k[a.length()][b.length()])
    {
        if(k[i1][j1] == 1)
        {
            cout<<a[i1-1];
            i1--;
            j1--;
        }
        else if(k[i1][j1] == 2)
        {
            i1--;
        }
        else if(k[i1][j1] == 3)
        {
            j1--;
        }
        if(i1 == 0 || j1 == 0)
            break;     
    }
    cout<<"\n";
}

int main()
{
    cout<<"------ LCS -----"<<endl;
    cout<<"Enter string a: ";
    string a, b;
    cin>>a;
    cout<<"Enter string b: ";
    cin>>b;
    lcs(a, b);
    cout<<"\n";
    return 0;
}