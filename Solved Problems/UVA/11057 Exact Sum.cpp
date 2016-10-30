/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.039
    Rank :      322
    Complexity: For sorting (NlgN) + For each N binary search (NlgN) = 2 * N * lgN

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


int binarySearch(vector<int> items, int key)
{
    int low = 0, high = items.size() - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if(key < items[mid]) high = mid - 1;
        else if(key > items[mid]) low = mid + 1;
        else return mid;
    }
    return -1;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int temp;
    int N;
    VI prices;
    int money;

    while(scanf("%d", &N) != EOF) {
        FOR(i, 1, N) {
            scanf("%d", &temp);
            prices.PB(temp);
        }
        scanf("%d", &money);

        sort(prices.begin(), prices.end());

        int b1, b2, minDiff = INF;

        FOR(i, 0, prices.size()-1) {
            if(prices[i] < money) {
                if(binary_search(prices.begin(), prices.end(), money - prices[i])) {
                    int diff = abs(2*prices[i] - money);
                    if(diff < minDiff) {
                        b1 = prices[i];
                        b2 = money - prices[i];
                        minDiff = diff;
                    }
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", b1, b2);
        prices.clear();
    }
    return 0;
}

