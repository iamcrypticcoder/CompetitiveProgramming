/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
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

#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^ ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask | (1 << i))
#define OFF_BIT(mask, i) (mask & NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_COM 8

int NODES;
vector<PII> pnts;
double dist[MAX_COM][MAX_COM];
double DP[MAX_COM][ (1 << MAX_COM)];
int next[MAX_COM][1 << MAX_COM ];
VI tourPnts;


double dist_2d(PII a, PII b)
{
    return sqrt(SQR(a.first - b.first) + SQR(a.second - b.second));
}

double TSP(int pos, int mask)
{
    if(DP[pos][mask] != -1.0) return DP[pos][mask];
    if(mask == (1 << NODES)-1) return DP[pos][mask] = 0.0;

    double ret = INF;
    FOR(i, 0, NODES-1)
        if( i != pos && TEST_BIT(mask, i) == 0) {
            double temp = dist[pos][i] + TSP(i, mask | (1 << i));
            if(temp < ret) {
                ret = temp;
                next[pos][mask] = i;
            }
        }

    return DP[pos][mask] = ret;
}

void trackSolution(int pos, int mask)
{
    if(pos == -1) return;
    tourPnts.PB(pos);
    int i = next[pos][mask];
    trackSolution(i, mask | (1 << i));
}

int main()
{
    READ("input.txt");
//    WRITE("output.txt");

    int TC, tc;

    tc = 1;
    while(scanf("%d", &NODES) != EOF) {
        if(NODES == 0) break;

        pnts = vector<PII>(NODES);

        FOR(i, 0, NODES-1) {
            scanf("%d %d", &pnts[i].first, &pnts[i].second);
        }

        memset(dist, 0, sizeof dist);
        FOR(i, 0, NODES-1) FOR(j, 0, NODES-1) {
            dist[i][j] = dist_2d(pnts[i], pnts[j]) + 16.0;
        }
        /*
        FOR(i, 0, NODES-1) {
            FOR(j, 0, NODES-1) printf("%lf\t", dist[i][j]);
            printf("\n");
        }
        printf("\n");
        */

        double ans = INF;
        int ansStart = -1;
        FOR(start, 0, NODES-1) {
            FOR(i, 0, NODES-1) FOR(j, 0, (1<<NODES)-1) DP[i][j] = -1.0;
            memset(next, -1, sizeof next);
            double temp = TSP(start, 1 << start);
            if(temp < ans) {
                ans = temp;
                ansStart = start;
            }
        }
        TSP(ansStart, 1 << ansStart);

        //printf("%.2lf\n", ans);

        printf("**********************************************************\n");
        printf("Network #%d\n", tc++);
        trackSolution(ansStart, 1 << ansStart);
        //FOR(i, 0, tourPnts.SZ-1) printf("%d ", tourPnts[i]);
        //printf("\n");

        FOR(i, 0, tourPnts.size()-2)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
                   pnts[tourPnts[i]].first, pnts[tourPnts[i]].second,
                   pnts[tourPnts[i+1]].first, pnts[tourPnts[i+1]].second,
                   dist[tourPnts[i]][tourPnts[i+1]]);

        printf("Number of feet of cable required is %.2lf.\n", ans);

        tourPnts.clear();
    }

    return 0;
}

