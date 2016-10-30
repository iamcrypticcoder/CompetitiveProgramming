#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>
#include <queue>

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
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;


#define WHITE 0
#define GRAY 1
#define BLACK 2

int t[6];
int per[121][6];
VC signs;
bool isPos;

void GenPermutations()
{
    t[1] = 1; t[2] = 2; t[3] = 3; t[4] = 4; t[5] = 5;

    int i = 0;
    do {
        i++;
        FOR(j, 1, 5) per[i][j] = t[j];
    }while(next_permutation(t+1, t+1+5));
}

void BackTrack(int val, int permu, int i)
{
    if(i > 5) {
        if(val == 23) {
            isPos = true;
            return;
        }
        return;
    }

    BackTrack(val + t[per[permu][i]], permu, i+1);
    BackTrack(val - t[per[permu][i]], permu, i+1);
    BackTrack(val * t[per[permu][i]], permu, i+1);
}

int main()
{
    READ("input.txt");
 //   WRITE("output.txt");

    GenPermutations();

    int TC, tc;

    //scanf("%d", &TC);
    //cin >> TC;
    while(scanf("%d %d %d %d %d", &t[1], &t[2], &t[3], &t[4], &t[5]) != EOF) {
        if(t[1]+t[2]+t[3]+t[4]+t[5] == 0) break;

        isPos = false;
        FOR(permu, 1, 120) {
            BackTrack(t[per[permu][1]], permu, 2);
            if(isPos == true) break;
        }
        if(!isPos) printf("Impossible\n");
        else printf("Possible\n");
    }

    return 0;
}

