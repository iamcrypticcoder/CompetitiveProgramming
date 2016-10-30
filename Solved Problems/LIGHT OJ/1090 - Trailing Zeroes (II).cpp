/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

int calcf5(int n) {
	int ret = 0;
	while(n > 0) {
		n /= 5;
		ret += n;
	}
	return ret;
}

int calcf2(int n) {
	int ret = 0;
	while(n > 0) {
		n >>= 1;
		ret += n;
	}
	return ret;
}

int calcn2(int n) {
	int ret = 0;
	while((n&1) == 0) {
		ret++;
		n >>= 1;
	}
	return ret;
}

int calcn5(int n) {
	int ret = 0;
	while(n % 5 == 0) {
		ret++;
		n /= 5;
	}
	return ret;
}


int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int n, r, p, q;

   TC = src();

   FOR(tc, 1, TC) {
      scanf("%d %d %d %d", &n, &r, &p, &q);

		int t5 = calcf5(n) - calcf5(r) - calcf5(n - r) + q * calcn5(p);
		int t2 = calcf2(n) - calcf2(r) - calcf2(n - r) + q * calcn2(p);
		printf("Case %d: %d\n", tc, t5 < t2 ? t5 : t2);

   }

   return 0;
}
