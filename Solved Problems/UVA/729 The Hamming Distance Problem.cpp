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

int N, H;

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;
    string out;

    cin >> TC;

    FOR(tc, 1, TC){
        if(tc > 1) cout << "\n";
        cin >> N >> H;

        out = "";
        FOR(i, 1, N-H)
            out += "0";
        FOR(i, 1, H)
            out += "1";

        cout << out << "\n";
        while(next_permutation(out.begin(), out.end())) {
            cout << out << "\n";
        }

    }


    return 0;
}

