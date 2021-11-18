/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      AC
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

typedef long long LL;
const int MAX_N = 1e5 + 1;
vector<bool> flag;
vector<int> result;

void sieveOptimized() {
    flag = vector<bool>(MAX_N + 7, false);
    flag[0] = flag[1] = true; // Not prime
    for (int i = 3; i*i <= MAX_N; i += 2) {
        if (false == flag[i]) {
            for (int j = i*i; j <= MAX_N; j += 2*i)
                flag[j] = true;
        }
    }
//    cout << "end of sieve" << endl;
}

bool isPrime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return (false == flag[n]);
}

void preCal() {
    result = vector<int>(MAX_N + 7);
    for (int i = 2; i <= MAX_N; i++)
        result[i] = isPrime(i) ? 1 : 2;
//    cout << "end of pre cal" << endl;
}

int main()
{
    //READ("input.txt");
    //WRITE("../output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    sieveOptimized();
    preCal();

    int n;
    while (cin >> n) {
        if (n == 1 || n == 2) cout << 1 << endl;
        else cout << 2 << endl;
        for (int i = 2; i <= n+1; i++)
            cout << result[i] << " ";
        cout << endl;
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
