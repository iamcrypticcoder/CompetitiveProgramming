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

VI v;                   // This vector only stores upper bound.

int binarySearch(int key)
{
    int low, high, mid;

    low = 0; high = v.SZ-1;

    while(low <= high) {
        mid = (low+high) / 2;
        if(key < v[mid]) high = mid - 1;
        else if (key > v[mid]) low = mid +1;
        else return mid;
    }
    return high;
}

void Generate()
{
    int pos;

    v.PB(1);
    v.PB(2);

    for(int i = 2; v[v.SZ-1] < 2e9; i++) {
        pos = binarySearch(i) + 1;          // Add 1 since 0-indexed.
        v.PB(v[v.SZ-1] + pos);
    }
}

int main()
{
//    READ("input.txt");
//    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int in;

    Generate();
 /*
    FOR(i,0,21)
        cout << v[i] << " ";
    cout << v[v.SZ-1] << "\n";
    cout << v.SZ << "\n";
*/


    while(cin >> in && in) {
        int pos = binarySearch(in) + 1;
        cout << pos << "\n";
    }


	return 0;
}
