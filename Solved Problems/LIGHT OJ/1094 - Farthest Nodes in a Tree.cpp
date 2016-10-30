/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 0.147
    Rank : 5

*/
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

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODES, EDGES;
vector<vector<PI> > G;
int U, V;
int maxDist;

int DFS(int u, int parent)
{
    int ret = 0;
    int max1 = 0, max2 = 0;

    FOR(i, 0, G[u].SZ-1) {
        PI v = G[u][i];
        if(v.first != parent) {
            int d = v.second + DFS(v.first, u);
            if(d > max1) {
                max2 = max1; max1 = d;
            }
            else if(d > max2) max2 = d;
        }
    }
    if(max1 + max2 > maxDist) maxDist = max1 + max2;

    return max(max1, max2);
}



int main()
{
    READ("input.txt");
//    WRITE("output.txt");

    int TC, tc;
    int u, v, c;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d", &NODES);
        G = vector<vector<PI> >(NODES);

        FOR(i, 1, NODES-1) {
            scanf("%d %d %d", &u, &v, &c);
            G[u].PB(make_pair(v,c));
            G[v].PB(make_pair(u,c));
        }

        maxDist = -1;
        DFS(0, -1);

        printf("Case %d: %d\n", tc, maxDist);

    }

    return 0;
}
