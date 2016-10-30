/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
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

typedef struct {
    int serial;
    int arrival;
    bool shiped;
    string bank;
} CAR;

int reachedTime[10001];

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    int N, T, M;
    int temp;
    string str;
    queue<CAR> leftQ, rightQ;
    int sTime;
    CAR c1, c2;

    scanf("%d", &TC);

    while(TC--) {
        scanf("%d %d %d", &N, &T, &M);

        bool isFirst = true;
        FOR(i, 1, M) {
            CAR c;
            cin >> c.arrival >> c.bank;
            c.shiped = false;
            c.serial = i;
            if(c.bank == "left") leftQ.push(c);
            else rightQ.push(c);
            if(isFirst) {
                sTime = c.arrival;
                isFirst = false;
            }
        }

        int curTime = sTime;
        string curBank = "left";
        while( !leftQ.empty() || !rightQ.empty()) {
            int carTaken = 0;
            if(curBank == "left") {
                while( !leftQ.empty() ) {
                    CAR c = leftQ.front();
                    if(c.arrival <= curTime && carTaken < N) {
                        reachedTime[c.serial] = curTime + T;
                        carTaken++;
                        leftQ.pop();
                    }
                    else break;
                }
            }
            else {
                while( !rightQ.empty() ) {
                    CAR c = rightQ.front();
                    if(c.arrival <= curTime && carTaken < N) {
                        reachedTime[c.serial] = curTime + T;
                        carTaken++;
                        rightQ.pop();
                    }
                    else break;
                }
            }

            // Crossing the river
            // If no car is taken then check which side has car with lowest arrival time
            //
            if(carTaken == 0) {
                int tmp1, tmp2;
                tmp1 = leftQ.empty() ? INF : leftQ.front().arrival;
                tmp2 = rightQ.empty() ? INF : rightQ.front().arrival;
                bool shouldCross = false;
                if((curBank == "left" && tmp2 < tmp1) || (curBank == "right" && tmp1 < tmp2)) shouldCross = true;
                if(shouldCross) {
                    curTime += T;
                    curBank = (curBank == "left") ? "right" : "left";
                } else {
                    curTime = min(tmp1, tmp2);
                }
            } else {
                curTime += T;
                curBank = (curBank == "left") ? "right" : "left";
            }
        }
        FOR(i, 1, M) {
            printf("%d\n", reachedTime[i]);
        }
        if(TC > 0) cout << endl;
    }

    return 0;
}

