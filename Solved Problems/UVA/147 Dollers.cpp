/* Rememeber when you want to cast or floor a double value to int value then add
EPS with double value and then do the operation.

Because computer treats 14.00 as 13.99999999999... So when cast 14.00 the 
resulting value will be 13. But it should be 14. Hence after adding EPS 13.999...
becomes 14.0000000000...001.And your result will be perfect.
*/ 

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

int coin[11] = { 2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};
int totalCoin = 11;
long long nway[6001];

int main()
{
  double dn;
  int in; 
  int i, j, c;
  
  while(cin >> dn && dn != 0.00) {
    if(floor((dn*20 + EPS)) != ceil((dn*20))) {
	     printf("%6.2lf%17d\n", dn, 0);
      continue;
    }                     
    in = (int) (dn*20 + EPS);
 //   cout << in << "\n";
    
    memset(nway, 0, sizeof(nway));
    nway[0] = 1;
    
    for(i=0; i<totalCoin; i++) {
      c = coin[i];
      for(j = c; j<=in; j++)
        nway[j] += nway[j-c];
    }
  
	 printf("%6.2lf", dn);
	 cout.width(17);
  cout << nway[in];
  cout << "\n";  
 //   printf("%6.2lf%17lld\n", dn, nway[in]);
  }   
	return 0;
}
