//n-queen problem
//Apurv Jain
//2017KUCP1016
#include<iostream>
using namespace std;

void display(int **chess, int n)
{
    cout<<"Solution for the Chessboard of size "<<n<<"x"<<n<<" is: "<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<chess[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

bool isValid(int **chess, int row, int col, int n)
{
    for(int i = 0; i < col; i++)
        if(chess[row][i])
            return false;
    for(int i = row,j = col; i >=0 && j >= 0; i--, j--)
        if(chess[i][j])
            return false;
    for(int i = row, j = col; j>=0 && i < n; i++, j--)
        if(chess[i][j])
            return false;

    return true;
}

bool NQ(int **chess, int col, int n)
{
    if(col >= n)
        return true;
    for(int i = 0; i < n; i++)
    {
        if(isValid(chess, i, col, n))
        {
            chess[i][col] = 1;
            if(NQ(chess, col+1, n))
                return true;
            chess[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout<<"------ N Queen ------"<<endl;
    cout<<"Enter size of the Chessboard : ";
    int n;
    cin>>n;
    int ** chess = new int*[n];
    for(int i = 0; i < n; i++)
        chess[i] = new int[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            chess[i][j] = 0;
    
    if (NQ(chess, 0, n) == false) 
    { 
        cout<<"Solution does not exist for the Chessboard of size "<<n<<"x"<<n<<endl;
        return false; 
    }
    display(chess, n); 
    return 0;
}