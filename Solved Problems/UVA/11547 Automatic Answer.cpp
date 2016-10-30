#include <iostream>
#include <stdlib.h>

using namespace std;



int main()
{
    int TC,tc;
    int n, ans;

    cin >> TC;

    while(TC--) {
        cin >> n;
        ans = abs((n*63 + 7492)*5 - 498);
        ans = (ans%100)/10;
        cout << ans << endl;
    }

	return 0;
}
