#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>


using namespace std;

#define INF 99999999
#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

int N, M;
int temp;
VI seq;

int main()
{
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);

    int TC, tc = 1;

    while(cin >> N) {
        if(N == 0) break;

        FOR(i, 1, N) {
            int temp;
            cin >> temp;
            seq.push_back(temp);
        }

        cin >> M;

        cout << "Case " << tc++ << ":\n";
        FOR(i, 1, M) {
            int query;
            cin >> query;
            int minDiff = INF;
            int closestSum;

            FOR(j, 0, seq.size()-1) {
                FOR(k, j+1, seq.size()-1)
                    if(abs(seq[j] + seq[k] - query) < minDiff) {
                        minDiff = abs(seq[j] + seq[k] - query);
                        closestSum = seq[j] + seq[k];
                    }
            }

            cout << "Closest sum to " << query  << " is " << closestSum << ".\n";
        }
        seq.clear();
    }
}
