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


int pattern[10][4] = {
                        {0, 0, 0, 0},
                        {1, 1, 1, 1},
                        {2, 4, 8, 6},
                        {3, 9, 7, 1},
                        {4, 6, 4, 6},
                        {5, 5, 5, 5},
                        {6, 6, 6, 6},
                        {7, 9, 3, 1},
                        {8, 4, 2, 6},
                        {9, 1, 9, 1}
                    };

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    string m, n;
    int a, b;

    while(cin >> m >> n) {
        if(m == "0" && n == "0") break;
        if(n == "0") {
            cout << "1\n";
            continue;
        }

        a = m[m.size()-1] - '0';
        if(n.size() >= 2)
            b = atoi(n.substr(n.size()-2).c_str());
        else
            b = atoi(n.substr(n.size()-1).c_str());

        if(b % 4 == 0)
            cout << pattern[a][3] << "\n";
        else if(b % 4 == 1)
            cout << pattern[a][0] << "\n";
        else if(b % 4 == 2)
            cout << pattern[a][1] << "\n";
        else if(b % 4 == 3)
            cout << pattern[a][2] << "\n";

    }

	return 0;
}
