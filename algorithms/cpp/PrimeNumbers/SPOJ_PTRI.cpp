/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      TLE
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
const int MAXN = 1e8;
vector<bool> flag(MAXN + 7, false);
vector<int> primes;
map<int, int> posMap;
vector<int> csum;

void sieveOptimized() {
    flag[1] = true;
    for (int i = 3; i * i <= MAXN; i += 2) {
        if (!flag[i]) {
            for (int j = i*i; j <= MAXN; j += 2*i)
                flag[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MAXN; i += 2)
        if (!flag[i]) primes.push_back(i);
}

bool isPrime(int n) {
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return !flag[n];
}

void preCal() {
    for (int i = 0; i < primes.size(); i++)
        posMap[primes[i]] = i+1;
    int i = 1, n = 1;
    while (n <= MAXN) {
        csum.push_back(n);
        i++;
        n += i;
    }
}

pair<int, int> solve(int n) {
    n = posMap[n];
    int pos = lower_bound(csum.begin(), csum.end(), n) - csum.begin();
    if (csum[pos] == n) {
        return {pos+1, pos+1};
    }
    return {pos+1, n - csum[pos-1]};
}

int main()
{
    READ("../input.txt");
    //WRITE("../output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    sieveOptimized();
    preCal();

    cin >> TC;
    int n;
    for (int tc = 1; tc <= TC; tc++) {
        cin >> n;
        if (!isPrime(n)) cout << "-1\n";
        else {
            auto p = solve(n);
            printf("%d %d\n", p.first, p.second);
        }
    }

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
