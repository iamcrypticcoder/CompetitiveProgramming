#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)(L) ; i<=(int)(U) ; i++ )
#define FORD( i, U, L ) for(int i=(int)(U) ; i>=(int)(L) ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef pair<string, string> SS;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<SS> rule;

int main()
{
    READ("input.txt");
  //  WRITE("output.txt");
    int i, j, k, pos;
    int TC, tc;
    int N;
    string line1, line2, text;
    bool isMatch;

    while(cin >> N) {
        if(N == 0) break;
        getchar();

        FOR(i, 1, N) {
            getline(cin, line1);
            getline(cin, line2);
            rule.PB(SS(line1, line2));
        }

        getline(cin, text);

        FOR(i, 0, rule.SZ-1) {
            isMatch = true;

            while(isMatch) {
                isMatch = false;
                FOR(pos, 0, text.SZ - rule[i].first.SZ) {
                    if(text.substr(pos,rule[i].first.SZ) == rule[i].first) {
                        isMatch = true;
                        text.replace(pos, rule[i].first.SZ, rule[i].second);
                    }
                }
            }
        }

        cout << text << "\n";

        rule.clear();
    }

	return 0;
}
