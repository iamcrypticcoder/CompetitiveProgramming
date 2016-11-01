/*
	Solved By : Kazi Mahbubur Rahman (cryptic.coder)
	Time :		2.090
	Rank :		782
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
#define INF 2000000000
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef vector<vector<bool>> VVB;
typedef vector<vector<int>> VVI;
typedef vector<vector<double>> VVD;
typedef vector<vector<PII>> VVPII;
typedef vector<vector<pair<int, string>>> VVPIS;

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
	int label, dist, firstChar;

	bool operator < (const NODE &b) const {
		return dist < b.dist;
	}
};

struct EDGE {
	int u, v;
	string word;
	EDGE() {};
	EDGE(int x, int y, string str) {
		u = x;
		v = y;
		word = str;
	}
};

int NODES, EDGES;
MSI nodeMap;
vector<EDGE> edges;
VVPIS G;
priority_queue<NODE> minQ;
VI dist;
VVB covers;
int source, sink;
int result;

void dijkstra() {
	NODE u, v;

	dist = VI(NODES, INF);
	covers = VVB(NODES, VB(26, false));

	dist[source] = 0;
	u.label = source;
	u.dist = 0;
	u.firstChar = 0;
	minQ.push(u);

	while (!minQ.empty()) {
		NODE u = minQ.top();	minQ.pop();

		FOR(i, 0, G[u.label].size() - 1) {
			pair<int, string> p = G[u.label][i];
			v.label = p.first;

			// If first char doesnt match
			if (u.firstChar != p.second[0]) {
				if (covers[v.label][p.second[0] - 'a'] == false) {
					v.dist = u.dist + p.second.length();
					dist[v.label] = min(dist[v.label], v.dist);
					v.firstChar = p.second[0];
					minQ.push(v);
					covers[v.label][p.second[0] - 'a'] = true;
				}
				else {
					if (u.dist + p.second.length() < dist[v.label]) {
						dist[v.label] = v.dist = u.dist + p.second.length();
						v.firstChar = p.second[0];
						minQ.push(v);
					}
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
	string str1, str2, str3;
	int nodeNum, u, v, c;

	while (scanf("%d", &EDGES)) {
		if (EDGES == 0) break;
		nodeNum = 0;

		cin >> str1 >> str2;
		if (nodeMap.find(str1) == nodeMap.end()) nodeMap[str1] = nodeNum++;
		if (nodeMap.find(str2) == nodeMap.end()) nodeMap[str2] = nodeNum++;
		source = nodeMap[str1];
		sink = nodeMap[str2];

		FOR(i, 1, EDGES) {
			cin >> str1 >> str2 >> str3;
			if (nodeMap.find(str1) == nodeMap.end()) nodeMap[str1] = nodeNum++;
			if (nodeMap.find(str2) == nodeMap.end()) nodeMap[str2] = nodeNum++;
			u = nodeMap[str1];
			v = nodeMap[str2];
			EDGE e = EDGE(u, v, str3);
			edges.PB(e);
		}

		NODES = nodeNum;
		G = VVPIS(NODES);

		FOR(i, 0, edges.size() - 1) {
			EDGE e = edges[i];
			G[e.u].PB(make_pair(e.v, e.word));
			G[e.v].PB(make_pair(e.u, e.word));
		}

		dijkstra();

		if (dist[sink] == INF) printf("impossivel\n");
		else printf("%d\n", dist[sink]);

		edges.clear();
		nodeMap.clear();
	}

	cl = clock() - cl;
	fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

	return 0;
}


/*
Critical Input:
4
a c
c b kh
b a ku
c b akarman
b a akua
0

Output:
6
*/