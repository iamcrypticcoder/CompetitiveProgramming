#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;


typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define swap(x, y) (x) ^= (y) ^= (x) ^= (y)
#define FOR(i, L, U)		for(int i=L; i<=U; i++)
#define EPS 1e-9

#define MAX 1001

int N;
int NUM[MAX];

int Bubble(int *item, int count)
{
  int ex = 0;
  int a, b, t;
  
  for(a=1; a<=count; a++)

   for(b=count-1; b>=a; b--) {
    if(item[b-1] > item[b]) {

    t= item[b-1];
    item[b-1] = item[b];
    item[b] = t;
    ex++;
   }
  }
// BUBBLE SORT ENDED.
  
  return ex;
 
}

int main()
{
  int i;
  int ans;
  
  while(cin >> N) {
   FOR(i, 0, N-1)
     cin >> NUM[i];
   ans = Bubble(NUM, N);
   cout << "Minimum exchange operations : ";
   cout << ans << "\n";
   }  
   
     
  
   

	return 0;
}


