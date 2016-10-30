#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

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
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

// Accepted UVA No: 11064
int NUM_OF_DIVISORS(int N)
{
    if(N == 1) return 1;
    int ret = 1;

    int root = (int)sqrt(N);
    for(int i=2; i<=root; i++)
        if(N % i == 0) {
            int power = 0;
            while(N % i == 0) {
                power++;
                N /= i;
            }
            ret *= (power+1);
        }
    if(N > 1) ret *= 2;

    return ret;
}

int divisor[1001];
int num[1001];

bool comp(int i, int j)
{
    if(divisor[i] == divisor[j])    return i > j;
    return divisor[i] < divisor[j];
}

int main()
{
 //   READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    int n;

   // cout << NUM_OF_DIVISORS(12);

    FOR(i, 1, 1000) {
        num[i] = i;
        divisor[i] = NUM_OF_DIVISORS(i);
    }
    sort(num+1, num+1+1000, comp);

    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> n;

        cout << "Case " << tc << ": ";
        cout << num[n] << "\n";
    }


    return 0;
}

