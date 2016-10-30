
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;
typedef map<string, string> MSS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

LL GCD(LL a, LL b)	    {	return b==0 ? a : GCD(b, a%b); }
LL LCM(LL a, LL b)      {   return a/GCD(a, b)*b;          }
VI divisor;

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N, cardinality;

    while(cin >> N) {
        if(N==0) break;
        int root = sqrt(N);
        FOR(i, 1, root) {
            if(N%i == 0) {
                divisor.PB(i);
                if(i != (N/i)) divisor.PB(N/i);
            }
        }
  //      cout << "df";
        cardinality = 0;
        FOR(i, 0, divisor.SZ-1) {
            FOR(j, i+1, divisor.SZ-1)
                if(LCM(divisor[i], divisor[j]) == N)    // Casue gcd 1 hole lcm N hobe.
                    cardinality++;
        }
        cout << N << " " << cardinality+1 <<"\n";       // cause lcm(N,N) = N;

        divisor.clear();
    }

	return 0;
}
