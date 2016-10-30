#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define FOR( i, L, U ) for( i=L ; i<=U ; i++ )

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;


int age[101];

int main()
{   
    int n, i, temp, max, j;
    
    while(scanf("%d", &n) != EOF)
    {
		if(n == 0) break;
      memset(age, 0, sizeof(age)); 
       
      max = 0;      
      FOR(i, 1, n) {
        scanf("%d", &temp);
        age[temp]++;
        if(temp > max) max= temp;
      }
      
            
      FOR(i, 1, max-1) {
        FOR(j, 1, age[i])
          printf("%d ", i);       
      }
      FOR(j, 1, age[max]-1)
        printf("%d ", max);
         
      printf("%d\n", max);
    }
    


	return 0;
}
