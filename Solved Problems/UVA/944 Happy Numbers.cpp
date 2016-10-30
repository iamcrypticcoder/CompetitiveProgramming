/* No critical Input found.


*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>


using namespace std;

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef long long LL;

#define SQR(x) ((x)*(x))
#define FOR(i, L, U)		for(int i=L; i<=U; i++)

bitset<243+1> used;
bitset<99999+1> happy;
int happyCycle[99999 + 1];


void InitHappyNumber()
{
    FOR(i, 1, 243) {
        int num = i;
        int temp = 0;
        int iteration = 1;                          // Since the problem says iteration for 1 is 1.

        used.reset();

        while(num != 1) {
            if(used.test(num) == true || happy.test(num) == true) break;
            used.set(num, true);
            temp = 0;
            while(num) {
                temp += SQR(num % 10);
                num /= 10;
            }
            num = temp;
            iteration++;
        }

        if(num == 1) {
            happy.set(i, true);
            happyCycle[i] = iteration;
        }
        else if(happy.test(num) == true) {
            happy.set(i, true);
            happyCycle[i] = happyCycle[num] + iteration - 1;                    // Cause initial iteration value is 1.
        }

 //       cout << i << "\n";
    }

    FOR(i, 244, 99999) {
        int num = i;
        int temp = 0;
        int iteration = 0;

        while(num) {
            temp += SQR(num % 10);
            num /= 10;
        }

        happy.set(i, happy.test(temp));
        happyCycle[i] = happyCycle[temp] + 1;

 //        cout << i << "\n";
    }
}

int main()
{
    int L, H;

    InitHappyNumber();

    int TC = 1;

    while(cin >> L >> H) {
        if(TC >= 2) cout << "\n";
        FOR(i, L, H) {
            if(happy.test(i)) {
                cout << i << " " << happyCycle[i] << "\n";
            }
        }
        TC++;
    }

    return 0;
}

