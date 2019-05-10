// Closest Pair of points
//2017KUCP1016
//Apurv Jain
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<float.h>
using namespace std;
#define fmax 1000;
class Point
{
    public:
    int x, y;
    Point(){};
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};
Point *c_P[2];

int compX(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b; 
    return (p1->x - p2->x); 
}

int compY(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b; 
    return (p1->y - p2->y); 
}

float dist(Point p1, Point p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
                 (p1.y - p2.y)*(p1.y - p2.y) ); 
}

float min_dist(Point P[], int n, Point *Ps[2]) 
{ 

    cout<<"md"<<endl<<endl;
    float min = fmax;
    for (int i = 0; i < n; ++i) 
    {
        cout<<"1 lp"<<endl<<endl;
        for (int j = i+1; j < n; ++j) 
        {
            cout<<"2 lp"<<endl<<endl;
            if (dist(P[i], P[j]) < min) 
            {
                min = dist(P[i], P[j]); 
                Ps[0]->x = P[i].x;
                Ps[0]->y = P[i].y;
                Ps[1]->x = P[j].x;
                Ps[1]->y = P[j].y;
            } 
        }
    }
    cout<<"exit"<<endl<<endl;
    return min; 
} 

float min(float x, float y) 
{ 
    return (x < y)? x : y; 
} 

float stripClosest(Point strip[], int size, float d,Point *Pst[2]) 
{ 
    cout<<"strclo"<<endl<<endl;
    float min = d; 
    qsort(strip, size, sizeof(Point), compY);   
    for (int i = 0; i < size; ++i) 
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (dist(strip[i],strip[j]) < min)
            { 
                min = dist(strip[i], strip[j]); 
                Pst[0]->x = strip[i].x;
                Pst[0]->y = strip[i].y;
                Pst[1]->x = strip[j].x;
                Pst[1]->y = strip[j].y;
            }
  
    return min; 
}

float clu(Point P[], int n, Point *P1[2]) 
{ 
    cout<<"clu"<<endl<<endl;
    Point *Pl[2], *Pr[2];
    Point *Ps[2];
    Point *Pst[2];
    if (n <= 3) 
    {
        
        return min_dist(P,n,P1); 
    }
    int mid = n/2; 
    Point mid_P = P[mid]; 
    
    float dl = clu(P, mid, Pl); 
    float dr = clu(P + mid, n-mid, Pr); 
 
    float d = min(dl, dr); 
    int u;
    if(d == dl)
    {
        for(u=0;u<2;u++)
        {
            Ps[u]->x = Pl[u]->x;
            Ps[u]->y = Pl[u]->y;
        }
    }
    else
    {
        for(u=0;u<2;u++)
        {
            Ps[u]->x = Pr[u]->x;
            Ps[u]->y = Pr[u]->y;
        }
    }
    Point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(P[i].x - mid_P.x) < d) 
            strip[j] = P[i], j++; 
    float min1;
    min1 = stripClosest(strip, j, d, Pst);
    float min2;
    min2 = min(d,min1);
    if(min2 == d) 
    {
        for(u=0;u<2;u++)
        {
            P1[u]->x = Ps[u]->x;
            P1[u]->y = Ps[u]->y;
        }
    }
    else
    {
        for(u=0;u<2;u++)
        {
            P1[u]->x = Pst[u]->x;
            P1[u]->y = Pst[u]->y;
        }
    }
    return min2;
    //return min(d,stripClosest(strip,j,d));
}

float closest(Point P[], int n)
{
    Point *P2[2];
    float min;
    int i;
    cout<<endl<<"Closest"<<endl<<endl;
    qsort(P, n, sizeof(Point), compX);
    min = clu(P, n, P2);
    for(i=0;i<2;i++)
    {
        c_P[i]->x = P2[i]->x;
        c_P[i]->y = P2[i]->y;
    }
    cout<<"Bye"<<endl<<endl;
    return min;
} 

int main()
{
    cout<<"----- Closest Pair of Points --------"<<endl;
    //Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    //int n = sizeof(P) / sizeof(P[0]);
    int n;
    cout<<"Enter number of points: "<<endl;
    cin>>n;
    Point P[n];
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"Enter point "<<i+1<<" :"<<endl;
        cout<<"Enter x coordinate: ";
        cin>>P[i].x;
        cout<<"Enter y coordinate: ";
        cin>>P[i].y;
    }
    cout<<"Minimum distance is: "<<closest(P,n);
    cout<<"Closest Points are: "<<endl;
    for(i=0;i<2;i++)
    {
        cout<<"{"<<c_P[i]->x<<","<<c_P[i]->y<<"}"<<endl;
    }
    return 0;
}