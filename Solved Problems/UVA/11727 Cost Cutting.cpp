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



int main()
{
 int a, b, c, ans;
 int TC, tcase;
 int minimum, maximum;
     
     cin >> TC;
     
 
 FOR(tcase, 1, TC) {
  cin >> a >> b >> c ;
  cout << "Case " << tcase << ": ";
  minimum = min(a,min(b,c));
  maximum = max(a,max(b,c));
  if(a!= minimum && a != maximum) ans = a;
  if(b!= minimum && b != maximum) ans = b;
  if(c!= minimum && c != maximum) ans = c;
  
  cout << ans << "\n";
}

	return 0;
}
