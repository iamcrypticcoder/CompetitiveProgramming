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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;

#define MAX 1000000

int sum[MAX];

int main()
{
    READ("input.txt");
    WRITE("output.txt");

    string line;
    int QUERY;
    int a, b, temp;

    int tc = 1;
    while(cin >> line) {
        if(line.size() == 0) break;

        sum[0] = (line[0] == '0' ? 0 : 1);

        FOR(i, 1, line.size()-1) {
            if(line[i] == '1')  sum[i] = sum[i-1] + 1;
            else sum[i] = sum[i-1];
        }

        cin >> QUERY;
        cout << "Case " << tc++ << ":\n";
        FOR(i, 1, QUERY) {
            cin >> a >> b;
            if( a > b ) swap(a, b);

            temp = sum[b] - sum[a];
            if(line[a] == '1') temp += 1;

            if(temp == 0 || temp == (b-a+1))
                cout << "Yes\n";
            else cout << "No\n";
        }


    }

	return 0;
}
