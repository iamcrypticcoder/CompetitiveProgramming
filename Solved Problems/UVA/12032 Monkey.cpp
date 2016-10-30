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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

int height[100001];
int N;

bool isPossible(int k)
{
    FOR(i, 1, N) {
        if(height[i] - height[i-1] > k) return 0;
        if(height[i] - height[i-1] == k) k--;
    }
    return 1;
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    cin >> TC;

    FOR(tc, 1, TC) {
        cin >> N;

        FOR(i, 1, N)
            cin >> height[i];

        k = 0;
        FORD(i, N, 1) {
            if(height[i] - height[i-1] > k) k = height[i] - height[i-1];
            else if(height[i] - height[i-1] == k) k++;
        }

/*
        for(k=0; ; k++) {
            if(isPossible(k)) {
                break;
            }
        }
*/
        cout << "Case " << tc << ": ";
        cout << k << "\n";
    }

	return 0;
}
