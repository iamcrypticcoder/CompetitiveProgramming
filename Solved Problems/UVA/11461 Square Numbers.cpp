#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b;

    while(cin >> a >> b) {
        if(a == 0 && b == 0) break;

        a = (int)ceil(sqrt(a));
        b = (int)floor(sqrt(b));

        cout << b - a + 1 << "\n";
    }

    return 0;
}
