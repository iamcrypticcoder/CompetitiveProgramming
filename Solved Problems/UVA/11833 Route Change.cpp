/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
	Time :		0.000
	Rank :		25
	Complexity: Dijkstra
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
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a, int b) { while (b)b ^= a ^= b ^= a %= b;  return a; }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = { -1, 0, 1, 0, -1, 1,  1, -1 };
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1 };

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2 };

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_LEN 1000001

struct NODE {
	int label, dist;

	bool operator < (const NODE &b) const {
		return dist < b.dist;
	}
};
typedef vector<vector<PII> > VVP;

int NODES, EDGES;
VVP G;
VVI cost;
priority_queue<NODE> minQ;
VI dist;
int source, sink;
int C, K;

void dijkstra() {
	NODE u, v;
	PII p;

	dist = VI(NODES, INF);

	dist[source] = 0;
	u.label = source;
	u.dist = 0;
	minQ.push(u);

	while (!minQ.empty()) {
		u = minQ.top();	minQ.pop();

		// If current node is dest
		if (u.label == C - 1) continue;

		// If current node is in service route, go to only next node
		if (u.label < C) {
			v.label = u.label + 1;
			if (u.dist + cost[u.label][v.label] < dist[v.label]) {
				v.dist = dist[v.label] = u.dist + cost[u.label][v.label];
				minQ.push(v);
			}
		} else {
			FOR(i, 0, G[u.label].size() - 1) {
				PII p = G[u.label][i];
				v.label = p.first;
				if (u.dist + p.second < dist[v.label]) {
					v.dist = dist[v.label] = u.dist + p.second;
					minQ.push(v);
				}
			}
		}
	}

}

int main()
{
	READ("input.txt");
	//WRITE("output.txt");
	int i, j, k;
	int TC, tc;
	double cl = clock();
	int u, v, c;

	while (scanf("%d %d %d %d", &NODES, &EDGES, &C, &K) == 4) {
		if (!NODES && !EDGES && !C && !K) break;

		G = VVP(NODES);
		cost = VVI(NODES, VI(NODES, INF));
		source = K;
		sink = C - 1;

		FOR(i, 1, EDGES) {
			scanf("%d %d %d", &u, &v, &c);
			G[u].PB(make_pair(v, c));
			G[v].PB(make_pair(u, c));
			cost[u][v] = c;
			cost[v][u] = c;
		}

		dijkstra();

		printf("%d\n", dist[sink]);
	}

	cl = clock() - cl;
	fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

	return 0;
}
