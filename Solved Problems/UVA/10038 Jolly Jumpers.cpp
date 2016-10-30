#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

int main()
{
    int TC, tc;
    int N;
    int u, v;
    bool def[3001];

    while(cin >> N) {
        memset(def, false, sizeof(def));

        cin >> u;

        FOR(i, 2, N) {
            cin >> v;
            def[abs(u-v)] = true;
            u = v;
        }

        bool isPos = true;
        FOR(i, 1, N-1) {
            if(def[i] == false) {
                isPos = false;
                break;
            }
        }

        if(isPos) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }

    return 0;
}
