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

LL GCD(LL a, LL b) { return b == 0 ? a : GCD(b,a%b); }

struct EDGE {
    int u, v, c;
};

int NODES;
int setA[101];
int setB[101];
vector<EDGE> edgesA;
vector<EDGE> edgesB;
int minSpanCost, maxSpanCost;

void InitSet()
{
    FOR(i, 0, NODES) {
        setA[i] = i;
        setB[i] = i;
    }
}

int FindSet(int u, char ch)
{
    if(ch == 'A')
        return setA[u] == u ? u : (setA[u] = FindSet(setA[u], 'A')); // Path compression
    else if(ch == 'B')
        return setB[u] == u ? u : (setB[u] = FindSet(setB[u], 'B'));
}
void Union(int u, int v, char ch)
{
    if(ch == 'A')
        setA[FindSet(u, 'A')] = FindSet(v, 'A');
    else if(ch == 'B')
        setB[FindSet(u, 'B')] = FindSet(v, 'B');
}

bool compAsc(EDGE a, EDGE b)
{
    return a.c < b.c;
}

bool compDesc(EDGE a, EDGE b)
{
    return a.c > b.c;
}

void Krushal_MinMaxST()
{
    sort(edgesA.begin(), edgesA.end(), compAsc);
    sort(edgesB.begin(), edgesB.end(), compDesc);

    int numSpanEdgesMinST = 0;
    int numSpanEdgesMaxST = 0;

    FOR(i, 0, edgesA.SZ-1) {
        if(numSpanEdgesMinST < NODES-1) {
            if(FindSet(edgesA[i].u, 'A') != FindSet(edgesA[i].v, 'A')) {
                numSpanEdgesMinST++;
                Union(edgesA[i].u, edgesA[i].v, 'A');
                minSpanCost += edgesA[i].c;
            }
        }
        if(numSpanEdgesMaxST < NODES-1) {
            if(FindSet(edgesB[i].u, 'B') != FindSet(edgesB[i].v, 'B')) {
                numSpanEdgesMaxST++;
                Union(edgesB[i].u, edgesB[i].v, 'B');
                maxSpanCost += edgesB[i].c;
            }
        }
    }
}

int main()
{
    READ("input.txt");
  //  WRITE("output.txt");

    int TC, tc;
    int n;

    scanf("%d", &TC);
    //cin >> TC;

    FOR(tc, 1, TC) {
        //cin >> n;
        scanf("%d", &n);
        NODES = n + 1;

        EDGE e;
        while(scanf("%d %d %d", &e.u, &e.v, &e.c)) {
            if(e.u == 0 && e.v == 0 && e.c == 0) break;
            edgesA.PB(e);
            edgesB.PB(e);
        }

        InitSet();
        minSpanCost = maxSpanCost = 0;
        Krushal_MinMaxST();

        //cout << "Case " << tc << ": ";
        printf("Case %d: ", tc);
        int total = minSpanCost + maxSpanCost;
        if(total % 2 == 0)
            printf("%d\n", total/2);
            //cout << total/2 << "\n";
        else {
            printf("%d/2\n", total);
            //cout << total << "/2\n";
        }

        edgesA.clear();
        edgesB.clear();
    }

    return 0;
}
