/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.016
    Rank :      516
    Complexity: N * lg(1e9) where N = 1000 (max)
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

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

int N;                  // Number of vessels
int M;                  // Number of Containers;
int caps[1000001];      // Capacity of each vessels

// Checking using maximal capacity "cap" is it possible ?
bool isPossible(int cap)
{
    int contUsed = 0;               // Containers used must be less than M. right ?
    int contSize = 0;               // Container Size must be less than cap. right ?

    FOR(i, 1, N) {
        if(caps[i] > cap) return false;
        if(contSize + caps[i] > cap) {
            contSize = 0;
            contUsed++;
        }
        contSize += caps[i];
        if(i == N) contUsed++;
        if(contUsed > M) return false;
    }
    return true;
}

int BinarySearch()
{
    int high = 1000000000;          // 1000 * 1000000 = 1e9
    int low = 0;
    int mid;

    while(low < high) {
        mid = (low + high) / 2;
        if(isPossible(mid)) high = mid;
        else low = mid+1;
    }
    return high;
}

int BinarySearch2()
{
    int high = 1000000000;          // 1000 * 1000000 = 1e9
    int low = 0;
    int mid;

    while(low < high) {
        mid = (low + high) / 2;
        if(isPossible(mid)) high = mid;
        else low = mid+1;
    }
    if(isPossible(low) == false) return -1;
    return low;
}

int main()
{
    //READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    while(scanf("%d %d", &N, &M) != EOF) {
        FOR(i, 1, N) scanf("%d", &caps[i]);
        int ans = BinarySearch();
        printf("%d\n", ans);
    }
    return 0;
}

