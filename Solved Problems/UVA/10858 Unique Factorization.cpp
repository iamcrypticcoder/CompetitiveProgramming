/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.015
    Rank :      85
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

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10001

stringstream ss;
vector<int> s;
int countFact;

void uniqueFact(int num, int start)
{
    int root = (int) sqrt(num);
    FOR(i, start, root) {
        if(num % i == 0) {
            s.push_back(i);
            uniqueFact(num / i, i);
        }
    }
    s.push_back(num);
    if(s.size() > 1) {
        ss << s[0];
        FOR(i, 1, s.size()-1) ss << " " << s[i];
        ss << endl;
        countFact++;
    }

    s.pop_back();
    s.pop_back();
}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N;

    while(scanf("%d", &N) != EOF) {
        if(N == 0) break;

        s.clear();
        countFact = 0;
        ss.str("");
        ss.clear();
        uniqueFact(N, 2);
        cout << countFact << endl;
        cout << ss.str();
    }

    return 0;
}

