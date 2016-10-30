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
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

int NODES, EDGES;
MSI nodeMap;
int set[5001];
int C[5001];

void InitSet(int n)
{
    FOR(i, 0, n) set[i] = i;
}

int FindSet(int u)
{
    return set[u] == u ? u : (set[u] = FindSet(set[u]));
}

void Union(int u, int v)
{
    set[FindSet(u)] = FindSet(v);
}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    string str1, str2;
    int u, v;

    while(scanf("%d %d", &NODES, &EDGES) != EOF) {
        if(NODES == 0 && EDGES == 0) break;

        int nodeNum = 0;
        FOR(i, 1, NODES) {
            cin >> str1;
            if(nodeMap.find(str1) == nodeMap.end()) nodeMap[str1] = ++nodeNum;
        }

        InitSet(NODES);

        FOR(i, 1, EDGES) {
            cin >> str1 >> str2;
            u = nodeMap[str1];
            v = nodeMap[str2];

            if(FindSet(u) != FindSet(v)) Union(u, v);
        }

        memset(C, 0, sizeof(C));
        int ans = -1;
        FOR(i, 1, NODES) {
            u = FindSet(i);
            C[u]++;
            if(C[u] > ans) ans = C[u];
        }

        printf("%d\n", ans);
        nodeMap.clear();
    }

    return 0;
}

