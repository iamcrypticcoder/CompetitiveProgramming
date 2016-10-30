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


int main()
{
 //   READ("input.txt");
 //   WRITE("output.txt");

    int TC, tc;
    double pTax;
    int income, temp;

    int amt[4] = { 180000, 300000, 400000, 300000 };
    double taxes[4] = { 0.0, 0.1, 0.15, 0.20 };

    cin >> TC;

    FOR( tc, 1, TC ) {

        cin >> income;

        cout << "Case " << tc << ": ";
        if( income <= 180000) {
            cout << "0\n";
            continue;
        }

        temp = income - 180000;
        pTax = 0.0;


        FOR(i, 1, 3) {
            if( temp <= amt[i] ) {
                pTax += (taxes[i] * temp);
            }
            else {
                pTax += ( taxes[i] * amt[i]);
            }
            temp -= amt[i];

            if(temp <= 0) break;
        }

        if( temp > 0) {
            pTax += (0.25 * temp);
        }

        if( pTax < 2000.0 ) pTax = 2000.0;

        cout << (int)ceil(pTax) << "\n";
    }


    return 0;
}
