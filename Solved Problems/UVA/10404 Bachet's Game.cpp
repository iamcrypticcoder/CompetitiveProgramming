
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;


#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

vector<bool> WIN;
int N, M;
vector<int> v;

void Calculate()
{
    WIN = vector<bool>(N+1, false);

    FOR(i, 0, N) {
        if(WIN[i] == false) {
            FOR(j, 0, v.size()-1)
                if(i + v[j] <= N)
                    WIN[i + v[j]] = true;
        }
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(cin >> N >> M) {
        v = vector<int>(M);

        FOR(i, 0, M-1) {
            cin >> v[i];
        }

        Calculate();

        if(WIN[N] == true)
            cout << "Stan wins\n";
        else cout << "Ollie wins\n";

        v.clear();
    }
    return 0;
}



