/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 0.592
    Rank : 437
*/

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

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))


int sticks[20];
int M, avg;
bool isPos;

void solve(int mask, int sides, int sum, int startBit)
{
    int tSum, tMask;

    if(isPos) return;

    if(sum == avg) {
        if(sides + 1 == 4) { isPos = true; return; }
        solve(mask, sides+1, 0, 0);
    }

    FOR(i, startBit, M-1) {
        if(!TEST_BIT(mask, i) && sum+sticks[i] <= avg && !isPos) {
            int tMask = mask;
            ON_BIT(tMask, i);
            solve(tMask, sides, sum+sticks[i], i+1);
        }
    }
}


int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
/*
    int mask = 0;
    NEG_BITS(mask);

    FOR(i, 0, 30)
    {
        if(mask & (1 << i))
            cout << i << " " << "ON\n";
        else cout << i << " " << "OFF\n";
    }*/

    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        cin >> M;

        int sum = 0;
        FOR(i, 0, M-1)    {
            cin >> sticks[i];
            sum += sticks[i];
        }
        if(sum % 4 != 0) {
            cout << "no\n";
            continue;
        }
        avg = sum / 4;

        int mask = 0;
        isPos = false;
        solve(mask, 0, 0, 0);

        if(isPos) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

