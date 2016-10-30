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

int H[51];

int main()
{
  int TC, N, tcase;
  int i,j;
  int highJump, lowJump;
  
  cin >> TC;
  
  FOR(tcase , 1, TC) {
    highJump = lowJump = 0;
    cin >> N;
    FOR(j, 1, N)
      cin >> H[j];
    
    for(i=1; i < N; i++) {
      if(H[i] < H[i+1])
        highJump++;
      else if(H[i] > H[i+1])
        lowJump++;
    }
    cout << "Case " << tcase << ": " << highJump << " " <<  lowJump << "\n";
  }
  
       
	return 0;
}
