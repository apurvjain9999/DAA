#include <iostream> 
#include <string.h>
using namespace std;

void f_lps(const char* pat, int M, int* lps) 
{  
	int l = 0; 

	lps[0] = 0;
	for(int i=1; i<M;)
    { 
		if (pat[i] == pat[l]) 
        { 
			l++; 
			lps[i] = l; 
			i++; 
		} 
		else
		{ 
			if (l != 0) 
            { 
				l = lps[l - 1]; 
			} 
			else
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 
void kmp(const char* pat,const char* st) 
{ 
	int M = strlen(pat); 
	int N = strlen(st); 

	int lps[M]; 
 
	f_lps(pat, M, lps); //calculate lps

	int i; //for st[] 
	int j; //for pat[]
	for(i=0,j=0;i<N;)
    { 
		if (pat[j] == st[i]) 
        { 
			j++; 
			i++; 
		} 

		if (j == M) 
        { 
			cout<<"Pattern is found at index: "<<i-j<<endl;
			j = lps[j - 1]; 
		} 
		else if (i < N && pat[j] != st[i]) 
        { 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

int main() 
{ 
    cout<<"-------- KMP Pattern Matching ----------"<<endl<<endl;
    string st, pat;
    cout<<"Enter the String: ";
    getline(cin,st);
    cout<<"String: "<<st<<endl;
    cout<<"Enter the pattern for matching: ";
    getline(cin,pat);
    cout<<"Pattern to match: "<<pat<<endl; 
	kmp(pat.c_str(),st.c_str()); 
	return 0; 
} 
