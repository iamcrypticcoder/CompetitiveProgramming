/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
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

#define EPS 1e-9
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

double E[100001];

bool isPrime(int N)
{
    if(N == 0 || N == 1) return false;

    int root = (int)sqrt(N);
    FOR(i, 2, root) {
        if(N % i == 0) return false;
    }

    return true;
}

void Expectation()
{
    E[1] = 0.0;

    FOR(i, 2, 100000) {
        if(isPrime(i)) E[i] = 2.0;
        else {
            int root = (int)sqrt(i);
            double sum = 0;
            double prob = 2;
            FOR(j, 2, root) {
                if(i % j == 0) {
                    sum += E[j]; prob++;
                    if(i/j != j) { sum += E[i/j]; prob++; }
                }
            }
            sum += prob;

            E[i] = sum / (prob - 1);
        }
    }
}

int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    int N;

    Expectation();

    scanf("%d", &TC);

	FOR(tc, 1, TC) {
        scanf("%d", &N);

        printf("Case %d: %.12lf\n", tc, E[N]);
	}

    return 0;
}

