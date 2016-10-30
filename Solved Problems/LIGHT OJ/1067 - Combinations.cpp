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

int fact[1000001];

void factorial()
{
    fact[0] = 1;
    FOR(i, 1, 1000000)
        fact[i] = ((LL)i * fact[i-1] ) % 1000003;
}

LL x, y;
// This function finds x and y such that gcd(a, b) = ax + by but it fails to find gcd
void ext_gcd(int a, int b)
{
    int g;
    if( b == 0) {
        x = 1; y = 0; g = a; return;
    }
    ext_gcd(b, a%b);
    int x1 = y;
    int y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}

// This function returns (a^b) mod m.
// Dont change LL to int. Otherwise it will return wrong ans
// It fastest enough.
// Used in 10006
LL BigMod (LL a, LL n, LL b)
{
    if (n == 1 ) return a % b;
    LL ans = BigMod(a,n / 2 ,b);
    ans = (ans * ans) % b;
    if (n % 2 == 1 ) return ans * a % b;
    return ans; return ans;
}


int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    int n, k;

    factorial();
    //cout << fact[10000];

    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> n >> k;

        LL nume = fact[n];
        LL deno = ( (LL)fact[k] * fact[n-k] ) % 1000003;
        // THEORY
        // ax = 1 (mod n) where x is called modular multiplicative inverse.
        // Remember if n is prime then x would be a^(n-2)
        // Thats why I used BigMod with mod 1000003
        // THEORY
        x = BigMod(deno, 1000003-2, 1000003);
        nume *= x;
        nume %= 1000003;

        cout << "Case " << tc << ": ";
        cout << nume << "\n";
    }

    return 0;
}

