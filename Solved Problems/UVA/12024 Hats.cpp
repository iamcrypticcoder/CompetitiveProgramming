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

int fact[13];

void FactGen()
{
    fact[0] = 1;

    FOR(i, 1, 12)
        fact[i] = fact[i-1] * i;
}

// http://en.wikipedia.org/wiki/Derangement
int dearrangement(int N)
{
    int ret = 0;
    FOR(i, 0, N) {
        if(i % 2 == 0)
            ret += fact[N] / fact[i];
        else ret -= fact[N] / fact[i];
    }
    return ret;
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N;

    FactGen();

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> N;

        cout << dearrangement(N) << "/" << fact[N] << "\n";
    }

	return 0;
}
