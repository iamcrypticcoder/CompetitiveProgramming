/*
        Problem Link : https://onlinejudge.org/external/106/10603.pdf
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : AC
        Time : 0.000
        Rank : 353
        Complexity:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <tuple>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS             1e-9
#define SQR(x)          ((x)*(x))
#define INF             2000000000
#define TO_DEG          57.29577951
#define PI              2*acos(0.0)

#define ALL_BITS                                ((1 << 31) - 1)
#define NEG_BITS(mask)                          (mask ^= ALL_BITS)
#define TEST_BIT(mask, i)                       (mask & (1 << i))
#define ON_BIT(mask, i)                         (mask |= (1 << i))
#define OFF_BIT(mask, i)                        (mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)                         (x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)                (x & (x-1))

typedef unsigned int uint;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<uint, uint> PUU;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<uint> VU;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<uint, uint> MUU;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

long long GCD(long long a, long long b) { while (b)b ^= a ^= b ^= a %= b;  return a; }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

// Input Methods
inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

const char WHITE = 0;
const char GRAY = 1;
const char BLACK = 2;

const int MAX = int(1e5);

struct State {
    int a, b, c, poured;
    State();
    State(int x, int y, int z, int w) : a(x), b(y), c(z), poured(w) {}
    bool operator < (const State& o) const {
        return poured > o.poured;
    }
    bool have(int x) {
        return a == x || b == x || c == x;
    }
    int closeTo(int x) {
        int ret = 0;
        if (a < x) ret = max(ret, a);
        if (b < x) ret = max(ret, b);
        if (c < x) ret = max(ret, c);
        return ret;
    }
};

int A, B, C, D;
map<tuple<int, int, int>, int> dist;

void relax(State v, priority_queue<State>& pq) {
    if (dist.find({v.a, v.b, v.c}) == dist.end() || v.poured < dist[{v.a, v.b, v.c}]) {
        dist[{v.a, v.b, v.c}] = v.poured;
        pq.push(v);
    }
}

pair<int, int> dijkstra() {
    State src = State(0, 0, C, 0);
    priority_queue<State> pq;
    pq.push(src);
    dist.clear();
    dist[{0, 0, C}] = 0;
    int dPrime = 0;
    int poured = 0;

    while (!pq.empty()) {
        State u = pq.top(); pq.pop();
        //printf("a = %d, b = %d, c = %d, poured = %d\n", u.a, u.b, u.c, u.poured);

        if (u.have(D)) {
            return {u.poured, D};
        } else if (u.closeTo(D) > dPrime) {
            dPrime = u.closeTo(D);
            poured = u.poured;
        }

        if (u.a) {
            // If B isn't full
            if (B - u.b > 0) {
                int x = min(B - u.b, u.a);
                State v = State(u.a - x, u.b + x, u.c, u.poured + x);
                relax(v, pq);
            }
            // If C isn't full
            if (C - u.c > 0) {
                int x = min(C - u.c, u.a);
                State v = State(u.a - x, u.b, u.c + x, u.poured + x);
                relax(v, pq);
            }
        }
        if (u.b) {
            // If A isn't full
            if (A - u.a > 0) {
                int x = min(A - u.a, u.b);
                State v = State(u.a + x, u.b - x, u.c, u.poured + x);
                relax(v, pq);
            }
            // If C isn't full
            if (C - u.c > 0) {
                int x = min(C - u.c, u.b);
                State v = State(u.a, u.b - x, u.c + x, u.poured + x);
                relax(v, pq);
            }
        }
        if (u.c) {
            // If A isn't full
            if (A - u.a > 0) {
                int x = min(A - u.a, u.c);
                State v = State(u.a + x, u.b, u.c - x, u.poured + x);
                relax(v, pq);
            }
            // If B isn't full
            if (B - u.b > 0) {
                int x = min(B - u.b, u.c);
                State v = State(u.a, u.b + x, u.c - x, u.poured + x);
                relax(v, pq);
            }
        }
    }
    return {poured, dPrime};
}

pair<int, int> solve() {
    return dijkstra();
}

int main() {
    READ("../input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    TC = srcUInt();
    for (tc = 1; tc <= TC; tc++) {
        scanf("%d %d %d %d", &A, &B, &C, &D);

        auto ans = solve();
        printf("%d %d\n", ans.first, ans.second);
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
