/*
        Problem Link :
        Solved By : Kazi Mahbubur Rahman (iamcrypticcoder)
        Status : [AC, WA, TLE, RTE]
        Time :
        Rank :
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
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <limits.h>
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

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = {  2,  1, -1, -2, -2, -1, 1, 2 };

inline int srcInt() { int ret; scanf("%d", &ret); return ret; }
inline uint srcUInt() { uint ret; scanf("%u", &ret); return ret; }
inline LL srcLongLong() { long long ret; scanf("%lld", &ret); return ret; }
inline ULL srcULongLong() { unsigned long long ret; scanf("%llu", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 1000001


bool isOp(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

LL applyOp(LL v1, LL v2, int op) {
    switch (op) {
        case '+': return v1 + v2;
        case '-': return v1 - v2;
        case '*': return v1 * v2;
        case '/': return v1 / v2;
    }
}

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

LL evaluate(string exp) {
    stack<LL> values;
    stack<char> ops;

    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] == ' ')
            continue;

        if (isdigit(exp[i])) {
            LL val = 0;
            while (i < exp.size() && isdigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            values.push(val);
            continue;
        }

        if (exp[i] == '(') {
            ops.push('(');
            continue;
        }

        if (exp[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int v2 = values.top();
                values.pop();
                int v1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(v1, v2, op));
            }
            ops.pop();
            continue;
        }

        if (isOp(exp[i])) {
            while (!ops.empty() && prec(ops.top()) >= prec(exp[i])) {
                int v2 = values.top();
                values.pop();
                int v1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(v1, v2, op));
            }
            ops.push(exp[i]);
            continue;
        }
    }
    while (!ops.empty()) {
        int v2 = values.top();
        values.pop();
        int v1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(v1, v2, op));
    }

    int ret = values.top();
    values.pop();
    return ret;
}


// https://www.geeksforgeeks.org/expression-evaluation/
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    uint TC, tc;
    double cl = clock();

    vector<string> expList;
    expList.push_back("10 + 2 * 6");
    expList.push_back("100 * 2 + 12");
    expList.push_back("100 * ( 2 + 12 )");
    expList.push_back("100 * ( 2 + 12 ) / 14");

    for (int tc = 0; tc < expList.size(); tc++) {
        cout << evaluate(expList[tc]) << endl;
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}