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
typedef pair<double, double> PDD;
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

int V, M;
int source, sink;
vector<PDD> holes;
VVI G;
VC color;
VI dist;

inline double distance(PDD x, PDD y) {
	return sqrt(SQR(x.first - y.first) + SQR(x.second - y.second));
}

void createGraph() {
	G = VVI(holes.size());
	FOR(i, 0, holes.size() - 1) FOR(j, i + 1, holes.size() - 1) {
		double dist = distance(holes[i], holes[j]);
		// If gopher can reach within time than create edge
		if (V * M * 60.0 > dist || fabs(V * M * 60.0 - dist) < EPS) {
			G[i].push_back(j);
			G[j].push_back(i);
		}
	}
}

void BFS() {
	color = VC(holes.size(), WHITE);
	dist = VI(holes.size(), INF);
	queue<int> Q;

	Q.push(source);
	color[source] = GRAY;
	dist[source] = 0;
	
	while (!Q.empty()) {
		int u = Q.front();		Q.pop();

		if (u == sink) break;

		FOR(i, 0, G[u].size() - 1) {
			int v = G[u][i];
			if (color[v] == WHITE) {
				Q.push(v);
				color[v] = GRAY;
				dist[v] = dist[u] + 1;
			}
		}
		color[u] = BLACK;
	}
}

int main()
{
	READ("input.txt");
	WRITE("output.txt");
	int i, j, k;
	int TC, tc;
	double cl = clock();

	string line;
	PDD hole;
	stringstream ss;

	while (cin >> V >> M) {
		if (V == 0 && M == 0) break;
		getline(cin, line);

		getline(cin, line);
		ss = stringstream(line);
		ss >> hole.first >> hole.second;
		holes.push_back(hole);
		source = 0;

		getline(cin, line);
		ss = stringstream(line);
		ss >> hole.first >> hole.second;
		holes.push_back(hole);
		sink = 1;

		while (getline(cin, line)) {
			if (line.size() == 0) break;
			stringstream ss(line);
			PDD hole;
			ss >> hole.first >> hole.second;
			holes.push_back(hole);
		}
		
		createGraph();
		BFS();

		if (dist[sink] == INF) printf("No.\n");
		else printf("Yes, visiting %d other holes.\n", dist[sink] == 0 ? 0 : dist[sink] - 1);

		holes.clear();
		G.clear();
		dist.clear();
		color.clear();
	}

	cl = clock() - cl;
	fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

	return 0;
}
