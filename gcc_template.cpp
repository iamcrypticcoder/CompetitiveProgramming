// Problem Link :
// Solved By : iamcrypticcoder
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

int allBits()               { return ((1LL << 31) - 1);     }
int negBits(int n)          { return n ^ ((1LL << 31) - 1); }
bool checkBit(int n, int i) { return (n & (1LL << i));      }
int setBit(int n, int i)    { return (n | (1LL << i));      }
int clearBit(int n, int i)  { return (n & ~(1LL << i));     }
int flipBit(int n, int i)   { return (n ^ (1LL << i));      }
bool isPower2(int n)        { return (n && !(n & (n-1)));   }

long long GCD(long long a, long long b) { while (b)b ^= a ^= b ^= a %= b;  return a; }
long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

// Input Methods
inline int32_t srcInt32() { int ret; scanf("%d", &ret); return ret; }
inline uint32_t srcUInt32() { uint32_t ret; scanf("%u", &ret); return ret; }
inline int64_t srcInt64() { int64_t ret; scanf("%lld", &ret); return ret; }
inline uint64_t srcUInt64() { uint64_t ret; scanf("%llu", &ret); return ret; }

const char WHITE = 0;
const char GRAY = 1;
const char BLACK = 2;

const int INF       = int(1e9);
const double EPS    = double(1e-9);
const double TO_DEG = double(57.29577951);
const double PI     = 2*acos(0.0);
const int MAX_N     = int(1e5);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //READ("../input.txt");
    //WRITE("output.txt");
    int64_t TC, tc;
    double cl = clock();

    TC = srcInt64();
    for (tc = 1; tc <= TC; tc++) {
        // Start code for a test case
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
