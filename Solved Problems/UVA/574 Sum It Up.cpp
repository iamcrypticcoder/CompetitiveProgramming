#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <string>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PB push_back
#define SZ size()

#define SQR(x) ((x)*(x))
#define INF 99999999

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int T, N;
VI v;
vector<bool> used;

int sum;
bool hasSolution;
VVI sol;
VI ele;

/*
Problem says all sums have to be distinct. That's why this function check new solution with all
previous solutions.
*/
bool isFound(VI v)
{
    FOR(i, 0, sol.SZ-1) {
        bool is = true;
        if(sol[i].SZ != v.SZ) continue;
        FOR(j, 0, sol[i].SZ-1)
            if(v[j] != sol[i][j]) {
                is = false;
                break;
            }
        if(is) return true;
    }
    return false;
}

void BackTrack(int s)
{
    if(sum == T) {
        hasSolution = true;
        if( ! isFound(ele)) {    // Check already got or not.
            cout << ele[0];
            FOR(i, 1, ele.SZ-1)
                cout << "+" << ele[i];
            cout << "\n";
            sol.PB(ele);
        }
        return;
    }

    FOR(i, s, N) {
        if(sum + v[i] <= T) {
            used[i] = true;
            sum += v[i];
            ele.PB(v[i]);
            BackTrack(i+1);
            ele.pop_back();
            sum -= v[i];
            used[i] = false;
        }
    }

}


int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;

    while(cin >> T >> N) {
        if(T == 0 && N == 0) break;

        v = VI(N+1);
        used = vector<bool>(N+1, false);

        FOR(i, 1, N)
            cin >> v[i];

        cout << "Sums of " << T << ":\n";

        sum = 0;
        hasSolution = false;
        BackTrack(1);

        if(hasSolution == false)
            cout << "NONE\n";

        ele.clear();
        sol.clear();

    }

    return 0;
}

