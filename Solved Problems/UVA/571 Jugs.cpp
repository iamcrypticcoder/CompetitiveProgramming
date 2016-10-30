
#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SZ size()
#define PB push_back
#define PF push_front

#define INF 99999999

#define fillA 0
#define fillB 1
#define emptyA 2
#define emptyB 3
#define pourAB 4
#define pourBA 5

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

typedef struct {
    int a, b;
}STATE;

int dist[1005][1005];
STATE parent[1005][1005];
int work[1005][1005];
queue<STATE> Q;
string s[] = {"fill A", "fill B",
                "empty A", "empty B",
                "pour A B", "pour B A" };


void PrintPath(int a, int b)
{
    if(dist[a][b] != 0) {
        PrintPath(parent[a][b].a, parent[a][b].b);
        cout << s[work[a][b]] << "\n";
    }
}

int main()
{
    int i, j, k;
    int TC, tc;

    STATE size, u, v;
    int x, N;

    while(cin >> size.a >> size.b >> N) {

        FOR(i, 0, 1002)
            FOR(j, 0, 1002)
                dist[i][j] = INF;

        u.a = u.b = 0;
        dist[u.a][u.a] = 0;
        Q.push(u);

        while( ! Q.empty()) {
            u = Q.front();      Q.pop();

            if(u.b == N || u.a == N) {
 //               cout << u.a << " " << u.b << endl;
                break;
            }

            x = dist[u.a][u.b] + 1;

            //filling A
            v.a = size.a;
            v.b = u.b;

            if( dist[v.a][v.b] > x ) {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                Q.push( v );
                work[v.a][v.b] = fillA;
            }

            // filling B
            v.a = u.a;
            v.b = size.b;

            if( dist[v.a][v.b] > x ) {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                Q.push( v );
                work[v.a][v.b] = fillB;
            }

            // empty A
            v.a = 0;
            v.b = u.b;

            if( dist[v.a][v.b] > x ) {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                Q.push( v );
                work[v.a][v.b] = emptyA;
            }

            // empty B
            v.a = u.a;
            v.b = 0;

            if( dist[v.a][v.b] > x ) {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                Q.push( v );
                work[v.a][v.b] = emptyB;
            }


            //pour A -> B
            if( u.a+u.b >= size.b ) {
                v.a = u.a - ( size.b - u.b );
                v.b = size.b;
            }
            else {
                v.b = u.b + u.a;
                v.a = 0;
            }

            if( dist[v.a][v.b] > x ) {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                Q.push( v );
                work[v.a][v.b] = pourAB;
            }

            // pour B -> A

            if( u.a+u.b >= size.a ) {
                v.b = u.b - ( size.a - u.a );
                v.a = size.a;
            }
            else {
                v.a = u.a + u.b;
                v.b = 0;
            }

            if( dist[v.a][v.b] > x ) {
                dist[v.a][v.b] = x;
                parent[v.a][v.b] = u;
                Q.push( v );
                work[v.a][v.b] = pourBA;
            }
        }
        PrintPath(u.a, u.b);
        cout << "success\n";
    }
	return 0;
}
