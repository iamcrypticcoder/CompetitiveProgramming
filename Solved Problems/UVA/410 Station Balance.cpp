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

int C, S;
VI specimen;

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    int TC, tc;

    tc = 1;
    while(cin >> C >> S) {

        specimen = VI(2 * C);

        int sum=0;
        FOR(i, 0, S-1) {
            cin >> specimen[i];
            sum += specimen[i];
        }
        double avg = double(sum) / C;

        sort(specimen.begin(), specimen.end());

        cout << "Set " << "#" << tc << "\n";

        double imbal = 0.0;
        FOR(i, 0, C-1) {
            imbal += fabs(specimen[i] + specimen[2*C-1 - i] - avg);

            cout << " " << i << ":";
            if(specimen[i] != 0) cout << " " << specimen[i];
            if(specimen[2*C-1 - i] != 0) cout << " " << specimen[2*C-1 - i];
            cout << "\n";
        }
        printf("IMBALANCE = %.5lf\n\n", imbal);

        specimen.clear();

        tc++;

    }

    return 0;
}

