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
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i--

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

string A;

/*
int strToPalinCost(int l ,int r)
{
    int ret;
    if(l == r) return 0;
    if(r - l == 1) {
        if(A[l] == A[r]) return 0;
        else return 1;
    }

    if(A[l] == A[r]) return strToPalinCost(l+1, r-1);
    else return 1 + min(min(strToPalinCost(l+1, r-1), strToPalinCost(l+1, r)),strToPalinCost(l, r-1));
}
*/

int DP[1000][1000];

int strToPalinCost(string A)
{
    int size = A.size();
    FOR(i, 0, size-1)   DP[i][i] = 0;
    FOR(i, 0, size-2)  {
        if(A[i] == A[i+1])  DP[i][i+1] = 0;
        else DP[i][i+1] = 1;
    }

    FOR(length, 3, size)
        FOR(i, 0, size-1-length+1) {
            int j = i + length -1;

            if(A[i] == A[j])
                DP[i][j] = DP[i+1][j-1];
            else DP[i][j] = 1 + min(min(DP[i][j-1], DP[i+1][j]),DP[i+1][j-1]);
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
 //   READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;

    cin >> TC;
    getline(cin, A);

    FOR(tc, 1, TC) {
        getline(cin, A);

        cout << "Case " << tc << ": ";
        cout << strToPalinCost(A) << "\n";

    }
    return 0;
}
