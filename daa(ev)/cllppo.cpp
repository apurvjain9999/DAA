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

float min_dist(Point P[], int n) 
{ 

    float min = fmax;
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < min) 
            {
                min = dist(P[i], P[j]); 
            } 
    return min; 
} 

float min(float x, float y) 
{ 
    return (x < y)? x : y; 
} 

float stripClosest(Point strip[], int size, float d) 
{ 
    float min = d; 
    qsort(strip, size, sizeof(Point), compY);   
    for (int i = 0; i < size; ++i) 
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (dist(strip[i],strip[j]) < min)
            { 
                min = dist(strip[i], strip[j]); 
            }
  
    return min; 
}

float clu(Point P[], int n) 
{ 
    if (n <= 3) 
        return min_dist(P, n); 
    int mid = n/2; 
    Point mid_P = P[mid]; 
    
    float dl = clu(P, mid); 
    float dr = clu(P + mid, n-mid); 
 
    float d = min(dl, dr); 
   
    Point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(P[i].x - mid_P.x) < d) 
            strip[j] = P[i], j++; 

    return min(d,stripClosest(strip,j,d));
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compX);
    return clu(P, n);
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
    return 0;
}