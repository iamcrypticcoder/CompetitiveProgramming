#include <iostream>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

int main()
{
    int N, temp;

    while(cin >> N) {
        if(N == 0) break;
        int XOR = 0;
        FOR(i, 1, N) {
            cin >> temp;
            XOR ^= temp;
        }

        if(XOR == 0)
            cout << "No\n";
        else cout << "Yes\n";


    }
    return 0;
}
