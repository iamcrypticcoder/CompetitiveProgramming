#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int tc, TC;
    int N, K;
    char ch;

    cin >> TC;

    for(tc=1; tc<=TC; tc++) {
        cin >> N >> K;
        string str;
        for(char ch='A'; ch<=('A'+N-1); ch++)
            str += ch;
  //      cout << str;

        cout << "Case " << tc << ":\n";
        while(K--) {
            cout << str << "\n";
            if(next_permutation(str.begin(), str.end()) == false) break;
        }

    }

    return 0;
}
