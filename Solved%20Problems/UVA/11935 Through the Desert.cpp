/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
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

#define EPS 1e-6
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

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX 10000

vector<string> events;

bool isPossible(double capacity) {
    double fuelRemaining = capacity;
    double consumption = 0.0;
    int totalLeak = 0, prevPos = 0;

    int pos, cost;
    char s1[20], s2[20];

    FOR(i, 0, events.size()-1) {
        //cout << events[i] << endl;
        int x = sscanf(events[i].c_str(), "%d %s %s %d", &pos, &s1, &s2, &cost);

        int delta = pos - prevPos;
        if(delta > 0) {
            fuelRemaining = fuelRemaining - (consumption * delta);
            if(totalLeak > 0) fuelRemaining -= (delta * totalLeak);
        }
        if(fuelRemaining < 0.0) return false;

        if(strcmp(s1, "Fuel") == 0) {
            consumption = cost / 100.0;
        } else if(strcmp(s1, "Leak") == 0) {
            totalLeak++;
        } else if(strcmp(s1, "Gas") == 0) {
            fuelRemaining = capacity;
        } else if(strcmp(s1, "Mechanic") == 0) {
            totalLeak = 0;
        } else if(strcmp(s1, "Goal") == 0) {

        }

        prevPos = pos;
    }

    return true;
}

double bisection(double l, double r) {
    while(fabs(r-l) > EPS) {
        double m = (l+r) / 2;
        if(isPossible(m)) r = m;
        else l = m;
    }
    return l;
}

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;
    string tempStr;
    char s1[20], s2[20];
    int d, c; // Distance and Cost

    while(getline(cin, tempStr)) {
        if(tempStr == "0 Fuel consumption 0") break;
        events.PB(tempStr);
        while(getline(cin, tempStr)) {
            events.PB(tempStr);
            int x = sscanf(tempStr.c_str(), "%d %s %s %d", &d, &s1, &s2, &c);\
            if(strcmp(s1, "Goal") == 0) break;
        }
        //cout << events.size() << endl;

        printf("%.3lf\n", bisection(0.0, 10000.0));
        //isPossible(80.0);

        events.clear();
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
