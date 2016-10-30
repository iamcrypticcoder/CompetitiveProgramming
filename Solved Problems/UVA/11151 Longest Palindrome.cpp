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

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);



/*
int longestPalin(int l, int r)
{
    if(l == r) return 1;
    if(r - l == 1) {
        return A[l] == A[r] ? 2 : 1;
    }
    if(A[l] == A[r]) return (2 + longestPalin(l+1, r-1));
    else return max(longestPalin(l+1, r), longestPalin(l, r-1));
}
*/

int DP[1000][1000];

int longestPalin(string A)
{
    int size = A.size();

    FOR(i, 0, size-1)   DP[i][i] = 1;
    FOR(i, 0, size-2) {
        if(A[i] == A[i+1])  DP[i][i+1] = 2;
        else DP[i][i+1] = 1;
    }

    FOR(length, 3, size)
        FOR(i, 0, size-1-length+1) {
            int j = i + length -1;
            if(A[i] == A[j])
                DP[i][j] = 2 + DP[i+1][j-1];
            else DP[i][j] = max(DP[i][j-1], DP[i+1][j]);
        }
/*
    FOR(i, 0, size-1) {
        FOR(j, 0, size-1)
            cout << DP[i][j] << " ";
        cout << "\n";
    }
*/
    return DP[0][size-1];
}


int main()
{
    int tc, TC;
    string A;

    cin >> TC;
    getline(cin, A);

    while(TC--) {
        getline(cin, A);
        if(A.size() == 0) {
            cout << "0\n";
            continue;
        }
        cout << longestPalin(A) << "\n";
    }

    return 0;
}
