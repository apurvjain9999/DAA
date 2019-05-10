// LCS(Longest Common Subsequence)

#include<iostream>
using namespace std;

int lcs(string a, string b)
{
    int l[a.length()+1][b.length()+1], arrow[a.length()+1][b.length()+1];
    for(int i = 0; i <= a.length(); i++)
    {
        for(int j = 0; j <= b.length(); i++)
        {
            if(i == 0 || j == 0)
            {
                l[i][j] = 0;
                arrow[i][j] = 0;
            }
            else if(a[i-1] == b[j-1])
            {
                l[i][j] = l[i-1][j-1] + 1;
                arrow[i][j] = 1;
            }
            else
            {
                int r = l[i-1][j];
                int f = l[i][j-1];
                l[i][j] = (r < f) ? f : r;
                // arrow[i][j] = 3;
            }
        }
    }
    return l[a.length()][b.length()];
}

int main(int argc, char const *argv[])
{
    cout<<"Enter string a: ";
    string a, b;
    cin>>a;
    cout<<"Enter string b: ";
    cin>>b;
    cout<<lcs(a, b)<<"\n";
    return 0;
}