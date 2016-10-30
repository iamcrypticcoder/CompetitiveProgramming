/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time : 0.003
    Rank : 53
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

int n, m;


int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    char cmd[100];
    int x;

    scanf("%d", &TC);

    FOR(tc, 1, TC) {
        scanf("%d %d", &n, &m);
        deque<int> Q;

        printf("Case %d:\n", tc);
        FOR(i, 1, m) {
            scanf("%s", cmd );

            if(strcmp(cmd, "pushLeft") == 0) {
                scanf("%d", &x);
                if(Q.size() == n) printf("The queue is full\n");
                else {
                    Q.push_front(x);
                    printf("Pushed in left: %d\n", x);
                }
            }
            else if(strcmp(cmd, "pushRight") == 0) {
                scanf("%d", &x);
                if(Q.size() == n) printf("The queue is full\n");
                else {
                    Q.push_back(x);
                    printf("Pushed in right: %d\n", x);
                }
            }
            else if(strcmp(cmd, "popLeft") == 0) {
                if(Q.empty()) printf("The queue is empty\n");
                else {
                    x = Q.front();  Q.pop_front();
                    printf("Popped from left: %d\n", x);
                }
            }
            else if(strcmp(cmd, "popRight") == 0) {
                if(Q.empty()) printf("The queue is empty\n");
                else {
                    x = Q.back();   Q.pop_back();
                    printf("Popped from right: %d\n", x);
                }
            }

        }
    }

    return 0;
}

