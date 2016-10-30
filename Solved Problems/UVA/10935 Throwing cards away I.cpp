/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.009
    Rank :      1810
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

//int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

int main()
{
    //READ("input.txt");
        WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N;
    list<int> l;

    while(scanf("%d", &N) != EOF) {
        if(N == 0) break;

        l.clear();
        FOR(i, 1, N) l.push_back(i);

        bool first = true;
        printf("Discarded cards:");


        while(l.size() > 1) {
            //printf("dfsf");

            int discard = l.front(); l.pop_front();
            int move = l.front(); l.pop_front();
            l.push_back(move);

            if(first) {
                printf(" %d", discard);
                first = false;
            }
            else printf(", %d", discard);

        }
        //cout << l.front();
        printf("\n");
        cout << "Remaining card: " << l.front() << endl;
        //printf("Remaining card: %d\n", (int)l.size());

    }

    return 0;
}

