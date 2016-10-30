#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define MAX 10000

int pi[MAX+1];
string store[MAX+1];
int map[MAX+1];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int TC, tc, i, n;
    string line;

    cin >> TC;
    getline(cin, line);

    while(TC--) {
        getline(cin, line);
        getline(cin, line);
        stringstream ss1(line);

        i = 0;
        while(ss1 >> pi[++i]) {
            map[pi[i]] = i;
        }
        n = i-1;

        getline(cin, line);
        stringstream ss2(line);

        i=0;
        while(ss2 >> store[++i]);

        for(i=1; i<=n; i++)
            cout << store[map[i]] << "\n";

        if(TC!=0) cout << "\n";

    }

    return 0;
}
