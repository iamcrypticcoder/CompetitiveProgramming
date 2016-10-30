/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
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

int countDigit(int N)
{
    int ret = 0;
    while(N) {
        N = N / 10;
        ret++;
    }
    return ret;
}

int binarySearch(vector<LL> items, LL key)
{
    int low = 0, high = items.size() - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if(key < items[mid]) high = mid - 1;
        else if(key > items[mid]) low = mid + 1;
        else return mid;
    }
    return mid;
}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    LL N;
    vector<LL> groupDigits;             // Stores number of digits for S(1), S(2), S(3)...
    vector<LL> totalDigits;             // Stores total(sum) number of digits till S(1), S(2), S(3)....
    vector<LL> cntDigits;

    groupDigits.PB(0);
    totalDigits.PB(0);                  // For S(0) = 0
    for(i = 1; ;i++) {
        groupDigits.PB(groupDigits[i-1] + countDigit(i));
        totalDigits.PB(totalDigits[i-1] + groupDigits[i]);
        if(totalDigits[i] >= 2147483647) break;
    }
    cntDigits.PB(0);
    FOR(i, 1, totalDigits.size()) {
        cntDigits.PB(cntDigits[i-1] + countDigit(i));
    }
    //cout << cntDigits[cntDigits.size() - 1];
cout << cntDigits[2];

    scanf("%d", &TC);
    while(TC--) {
        scanf("%lld", &N);

        int index = binarySearch(totalDigits, N);

        if(totalDigits[index] == N) {
            printf("%d\n", index % 10);
        } else {
            N = N - totalDigits[index-1];
            int groupIndex = index;
        }

    }

    return 0;
}

