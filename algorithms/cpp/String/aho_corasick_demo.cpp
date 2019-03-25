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

#define ff first
#define ss second
#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 		1e-9
#define SQR(x) 		((x)*(x))
#define INF 		2000000000
#define TO_DEG 		57.29577951
#define PI 			2*acos(0.0)

#define ALL_BITS					((1 << 31) - 1)
#define NEG_BITS(mask)				(mask ^= ALL_BITS)
#define TEST_BIT(mask, i)			(mask & (1 << i))
#define ON_BIT(mask, i)				(mask |= (1 << i))
#define OFF_BIT(mask, i)			(mask &= NEG_BITS(1 << i))
#define IS_POWER_TWO(x)				(x && !(x & (x-1)))
#define OFF_RIGHTMOST_SET_BIT(x)	(x & (x-1))

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
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool> > VVB;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<PII> > VVPII;

ULL GCD(ULL a, ULL b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline int srcUInt() { uint ret; scanf("%u", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 100000
#define MAXS 500
#define MAXC 26

int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];

int buildMatchingMachine(vector<string> keys) {
    memset(out, 0, sizeof out);
    for (int i = 0; i < MAXS; ++i) memset(g[i], -1, sizeof g[i]);

    // Insert keys into regular trie
    int states = 1;
    for (int i = 0; i < keys.size(); ++i) {
        string key = keys[i];
        int curState = 0;
        for (int j = 0; j < key.length(); ++j) {
            int ch = key[j] - 'a';
            if (g[curState][ch] == -1) g[curState][ch] = states++;
            curState = g[curState][ch];
        }
        out[curState] |= (1 << i);
    }

    // Initialize values in fail function
    memset(f, -1, sizeof f);
    queue<int> q;

    for (int ch = 0; ch < MAXC; ++ch) {
        if (g[0][ch] != -1) {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        } else {
            g[0][ch] = 0;
        }
    }

    while (!q.empty()) {
        int state = q.front();
        for (int ch = 0; ch < MAXC; ++ch) {
            // Find failure state of removed state
            int failure = f[state];

            // Find the deepest node labeled by proper
            // suffix of string from root to current
            // state.
            while (g[failure][ch] == -1)
                failure = f[failure];

            failure = g[failure][ch];
            f[g[state][ch]] = failure;

            // Merge output values
            out[g[state][ch]] |= out[failure];

            // Insert the next level node (of Trie) in Queue
            q.push(g[state][ch]);
        }
    }

    return states;
}

int findNextState(int curState, char nextInput) {
    int answer = curState;
    int ch = nextInput - 'a';
    while (g[answer][ch] == -1)
        answer = f[answer];
    return g[answer][ch];
}

void searchWords(vector<string> keys, string text) {
    buildMatchingMachine(keys);
    int curState = 0;
    for (int i = 0; i < text.length(); ++i) {
        curState = findNextState(curState, text[i]);
        if (out[curState] == 0) continue;
        for (int j = 0; j < keys.size(); ++j) {
            if ((out[curState] & (1 << j)) != 0) {
                printf("Word %s appears from %d to %d\n", keys[j].c_str(), i - keys[j].length() + 1, i);
            }
        }
    }
}

int main()
{
    //READ("input.txt");
    //WRITE("input.txt");

    int i, j;
    int TC, tc;
    double cl = clock();

    vector<string> keys;
    keys.PB("he");
    keys.PB("she");
    keys.PB("his");
    keys.PB("hers");
    string text = "ashishers";

    searchWords(keys, text);

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
