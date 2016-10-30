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

#define MAX 10000

int MW[MAX+1];
int maxburger[MAX+1];
int m, n, t;


int Process()
{
	int i, j;
	int w;
	int a = m, b = n;
	
	m = min(a, b);
	n = max(a, b);
	

	memset(MW, 0, sizeof(MW));
	memset(maxburger, 0, sizeof(maxburger));

	FOR(w, 1, t) {
		if(w < m) continue;
		MW[w] = m + MW[w - m];
		maxburger[w] = MW[w]/m;
	}
	FOR(w, 1, t) {
		if(w < n) continue;
		if(n + MW[w - n] > MW[w]) {
			MW[w] = n + MW[w - n];
			maxburger[w] = maxburger[w-n] + 1;
		}
	}

	return maxburger[t];
}

int main()
{
	
	while(cin >> m >> n >> t) {


		cout << Process();
		if(MW[t] < t) cout << " " << t - MW[t];
		cout << "\n";
	}

 	return 0;
}
